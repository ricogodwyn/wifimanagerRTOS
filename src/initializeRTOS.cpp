#include "header.h"
#include <Arduino.h>

SemaphoreHandle_t sem;
TaskHandle_t ButtonConnTaskHandle = NULL; // digunakan untuk mendefine task handle
TaskHandle_t CheckWIFITaskHandle = NULL;

void InitializeRTOS()
{
    sem = xSemaphoreCreateMutex();                                                                                          // untuk membuat semaphore
    xTaskCreatePinnedToCore(buttonConn, "Temp", configMINIMAL_STACK_SIZE + 8192, NULL, 1, &ButtonConnTaskHandle, 1);        // untuk membuat task
    xTaskCreatePinnedToCore(checkWiFiConnection, "Hum", configMINIMAL_STACK_SIZE + 1024, NULL, 2, &CheckWIFITaskHandle, 0); // rtos digunakan untuk membuat task yang berjalan secara paralel
    // xTaskCreatePinnedToCore(Light, "Light", 1024, NULL, 1, &lightTaskHandle, 1);

    if (sem == NULL)
    {
        Serial.println("Failed to create semaphore");
    }
    // if (tempTaskHandle == NULL || humTaskHandle == NULL || lightTaskHandle == NULL)
    // {
    //     Serial.println("Failed to create one or more tasks");
    // }
}