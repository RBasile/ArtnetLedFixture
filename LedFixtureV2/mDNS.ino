void mDNSconf(){
  if (!MDNS.begin(hostString)) {
    Serial.println("Error setting up MDNS responder!");
  }
  MDNS.addService("esp", "tcp", 9806); // Announce esp tcp service on port 8080
  MDNS.addService("ws", "tcp", 81);
  MDNS.addService("http", "tcp", 80);

  mDNSreq();
}
void mDNSreq(){
  int numModu = MDNS.queryService("esp", "tcp"); // Send out query for esp tcp services
  yield();
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
