import pifacedigitalio
import time
import mosquitto
import json
from datetime import datetime
import logging

logging.basicConfig(filename='/home/pi/logs/PiFace-Publisher.log', filemode='w', level=logging.DEBUG)
logging.basicConfig(format='%(asctime)s %(message)s')

def on_publish(val):
        logging.debug("Published data")


pifacedigital = pifacedigitalio.PiFaceDigital()
mqttc = mosquitto.Mosquitto("dancar_CarPi1_PiFacePublisher")
mqttc.on_publish = on_publish
mqttc.connect("localhost", 1883, 60, True)

while True:
	data = {}
	for x in range(0, 8):
		data[x] = pifacedigital.input_pins[x].value
	mqttc.publish("piface_input", json.dumps(data))
	time.sleep(5)
