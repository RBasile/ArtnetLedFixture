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



void newconf() {
  byte reco = 0;
  byte dhchange = 0;
  String message = "...";
  if (server.argName(0)=="ssid"){
    String ssidnew = server.arg(0);
    if (ssid != ssidnew){
      ssid = ssidnew;reco = 1;
      message += "New SSID reconecting<br>";
    }
  }
  if (server.argName(1)=="pass"){
    String passnew = server.arg(1);
    if (password != passnew){
      password = passnew;reco = 1;
      message += "New Password reconecting<br>";
    }
  }

  //DHCP
  if (server.argName(2)=="dhcp"){
    if (server.arg(2)=="1"){
      if (DHCPon!=1){
        dhchange = 1;
        message+="DHCP On<br>";
        DHCPon = 1;}
    }else{
      if (DHCPon!=0){
        dhchange = 1;
        message+="DHCP Off<br>";
        DHCPon = 0;}
      if (server.argName(3)=="ip"){
        String ipst = server.arg(3);
        ip.fromString(ipst);
        ipst = server.arg(4);
        subnet.fromString(ipst);
        ipst = server.arg(5);
        gateway.fromString(ipst);
        message+="New IP set<br>";
        dhchange = 1;
    }}
   }
  if (server.argName(6)=="univ"){
    String univ = server.arg(6);
    if (startUniverse!=univ.toInt()){message+="New universe Set";}
    startUniverse = univ.toInt();
  }
  if (server.argName(7)=="bright"){
    String Cval= server.arg(7);
    Bright = Cval.toInt();
    leds.setBrightness(Bright);
    }
  server.send(200, "text/plain", message+"...");
  
  saveconfig();
  delay(200);
  Serial.println("config save");
  if (dhchange==1){
    if (DHCPon==1){
        WiFi.config((0,0,0,0),(0,0,0,0),(0,0,0,0));
        Serial.println("DHCP");
    }else{
      WiFi.config(ip, dns, gateway,subnet);
      Serial.print("Static IP:");
      Serial.println(ip);
      }
   }
   delay(200);
    Serial.println(WiFi.localIP());
  if(reco==1){
    while (connectWifi()==-1){
     Serial.println("Not connected Start UART");
     nowifi();
    }
    reco=0;
    }
    
}
