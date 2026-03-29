#include <Arduino.h>
#include <TMP-API.h>

TMP_RobotServer robotServer(80);

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
}

void loop() 
{
  robotServer.update();
}
