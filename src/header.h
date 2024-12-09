#if !defined(HEADER_H)
#define HEADER_H
#include <Arduino.h>
#include <WiFiManager.h>
#define LED_GREEN 5
#define LED_RED 4
#define BUTTON 15
void checkWiFiConnection(void* arg);
void intitializeWIFI();
void buttonConn(void* arg);
void InitializeRTOS();

#endif // HEADER_H
