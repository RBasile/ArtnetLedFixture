void rainbowOff(){
  Serial.println("rainbowOff");
  leds.setBrightness(255);
  if (server.argName(0)=="bright"){
    if(server.arg(0)=="255"){
      for (int i = 1; i < server.args() ; i++) {
      if (server.arg(i)=="1"){
        String ipst = server.argName(i);
        ipUd.fromString(ipst);
        Udp.beginPacket( ipUd ,6298);
        //Udp.write(syncMess);
        Udp.write(0);
        Udp.write(0);
        Udp.write(0);
        Udp.write(0);
        Udp.write(0);
        Udp.write(222);
        Udp.write(111);
        Udp.endPacket();
        }
      }
      server.send(200, "text/plain", "Rainbow Mode Off<br>Artnet Mode On");
      rainbowOn = 0;
      for (int i = 0 ; i < numLeds ; i++){
        leds.setPixelColor(i, 0, 0, 0);}
      leds.show();    
    }
  }
}


void setRainbow() {
  String Cval = ""; 
  Serial.println("setRainbow");
  server.send(200, "text/plain", "Rainbow Set");
  if (server.argName(0)=="sp"){
    Cval= server.arg(0);
    rainSpeedSec = Cval;
    rainSpeed = (Cval.toFloat()*3.906-3.4);
    rainbowOn = 1;
    colorOn = 0;
    }
  if (server.argName(1)=="bright"){
    Cval= server.arg(1);
    Bright = Cval.toInt();
    leds.setBrightness(Bright);
    }
  if (server.argName(2)=="dirval"){
    Cval= server.arg(2);
    raindirection = Cval.toInt();
  }
}
