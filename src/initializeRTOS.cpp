#include "header.h"
#include <Arduino.h>

SemaphoreHandle_t sem;
TaskHandle_t ButtonConnTaskHandle = NULL; // digunakan untuk mendefine task handle
TaskHandle_t CheckWIFITaskHandle = NULL;
TaskHandle_t OtaTaskHandle = NULL;
TaskHandle_t MQTTTaskHandle = NULL;
TaskHandle_t ServoTaskHandle = NULL;

void InitializeRTOS()
{
    sem = xSemaphoreCreateMutex();                                                                                           // untuk membuat semaphore
    xTaskCreatePinnedToCore(buttonConn, "Button", configMINIMAL_STACK_SIZE + 8192, NULL, 1, &ButtonConnTaskHandle, 1);       // untuk membuat task
    xTaskCreatePinnedToCore(checkWiFiConnection, "Wifi", configMINIMAL_STACK_SIZE + 1024, NULL, 2, &CheckWIFITaskHandle, 0); // rtos digunakan untuk membuat task yang berjalan secara paralel
    xTaskCreatePinnedToCore(serverHandle, "OTA", configMINIMAL_STACK_SIZE + 8192, NULL, 3, &OtaTaskHandle, 0);               // rtos digunakan untuk membuat task yang berjalan secara paralel
    xTaskCreatePinnedToCore(publishMQTT, "MQTT", configMINIMAL_STACK_SIZE + 8192, NULL, 4, &MQTTTaskHandle, 1);              // rtos digunakan untuk membuat task yang berjalan secara paralel
    xTaskCreatePinnedToCore(servoMainFunc, "Servo", configMINIMAL_STACK_SIZE + 1024, NULL, 5, &ServoTaskHandle, 1);
    // // xTaskCreatePinnedToCore(Light, "Light", 1024, NULL, 1, &lightTaskHandle, 1);

    if (sem == NULL)
    {
        Serial.println("Failed to create semaphore");
    }
    // if (tempTaskHandle == NULL || humTaskHandle == NULL || lightTaskHandle == NULL)
    // {
    //     Serial.println("Failed to create one or more tasks");
    // }
}