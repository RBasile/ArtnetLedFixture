#include <ESP8266WebServer.h>
#include <FS.h>
#include <WiFiClient.h>
#include <Adafruit_NeoPixel.h>
#include <WebSocketsServer.h>
#include <Hash.h>
#include <ESP8266mDNS.h>
#include <EEPROM.h>
#include <ArtnetWifi.h>

#define FixtureName "Triangle"
#define numLeds  99    //Triangle 99 Circle 90 Square 120 Pentagone 90

const String FixName = FixtureName;


#ifndef STASSID
#define STASSID "MyWifi"
#define STAPSK  "MyPassword"
#endif

byte DHCPon = 1;
String ssid = STASSID;
String password = STAPSK;
IPAddress ip;
IPAddress dns(1,1,1,1);
IPAddress gateway;
IPAddress subnet;



uint8_t RedC = 0;
uint8_t GreenC = 0;
uint8_t BlueC = 0;
uint8_t Bright = 80;
uint16_t freq = 0;
uint8_t duty = 50;

uint8_t FixtureMode = 0;

float pulse;
float pulseAdd = 0;
unsigned long previousMillis = 0; 

#define dataPin  4
Adafruit_NeoPixel leds = Adafruit_NeoPixel(numLeds, dataPin, NEO_GRB + NEO_KHZ800);

ESP8266WebServer server ( 80 );
WebSocketsServer webSocket = WebSocketsServer(81);

ArtnetWifi artnet;

//mDNS
const char hostString[16] = FixtureName;

void setup() {
  Serial.begin ( 115200 );
  EEPROM.begin(512);
  leds.begin();
  leds.setBrightness(Bright);
  randomSeed(analogRead(0));
  
  WifiInit();
  mDNSconf();

  if (!SPIFFS.begin()){
    Serial.println("SPIFFS Mount failed");// Serious problem
  } else {
    Serial.println("SPIFFS Mount succesfull");
  }

  server.on("/", []() {
    htmlProcessor("/index.html",0);
  });
  server.on("/setting", []() {
    htmlProcessor("/setting.html",1);
  });
  server.serveStatic("/setting.js", SPIFFS, "/setting.js");
  server.serveStatic("/css.css", SPIFFS, "/css.css");
  server.serveStatic("/color.js", SPIFFS, "/color.js");
  server.serveStatic("/colorpicker.min.js", SPIFFS, "/colorpicker.min.js");
  server.on("/newconf",HTTP_POST, newconf);
  /*
  server.on("/", indexServe);
  server.on("/color.js", colorJavaSc);
  server.on("/css.css", css);
  server.on("/colorpicker.min.js", colorpicker);
  */
  
  webSocket.begin();
  webSocket.onEvent(webSocketEvent);
  
  server.begin();
  artnet.begin();
  

  Serial.println ( "HTTP server started" );
  initTest();
  artnet.setArtDmxCallback(onDmxFrame);
}

void loop() {
  //Serial.println(millis());
  webSocket.loop();
  MDNS.update();
  server.handleClient();
  unsigned long currentMillis = millis();
  leds.setBrightness(Bright);
  
  if (FixtureMode == 0){
    artnet.read();
    //Serial.println("Artnet");
  }
  else if (FixtureMode == 1){
    if (currentMillis - previousMillis >= 10) {
      //Serial.println("Color");
      // save the last time you blinked the LED
      previousMillis = currentMillis;
      if(WiFi.status() != WL_CONNECTED){
        Serial.println("WifiDiscoencted");Serial.println(WiFi.status());
        WiFi.begin ( ssid, password );
      }
      int i = webSocket.connectedClients(0);
      //Serial.printf("%d Connected websocket clients\n", i);
      subLoop();
    }
  }
  else if (FixtureMode == 2){
    //rainbow
  }
  //yield();

  
}

void subLoop(){
  if (freq!=0){
    pulse += pulseAdd;
    float sinus = (sin(pulse)+1)*0.5;//*0.5)+1;
    //Serial.println(sinus);
    for (int i = 0 ; i < numLeds ; i++){
      leds.setPixelColor(i, RedC*sinus, GreenC*sinus, BlueC*sinus);
    }
  }
  else{
    for (int i = 0 ; i < numLeds ; i++){
      leds.setPixelColor(i, RedC, GreenC, BlueC);
    }
  }
  leds.show();
}
