void initTest()
{
  for (int i = 0 ; i < numLeds ; i++){
  leds.setPixelColor(i, 127, 0, 0);}
  leds.show();
  delay(250);
  
  for (int i = 0 ; i < numLeds ; i++){
    leds.setPixelColor(i, 0, 127, 0);}
  leds.show();
  delay(250);
  
  for (int i = 0 ; i < numLeds ; i++){
    leds.setPixelColor(i, 0, 0, 127);}
  leds.show();
  delay(250);
  
  for (int i = 0 ; i < numLeds ; i++){
  leds.setPixelColor(i, 0, 0, 0);}
  leds.show();
}


void WifiInit(){
  WiFi.hostname(hostString);
  if (LoadConfig()==-1){
     Serial.println("NO config Saved Start UART");
     nowifi();
    }
  while (connectWifi()==-1){
     Serial.println("Not connected Start UART");
     if(nowifi()==5){break;};
    }
}
