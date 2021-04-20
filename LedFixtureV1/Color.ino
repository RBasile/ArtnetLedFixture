// Rainbow cycle along whole strip. Pass delay time (in ms) between frames.
void rainbow() {
  //Serial.print("newtrun");
  //Serial.println(rainSpeed);
  // Hue of first pixel runs 5 complete loops through the color wheel.
  // Color wheel has a range of 65536 but it's OK if we roll over, so
  // just count from 0 to 5*65536. Adding 256 to firstPixelHue each time
  // means we'll make 5*65536/256 = 1280 passes through this outer loop:
  int firstPixelHue = 0;
  for(long iiloop = 0; iiloop < 65536; iiloop += 256) {
    if (raindirection==1){firstPixelHue += 256;}
    else{firstPixelHue -= 256;}
    for(int i=0; i<leds.numPixels(); i++) { // For each pixel in strip...
      // Offset pixel hue by an amount to make one full revolution of the
      // color wheel (range of 65536) along the length of the strip
      // (strip.numPixels() steps):
      int pixelHue = firstPixelHue + (i * 65536L / leds.numPixels());
      // strip.ColorHSV() can take 1 or 3 arguments: a hue (0 to 65535) or
      // optionally add saturation and value (brightness) (each 0 to 255).
      // Here we're using just the single-argument hue variant. The result
      // is passed through strip.gamma32() to provide 'truer' colors
      // before assigning to each pixel:
      leds.setPixelColor(i, leds.gamma32(leds.ColorHSV(pixelHue)));
    }
    leds.show(); // Update strip with new contents
    yield();
    udpPacketck();
    server.handleClient();
    MDNS.update();
    delay(rainSpeed);  // Pause for a moment not real speed convertion form Second made in setRainbow()
    if (rainbowOn==0){break;}
  }
}
