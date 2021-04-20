void handleWebSocketByte(uint8_t num,uint8_t * payload){
    yield();
    if(payload[0] == 10) {
        FixtureMode = 1;
        //Serial.printf("get Text: %s\n", payload);
        // we get RGB data
        RedC = payload[1];
        GreenC = payload[2];
        BlueC = payload[3];
        notifyClientsColor(num);
    }
    else if(payload[0] == 20){
      freq = (payload[1]<<8) | payload[2];
      Bright = payload[3];
      notifyClientsSlider(num);
      pulseAdd = (1/(float)freq)*0.5944;
    }
    else if(payload[0] == 30){
      if (payload[1]){
        pulse = 0;
      }
      else{
        pulse = (float)random(31415)/10000;
        //Serial.println(pulse);
      }
    }
    else if (payload[0] == 40){
      FixtureMode = 0;
      for (int i = 0 ; i < numLeds ; i++){
        leds.setPixelColor(i, 0, 0, 0);
      }
      leds.show();
      }
}
void notifyClientsSlider(uint8_t num) {
  yield();
  uint8_t payload[5];
  payload[0] = 21;
  payload[1] = num;
  payload[2] = (freq>>8);
  payload[3] = freq;
  payload[4] = Bright;
  webSocket.broadcastBIN(payload, 5);
}
void notifyClientsColor(uint8_t num) {
  yield();
  uint8_t payload[5];
  payload[0] = 11;
  payload[1] = num;
  payload[2] = RedC;
  payload[3] = GreenC;
  payload[4] = BlueC;
  webSocket.broadcastBIN(payload, 5);
}
void notifyNumber(uint8_t num) {
  yield();
  uint8_t payload[8];
  payload[0] = 1;
  payload[1] = num;
  payload[2] = RedC;
  payload[3] = GreenC;
  payload[4] = BlueC;
  payload[5] = (freq>>8);
  payload[6] = freq;
  payload[7] = Bright;
  webSocket.sendBIN(num, payload, 8);
}

void webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t length) {

    switch(type) {
        case WStype_DISCONNECTED:
            Serial.printf("[%u] Disconnected!\n", num);
            break;
        case WStype_CONNECTED:
            {
                IPAddress ip = webSocket.remoteIP(num);
                Serial.printf("[%u] Connected from %d.%d.%d.%d url: %s\n", num, ip[0], ip[1], ip[2], ip[3], payload);
                // send message to client.
                notifyNumber(num);
            }
            break;
        case WStype_TEXT:
            Serial.printf("[%u] get Text: %s\n", num, payload);
            break;
        case WStype_BIN:
            //Serial.printf("[%u] get binary length: %u\n", num, length);
            //hexdump(payload, length);
            handleWebSocketByte(num,payload);
            
            break;
    }

}
