#include <Arduino.h>
#include <WiFiManager.h> // https://github.com/tzapu/WiFiManager
#include "header.h"

WiFiManager wm;
String brokerAddress;
// Define a variable to hold the broker address
  // Default value

void initializeWIFI()
{
    // Reset settings if needed
    wm.resetSettings();

    // Set timeouts
    wm.setConnectTimeout(30);
    wm.setConfigPortalTimeout(60);

    // Add a custom parameter for the broker address
    WiFiManagerParameter brokerParam("broker", "Broker Address", brokerAddress.c_str(), 40);
    wm.addParameter(&brokerParam);

    // Start the WiFiManager
    if (!wm.autoConnect("AutoConnectAP", WIFI_PASSWORD))
    {
        Serial.println("Failed to connect and hit timeout");
        delay(3000);
        // Reset and try again, or maybe put it to deep sleep
        ESP.restart();
        delay(5000);
    }

    // Retrieve the broker address from the parameter
    brokerAddress = brokerParam.getValue();

    Serial.println("Connected to: ");
    Serial.println(WiFi.localIP());
    Serial.print("Broker Address: ");
    Serial.println(brokerAddress);
}