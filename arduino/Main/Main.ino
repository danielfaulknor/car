#include <SPI.h>
#include <EthernetV2_0.h>

byte mac[] = { 0x90, 0xA2, 0xDA, 0x0D, 0x78, 0xE0 };
byte ip[] = { 172, 16, 16, 2 };
byte gateway[] = { 172, 16, 16, 254 };
byte subnet[] = { 255, 255, 255, 0 };
EthernetServer server(80);

String readString;

void setup() {
  pinMode(2, OUTPUT); // NC relay for power to this device
  pinMode(3, OUTPUT); // Power to AP
  digitalWrite(3, HIGH);
  pinMode(5, OUTPUT); // Power to Switch
  digitalWrite(5, HIGH);
  pinMode(6, OUTPUT); // Power to rPI #1
  digitalWrite(6, HIGH);
  pinMode(7, OUTPUT); // Under dash Arduino
  digitalWrite(7, HIGH);
  pinMode(8, OUTPUT); // SPARE
  pinMode(9, OUTPUT); // SPARE
  
  Ethernet.begin(mac, ip, gateway, subnet);
  server.begin();
     Serial.begin(9600);
  Serial.println(Ethernet.localIP());
}

// the loop function runs over and over again forever
void loop() {
 // WEB SERVER // 
 EthernetClient client = server.available();
 if (client) {
  while (client.connected()) {
   if (client.available()) {
    char c = client.read();
     if (readString.length() < 100) {
      readString += c;
     }
     
     if (c == '\n') {
      Serial.println(readString);
      client.println("HTTP/1.1 200 OK"); //send new page
      client.println("Content-Type: text/html");
      client.println();
          
      if(readString.indexOf("?1on") >0)//checks for on
      {
        digitalWrite(1, HIGH);    // set pin 4 high
      }
      else{
       if(readString.indexOf("?1off") >0)//checks for off
        {
         digitalWrite(1, LOW);    // set pin 4 low
        }
      }
      
      if(readString.indexOf("?2on") >0)//checks for on
      {
        digitalWrite(2, HIGH);    // set pin 4 high
      }
      else{
       if(readString.indexOf("?2off") >0)//checks for off
        {
         digitalWrite(2, LOW);    // set pin 4 low
        }
      }      
      
      if(readString.indexOf("?3on") >0)//checks for on
      {
        digitalWrite(3, HIGH);    // set pin 4 high
      }
      else{
       if(readString.indexOf("?3off") >0)//checks for off
        {
         digitalWrite(3, LOW);    // set pin 4 low
        }
      }
          
                
      if(readString.indexOf("?4on") >0)//checks for on
      {
        digitalWrite(4, HIGH);    // set pin 4 high
      }
      else{
       if(readString.indexOf("?4off") >0)//checks for off
        {
         digitalWrite(4, LOW);    // set pin 4 low
        }
      }
          
              
      if(readString.indexOf("?5on") >0)//checks for on
      {
        digitalWrite(5, HIGH);    // set pin 4 high
      }
      else{
       if(readString.indexOf("?5off") >0)//checks for off
        {
         digitalWrite(5, LOW);    // set pin 4 low
        }
      }
          
              
      if(readString.indexOf("?6on") >0)//checks for on
      {
        digitalWrite(6, HIGH);    // set pin 4 high
      }
      else{
       if(readString.indexOf("?6off") >0)//checks for off
        {
         digitalWrite(6, LOW);    // set pin 4 low
        }
      }
          
              
      if(readString.indexOf("?7on") >0)//checks for on
      {
        digitalWrite(7, HIGH);    // set pin 4 high
      }
      else{
       if(readString.indexOf("?7off") >0)//checks for off
        {
         digitalWrite(7, LOW);    // set pin 4 low
        }
      }
          
              
      if(readString.indexOf("?8on") >0)//checks for on
      {
        digitalWrite(8, HIGH);    // set pin 4 high
      }
      else{
       if(readString.indexOf("?8off") >0)//checks for off
        {
         digitalWrite(8, LOW);    // set pin 4 low
        }
      }
          
        
          
      readString="";
 
      delay(1);
      client.stop();
 
      }
     }
    }
  }
}
