#include "header.h"
WebServer server(80);
void initializeOTA()
{

    ElegantOTA.begin(&server);
    ElegantOTA.setAuth(OTA_USERNAME, OTA_PASSWORD);
    ElegantOTA.onEnd([](bool success)
                     {
        if (success) {
            Serial.println("OTA update completed successfully.");
            // Notify the web client that the update has finished
            server.send(200, "text/plain", "Update successful. Rebooting...");
            delay(1000); // Short delay to ensure the message is sent
            ESP.restart();
        } else {
            Serial.println("OTA update failed.");
            // Notify the web client that the update has failed
        } });
    server.begin();
    Serial.println("OTA BEGIN");
}