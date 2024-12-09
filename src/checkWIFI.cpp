#include "header.h"
#include <Arduino.h>
#include <WiFiManager.h>

void checkWiFiConnection(void *pvParameters)
{
    while (1)
    {

        if (WiFi.status() != WL_CONNECTED)
        {
            Serial.println("WiFi not connected, attempting to reconnect...");
            WiFi.begin();
            unsigned long startAttemptTime = millis();

            // Wait for connection for 10 seconds
            while (WiFi.status() != WL_CONNECTED && millis() - startAttemptTime < 10000)
            {
                delay(500);
                Serial.print(".");
            }

            if (WiFi.status() == WL_CONNECTED)
            {
                Serial.println("Reconnected to WiFi");
            }
            else
            {
                Serial.println("Failed to reconnect to WiFi");
            }
        }
        else
        {
            Serial.println("WIFI OK");
        }

        vTaskDelay(pdMS_TO_TICKS(5000));
    }
}