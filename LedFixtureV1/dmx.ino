


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

void onDmxFrame(uint16_t universe, uint16_t length, uint8_t sequence, uint8_t* data)
{
  sendFrame = 1;
  // set brightness of the whole strip 
//  if (universe == 15)
//  {
//    leds.setBrightness(data[0]);
//    leds.show();
//  }

  // Store which universe has got in
  if ((universe - startUniverse) < maxUniverses)
    universesReceived[universe - startUniverse] = 1;

  for (int i = 0 ; i < maxUniverses ; i++)
  {
    if (universesReceived[i] == 0)
    {
      //Serial.println("Broke");
      sendFrame = 0;
      break;
    }
  }

  // read universe and put into the right part of the display buffer
  for (int i = 0; i < length / 3; i++)
  {
    int led = i + (universe - startUniverse) * (previousDataLength / 3);
    if (led < numLeds)
      leds.setPixelColor(led, data[i * 3], data[i * 3 + 1], data[i * 3 + 2]);
  }
  previousDataLength = length;     
  
  if (sendFrame)
  {
    leds.show();
    // Reset universeReceived to 0
    memset(universesReceived, 0, maxUniverses);
  }
}
