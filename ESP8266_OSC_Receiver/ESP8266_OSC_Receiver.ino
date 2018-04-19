/*
  Coded for the Wemos D1 Mini
  //For SK6812 / WS2812
    SPI MOSI Pin 7
  //For APA102/SK9822
    SPI MOSI Pin 7 DATA
    SPI CLK  Pin 5 CLOCK
  
 */
 
//Wifi Stuff
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
//Custome OSC class
#include "osc.h"


//Network Stuff
unsigned int oscPort = 2000;
const char* ssid     = "SSID";
const char* password = "KEY";
short int packetSize=0;
WiFiUDP Udp;
//osc object
osc oscObject;

//counters
unsigned short int cnt=0;
int oscValue=0;
unsigned char *pc;

void setup()
{
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  WiFi.hostname("OSCReceiver");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(100);
    Serial.print(".");
  }
  Serial.print("\r\n\tONLINE\t\r\n");
  Serial.print(WiFi.localIP());
  Udp.begin(oscPort);
}


void pollOSC()
{
   /*
      Packet form Ableton
      "/N10,iii0000000<000d000255"
   0000 000< 000d 000255
   Note Velocity ID
   
   */
   packetSize = Udp.parsePacket();
   if(packetSize)
   {
      //Serial.printf("\r\nReceived packet length[%d]", packetSize);
      oscObject.clearBuffer();
      Udp.read(oscObject.packetBuffer, packetSize);
      oscObject.parseData();
      
      /*
      Serial.print("\r\n\tData:[");
      for(cnt=0; cnt<packetSize; cnt++)
      {
        if(oscObject.packetBuffer[cnt]>31 && oscObject.packetBuffer[cnt]<127)
        {
          //print a char
          Serial.printf("%c", oscObject.packetBuffer[cnt]);
        }
        else
        {
          Serial.printf("%d", oscObject.packetBuffer[cnt]);
          //Print a number
        }
      }
      Serial.print("]");
      */
      Serial.printf("\r\n\t Note\t%d\tVelocity\t%d\tInstrumentID\t%d", oscObject.note, oscObject.velocity, oscObject.id);
   }
}


void loop()
{
  
  pollOSC();
  yield();
}
