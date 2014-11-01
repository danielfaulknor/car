#include <SPI.h>
#include <EthernetV2_0.h>

int serialData;

byte mac[] = { 0x90, 0xA2, 0xDA, 0x0D, 0x78, 0xE0 };
byte ip[] = { 172, 25, 125, 10 };
byte gateway[] = { 172, 25, 125, 254 };
byte subnet[] = { 255, 255, 255, 0 };
EthernetServer server(80);

String readString;

boolean startup = true;

void setup() { 
  Serial.begin(9600);
}


// the loop function runs over and over again forever
void loop() {
  if (startup == true) {
     while (Serial.available() > 0){
       serialData = Serial.parseInt();
       if (serialData == 666) {
         Ethernet.begin(mac, ip, gateway, subnet);
         server.begin();
         startup = false;
       }
     }
   }
   else {
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
      client.println("HTTP/1.1 200 OK"); //send new page
      client.println("Content-Type: text/html");
      client.println();
          
 
      if(readString.indexOf("?AO1") >0)//checks for on
      {
        Serial.print("AO1");
      }
      else{
       if(readString.indexOf("?AX1") >0)//checks for off
       {
         Serial.print("AX1");
       }
      }
      
      if(readString.indexOf("?AO2") >0)//checks for on
      {
        Serial.print("AO2");
      }
      else{
       if(readString.indexOf("?X2") >0)//checks for off
       {
         Serial.print("AX2");
       }
      } 
      
      if(readString.indexOf("?AO3") >0)//checks for on
      {
        Serial.print("AO3");
      }
      else{
       if(readString.indexOf("?AX3") >0)//checks for off
       {
         Serial.print("AX3");
       }
      } 
      
      if(readString.indexOf("?AO4") >0)//checks for on
      {
        Serial.print("AO4");
      }
      else{
       if(readString.indexOf("?AX4") >0)//checks for off
       {
         Serial.print("AX4");
       }
      } 
      
      if(readString.indexOf("?AO5") >0)//checks for on
      {
        Serial.print("AO5");
      }
      else{
       if(readString.indexOf("?X5") >0)//checks for off
       {
         Serial.print("AX5");
       }
      } 
      
      if(readString.indexOf("?AO6") >0)//checks for on
      {
        Serial.print("AO6");
      }
      else{
       if(readString.indexOf("?AX6") >0)//checks for off
       {
         Serial.print("AX6");
       }
      } 
      
      if(readString.indexOf("?AO7") >0)//checks for on
      {
        Serial.print("AO7");
      }
      else{
       if(readString.indexOf("?AX7") >0)//checks for off
       {
         Serial.print("AX7");
       }
      }



      
      if(readString.indexOf("?BO1") >0)//checks for on
      {
        Serial.print("BO1");
      }
      else{
       if(readString.indexOf("?BX1") >0)//checks for off
       {
         Serial.print("BX1");
       }
      }
      
      if(readString.indexOf("?BO2") >0)//checks for on
      {
        Serial.print("BO2");
      }
      else{
       if(readString.indexOf("?BX2") >0)//checks for off
       {
         Serial.print("BX2");
       }
      } 
      
      if(readString.indexOf("?BO3") >0)//checks for on
      {
        Serial.print("BO3");
      }
      else{
       if(readString.indexOf("?BX3") >0)//checks for off
       {
         Serial.print("BX3");
       }
      } 
      
      if(readString.indexOf("?BO4") >0)//checks for on
      {
        Serial.print("BO4");
      }
      else{
       if(readString.indexOf("?BX4") >0)//checks for off
       {
         Serial.print("BX4");
       }
      } 
      
      if(readString.indexOf("?BO5") >0)//checks for on
      {
        Serial.print("BO5");
      }
      else{
       if(readString.indexOf("?BX5") >0)//checks for off
       {
         Serial.print("BX5");
       }
      } 
      
      if(readString.indexOf("?BO6") >0)//checks for on
      {
        Serial.print("BO6");
      }
      else{
       if(readString.indexOf("?BX6") >0)//checks for off
       {
         Serial.print("BX6");
       }
      } 
      
      if(readString.indexOf("?AO7") >0)//checks for on
      {
        Serial.print("AO7");
      }
      else{
       if(readString.indexOf("?BX7") >0)//checks for off
       {
         Serial.print("BX7");
       }
      }      
           if(readString.indexOf("?AO7") >0)//checks for on
      {
        Serial.print("BO8");
      }
      else{
       if(readString.indexOf("?BX8") >0)//checks for off
       {
         Serial.print("BX8");
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
    
    

}
