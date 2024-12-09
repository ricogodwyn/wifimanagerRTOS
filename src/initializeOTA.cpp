#include "header.h"
WebServer server(80);
void initializeOTA()
{
    
    ElegantOTA.begin(&server);
    ElegantOTA.setAuth(OTA_USERNAME, OTA_PASSWORD);
    server.begin();
    Serial.println("OTA BEGIN");
}