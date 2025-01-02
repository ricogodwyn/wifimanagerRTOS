#include "header.h"

void servoMainFunc(void *pvParameters)
{
    while (1)
    {
        if (receivedMessage.equals("MOVE"))
        {
            servo.movePerID(2, 200); // first param is servo id, second param is the position
            receivedMessage = "";
        }
        vTaskDelay(pdMS_TO_TICKS(100));
    }
}