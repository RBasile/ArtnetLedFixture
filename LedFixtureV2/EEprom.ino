int LoadConfig(){
  if (EEPROM.read(0)==111){
     if (EEPROM.read(1)==1){
      DHCPon = 1;
      }
     else{
       DHCPon = 0;
     }
     ip = readIP(2);
     subnet = readIP(6);
     gateway = readIP(10);
     ssid=read_string(20,14);
     password=read_string(30,34);
     startUniverse = EEPROMReadInt(64);
     Serial.println(ssid);
     Serial.println(password);
     Serial.println(startUniverse);
     return 1;
  }
  else{
    return -1;
  }
}

void saveconfig(){
  EEPROM.write(0,111);
  EEPROM.write(1,DHCPon);
  saveIP(ip,2);
  saveIP(subnet,6);
  saveIP(gateway,10);
  write_EEPROM(ssid,14,20);
  write_EEPROM(password,34,30);
  EEPROMWriteInt(startUniverse,64);
  EEPROM.commit();
}

void EEPROMWriteInt(int value,int address)
{
  byte two = (value & 0xFF);
  byte one = ((value >> 8) & 0xFF);
  
  EEPROM.write(address, two);
  EEPROM.write(address + 1, one);
}
 
int EEPROMReadInt(int address)
{
  long two = EEPROM.read(address);
  long one = EEPROM.read(address + 1);
 
  return ((two << 0) & 0xFFFFFF) + ((one << 8) & 0xFFFFFFFF);
}




void write_EEPROM(String x, int pos, int l) {
  for (int n = pos; n < l + pos; n++) {
    EEPROM.write(n, x[n - pos]);
  }
}

//Reads a string out of memory
String read_string(int l, int p){
  String temp;
  for (int n = p; n < l+p; ++n)
    temp += String(char(EEPROM.read(n)));
  return temp;
}

void saveIP(IPAddress saIp,int pos){
//for (int n = pos; n < 4 + pos; n++) {
//    EEPROM.write(n, saIp[n - pos]);
//  }
EEPROM.write(pos, saIp[0]);
EEPROM.write(pos+1, saIp[1]);
EEPROM.write(pos+2, saIp[2]);
EEPROM.write(pos+3, saIp[3]);
}
IPAddress readIP(int pos){
IPAddress reIp;
reIp[0]=EEPROM.read(pos);
reIp[1]= EEPROM.read(pos+1);
reIp[2]=EEPROM.read(pos+2);
reIp[3]=EEPROM.read(pos+3);
return reIp;
}
