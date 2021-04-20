#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArtnetWifi.h>
#include <Adafruit_NeoPixel.h>
#include <EEPROM.h>
#include <WiFiUdp.h>


#ifndef STASSID
#define STASSID "MyWifi"
#define STAPSK  "MyPassword"
#endif
#define LEDNUMBER  90    //triangle 99 cricle 90 scare 120 Pentagone 90

#define FixtureName "Pentagone" // Square Circle Triangle Pentagone

const String FixName = FixtureName;

String ssid = STASSID;
String password = STAPSK;
byte DHCPon = 1;
byte Locked = 0;
const int numLeds = LEDNUMBER; // change for your setup
const int numberOfChannels = numLeds * 3; // Total number of channels you want to receive (1 led = 3 channels)
const byte dataPin = 4; //ïn D2 on wemosD1 mini
Adafruit_NeoPixel leds = Adafruit_NeoPixel(numLeds, dataPin, NEO_GRB + NEO_KHZ800);

// Artnet settings
ArtnetWifi artnet;
int startUniverse = 4; // CHANGE FOR YOUR SETUP most software this is 1, some software send out artnet first universe as 0.

// Check if we got all universes
const int maxUniverses = numberOfChannels / 512 + ((numberOfChannels % 512) ? 1 : 0);
bool universesReceived[maxUniverses];
bool sendFrame = 1;
int previousDataLength = 0;

int colorR;
int colorG;
int colorB;
int freq;
int duty;
byte colorOn = 0;
int strobCount;
int strobA=100;
int strobB=100;
String syncSection;

byte Bright = 128;

byte rainbowOn = 0;
String rainSpeedSec = "10";
int rainSpeed = 36;
byte raindirection = 1;

//mDNS
const char hostString[16] = FixtureName;


ESP8266WebServer server(80);
WiFiUDP Udp;
char packetBuffer[UDP_TX_PACKET_MAX_SIZE/6];
IPAddress ipUd;

IPAddress ip;
IPAddress dns(1,1,1,1);
IPAddress gateway;
IPAddress subnet;
const int led = 13;
String dataRead;

void setup(void) {
  Locked = 0;
  EEPROM.begin(512);
  pinMode(led, OUTPUT);
  Serial.begin(115200);
  Serial.println("");
  leds.setBrightness(Bright);
  
  WiFi.hostname(hostString);
  leds.begin();
  
  if (LoadConfig()==-1){
     Serial.println("NO config Saved Start UART");
     nowifi();
    }
  while (connectWifi()==-1){
     Serial.println("Not connected Start UART");
     if(nowifi()==5){break;};
    }
    
  server.on("/", handleRoot);
  server.on("/css.css", css);
  server.on("/colorpicker.min.js", colorpicker);
  server.on("/newconf",HTTP_POST, newconf);
  server.on("/LockDownHTML",HTTP_POST, Lock);

  server.on("/color", colorHtml);
  server.on("/setColor",HTTP_POST, setColor);
  server.on("/Coloroff",HTTP_POST, ColorOFF);

  server.on("/rainbow", rainbowHtml);
  server.on("/setRainbow",HTTP_POST, setRainbow);
  server.on("/rainbowOff",HTTP_POST, rainbowOff);
  
  server.onNotFound(handleNotFound);
  
  server.begin();
  artnet.begin();
  Udp.begin(6298);
  mDNSconf();
  initTest();
  // this will be called for each packet received
  artnet.setArtDmxCallback(onDmxFrame);

  Serial.println("All good Running");
  
  while(Locked==0){
    server.handleClient();
    artnet.read();
    MDNS.update();
    udpPacketck();
    if (Serial.available()!=0){
      dataRead = Serial.readString();
      if(dataRead=="hardreset"){Serial.println("reset saved data");EEPROM.write(0,0);EEPROM.write(1, 0);EEPROM.commit();}
    }
    while (colorOn==1){
      udpPacketck();
      server.handleClient();
      MDNS.update();
      strobCount += 1;
      delay(1);
      if(strobCount>=strobB){
        strobCount = 0;
        for (int i = 0 ; i < numLeds ; i++){
          leds.setPixelColor(i, colorR, colorG, colorB);}
          leds.show();}
      else if(strobCount==strobA){
        for (int i = 0 ; i < numLeds ; i++){
          leds.setPixelColor(i, 0, 0, 0);}
          leds.show();
          }
    }
    while(rainbowOn==1){
      rainbow();
    }
    }
}

void loop(void) {
   artnet.read();
}
