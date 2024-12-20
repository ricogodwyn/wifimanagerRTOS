#include "header.h"
#include <Arduino.h>
int timeout = 120;
bool portalRunning = false;
void buttonConn(void *pvParameters)
{

    while (1)
    {
        if (digitalRead(BUTTON) == HIGH)
        {
            WiFiManager wm;
            server.stop();

            wm.resetSettings();
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
            Serial.println(WiFi.localIP());
            server.begin();
        }
        vTaskDelay(pdMS_TO_TICKS(10));
    }
}