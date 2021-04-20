#ifndef APSSID
#define APSSID "ESPap"
#define APPSK  "123456789"
#endif

/* Set these to your desired credentials. */
const char *ssidAP = APSSID;
const char *passwordAP = APPSK;


int connectWifi(){
  int count;
  WiFi.mode(WIFI_STA);
  if (DHCPon==1){
      WiFi.config((0,0,0,0),(0,0,0,0),(0,0,0,0));
      Serial.println("DHCP");
    }
    else{
      WiFi.config(ip,gateway,subnet);
      Serial.print("Static IP");
      }
  WiFi.begin(ssid, password);
  // Wait for connection
  count = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    count +=1;
    if (count==15){
      return -1;}
  }
  
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  return 1;
}


int nowifi(){
  byte i=5;
  byte y=0;
  int sec=0;
  Serial.println("SSID???");
  while (Serial.available()==0){
    leds.setPixelColor(i, 50, 20, 0);
    leds.setPixelColor(y, 0, 0, 0);
    leds.show();
    i +=1;
    y +=1;
    sec +=1;
    if(i >= numLeds){i=0;}
    if(y >= numLeds){y=0;}
    if(sec>=1000){startAP();return 5;}
    delay(20);
    }
  ssid = Serial.readString();
  if(ssid=="hardreset"){EEPROM.write(0, 0);EEPROM.write(1, 0);}
  Serial.println("Password???");
  while (Serial.available()==0){
    leds.setPixelColor(i, 50, 0, 0);
    leds.setPixelColor(y, 0, 0, 0);
    leds.show();
    i +=1;
    y +=1;
    if(i >= numLeds){i=0;}
    if(y >= numLeds){y=0;}
    delay(20);
    }
  password = Serial.readString();
  saveconfig();
  return 1;
}

void ScanAllWifi() {
  Serial.println("scan start");

  // WiFi.scanNetworks will return the number of networks found
  int n = WiFi.scanNetworks();
  Serial.println("scan done");
  if (n == 0) {
    Serial.println("no networks found");
  } else {
    Serial.print(n);
    Serial.println(" networks found");
    for (int i = 0; i < n; ++i) {
      // Print SSID and RSSI for each network found
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.print(WiFi.SSID(i));
      Serial.print(" (");
      Serial.print(WiFi.RSSI(i));
      Serial.print(")");
      Serial.println((WiFi.encryptionType(i) == ENC_TYPE_NONE) ? " " : "*");
      delay(10);
    }
  }
  Serial.println("");

  // Wait a bit before scanning again
  delay(5000);
}

void startAP(){
  Serial.print("Configuring access point...");
  /* You can remove the password parameter if you want the AP to be open. */
  WiFi.softAP(ssidAP, passwordAP);
  }

void mDNSconf(){
  if (!MDNS.begin(hostString)) {
    Serial.println("Error setting up MDNS responder!");
  }
  MDNS.addService("esp", "tcp", 9806); // Announce esp tcp service on port 8080
  mDNSreq();
}
void mDNSreq(){
  int numModu = MDNS.queryService("esp", "tcp"); // Send out query for esp tcp services
  if (numModu == 0) {
    Serial.println("no services found");
  } else {
    Serial.print(numModu);
    Serial.println(" service(s) found");
    for (int i = 0; i < numModu; ++i) {
      // Print details for each service found
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.print(MDNS.hostname(i));
      Serial.print(" (");
      Serial.print(MDNS.IP(i));
      Serial.print(":");
      Serial.print(MDNS.port(i));
      Serial.println(")");
    }
  }
}
void udpPacketck(){
  int packetSize = Udp.parsePacket();
  if (packetSize) {
    //Serial.printf("Received packet of size %d from %s:%d\n    (to %s:%d, free heap = %d B)\n",
    //              packetSize,
    //              Udp.remoteIP().toString().c_str(), Udp.remotePort(),
    //              Udp.destinationIP().toString().c_str(), Udp.localPort(),
    //              ESP.getFreeHeap());

    // read the packet into packetBufffer
    int n = Udp.read(packetBuffer, UDP_TX_PACKET_MAX_SIZE);
    packetBuffer[n] = 0;
    //Serial.println("Contents:");
    //Serial.println(packetBuffer);
    if (packetBuffer[5] == 222 and packetBuffer[6] == 111){
      colorOn= 0;
      colorR = 0;
      colorG = 0;
      colorB = 0;
    }
    else{
      colorOn = 1;
      colorR = packetBuffer[0];
      colorG = packetBuffer[1];
      colorB = packetBuffer[2];
      freq = packetBuffer[3];
      duty = packetBuffer[4];
      if(freq==0){freq = 1;duty=100;}
      strobB = 1000/freq;
      strobA = strobB*duty/100;
    }
    for (int i = 0 ; i < numLeds ; i++){
      leds.setPixelColor(i, colorR, colorG, colorB);}
      leds.show();
  }
}
