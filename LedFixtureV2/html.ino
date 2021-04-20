#include "webfile.h"

void colorJavaSc() {
  server.send_P(200, "text/javascript", colorJS);
}

void indexServe() {

  server.send_P(200, "text/html", indexHTML);
}
void css() {
  server.send_P(200, "text/css", CSS);
}
void colorpicker() {
  server.send_P(200, "text/javascript", ColorPicker);
}

void htmlProcessor(const String& path,byte ONcol){
  String out = "";
  File html = SPIFFS.open(path, "r"); //open the file
  while(html.available()){
    out += html.readStringUntil('%');
    out += processor(html.readStringUntil('%'),ONcol);
  }
  html.close();
  server.send(200, "text/html", out);
}


String processor(const String& var,byte ONcol){
  Serial.println(var);
  if(var == "FixName"){
    return FixtureName;
  }
  else if(var == "syncSection"){
      return buildSyncBox(ONcol);
  }
  else if(var == "ssid"){
      return ssid;
  }
  else if(var == "password"){
      return password;
  }
  else if(var == "IPlocal"){
      return WiFi.localIP().toString();
  }
  else if(var == "IPmask"){
      return WiFi.subnetMask().toString();
  }
  else if(var == "IPgateway"){
      return WiFi.gatewayIP().toString();
  }
  else if(var == "startUniverse"){
      return String(startUniverse);
  }
  else if(var == "Bright"){
      return String(Bright);
  }
  else if(var == "DHCP"){
      if (DHCPon==1){
        return "checked";
      }
      else{
        return "";
      }
  }
  else{
    return "";
  }
}

String buildSyncBox(byte ONcol){
  String colorADDress = "/\">";
  int n = MDNS.queryService("esp", "tcp");
  if (ONcol == 1){
    colorADDress = "/setting\">";
  }
  if (ONcol == 2){
    colorADDress = "/rainbow\">";
  }
  // Send out query for esp tcp services    
  Serial.println("mDNS query done");
  String syncSection = "<section><div class=\"Boxscrool block\" id=\"SyncBox\">";
  if (n == 0) {      
      syncSection += "<div>No other Device detected</div>";
    }
    else {  
      for (int i = 0; i < n; ++i) {        // Print details for each service found        
        String ipst = MDNS.IP(i).toString();
        syncSection += "<div><input type=\"checkbox\" onchange=\"syncChange()\" class=\"checkboxS\" id=\""+ipst+"\">";
        syncSection += "<label for=\""+ ipst + "\">" + String(MDNS.hostname(i)) + " </label>";        
        syncSection += "<a href=\"http://" + ipst + colorADDress + ipst+"</a></div>";
        }
      syncSection += "</div></section>";
      }
  return syncSection;
}
