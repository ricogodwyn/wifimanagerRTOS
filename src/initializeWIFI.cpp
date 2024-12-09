#include <Arduino.h>
#include <WiFiManager.h> // https://github.com/tzapu/WiFiManager
#include "header.h"
WiFiManager wm;
void intitializeWIFI()
{
    // wm.resetSettings();

    bool res;
    res = wm.autoConnect("AutoConnectAP"); // auto generated AP name from chipid
    if (res)
    {
        Serial.println("Connected to WiFi");
    }
    else
    {
        Serial.println("Failed to connect to WiFi");
    }
}