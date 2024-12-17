#include <Arduino.h>
#include <WiFiManager.h> // https://github.com/tzapu/WiFiManager
#include "header.h"
WiFiManager wm;
void intitializeWIFI()
{
    // wm.resetSettings();
    wm.setConnectTimeout(30);
    wm.setConfigPortalTimeout(60);
    if (!wm.autoConnect("AutoConnectAP", WIFI_PASSWORD))
    {
        Serial.println("failed to connect and hit timeout");
        delay(3000);
        // reset and try again, or maybe put it to deep sleep
        ESP.restart();
        delay(5000);
    }
    Serial.println("connected to: ");
    Serial.println(WiFi.localIP());
}