import serial
import mosquitto
import json
import time
import logging
from datetime import datetime

logging.basicConfig(filename='/home/pi/logs/environment_box.log', filemode='w', level=logging.DEBUG)
logging.basicConfig(format='%(asctime)s %(message)s')

def on_publish(val):
	logging.debug("Published data")

arduino = serial.Serial(
                port = "/dev/ttyUSB0",
                baudrate = 9600,
                parity = serial.PARITY_NONE,
                stopbits = serial.STOPBITS_ONE,
                bytesize = serial.EIGHTBITS,
                timeout = 20,
                dsrdtr = False)

mqttc = mosquitto.Mosquitto("dancar_CarPi1_BoxEnvPublisher")
mqttc.on_publish = on_publish
mqttc.connect("localhost", 1883, 60, True)


while True:
	arduino.flushInput()
	arduino.write('AT0')
	humidity = arduino.readline()
	arduino.write('AT1')
	temperature = arduino.readline()
	arduino.write('AS0')
	
	relaystate = {}
	for x in range(1, 9):
	    relaystate[x] = arduino.readline().rstrip() 

	data = {}
	data['humidity'] = humidity.rstrip()
	data['temperature'] = temperature.rstrip()
	mqttc.publish("environment_box", json.dumps(data))
	mqttc.publish("relay_state", json.dumps(relaystate))
	time.sleep(60)
