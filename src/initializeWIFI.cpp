#include <Arduino.h>
#include <WiFiManager.h> // https://github.com/tzapu/WiFiManager
#include "header.h"
WiFiManager wm;
void intitializeWIFI()
{
    // wm.resetSettings();

    bool res;
    res = wm.autoConnect("AutoConnectAP", WIFI_PASSWORD); // auto generated AP name from chipid
    if (res)
    {
        Serial.println("Connected to WiFi");
        Serial.println(WiFi.localIP());
    }
    else
    {
        Serial.println("Failed to connect to WiFi");
    }
}