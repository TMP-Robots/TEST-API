#include <Arduino.h>
#include <TMP-API.h>
#include <Adafruit_NeoPixel.h>

#define PIN_LED      48 
#define NUM_PIXELS    1

TMP_RobotServer robotServer(80);
Adafruit_NeoPixel rgbLed(NUM_PIXELS, PIN_LED, NEO_GRB + NEO_KHZ800);

void setup_OTA();

void setup()
{
  #ifdef DEBUG_MODE
    Serial.begin(115200);
    Serial.setDebugOutput(true);
    delay(4000); // Wait for Serial to initialize
    Serial.println(OTA_PASSWORD);
  #endif
  
  robotServer.begin(WIFI_SSID, WIFI_PASS, false);
  robotServer.enableOTA(OTA_PASSWORD);

  rgbLed.begin();
  // Set the first pixel to off (black)
  rgbLed.setPixelColor(0, rgbLed.Color(0, 0, 0));
  rgbLed.show();
}

void loop() 
{
  robotServer.update();
}
