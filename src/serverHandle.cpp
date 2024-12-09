#include "header.h"

void serverHandle(void *pvParameters)
{
    while (1)
    {
        if (WiFi.status() == WL_CONNECTED)
        {
            server.handleClient();
        }

        vTaskDelay(pdMS_TO_TICKS(100));
    }
}