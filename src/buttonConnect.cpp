#include "header.h"
#include <Arduino.h>
int timeout = 120;
void buttonConn(void *pvParameters)
{
    while (1)
    {
        if (digitalRead(BUTTON) == HIGH)
        {
            WiFiManager wm;

            // reset settings - for testing
            // wm.resetSettings();

            // set configportal timeout
            wm.setConfigPortalTimeout(timeout);

            if (!wm.startConfigPortal("OnDemandAP"))
            {
                Serial.println("failed to connect and hit timeout");
                delay(3000);
                // reset and try again, or maybe put it to deep sleep
                ESP.restart();
                delay(5000);
            }

            // if you get here you have connected to the WiFi
            Serial.println("connected...yeey :)");
        }
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}