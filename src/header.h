#if !defined(HEADER_H)
#define HEADER_H
#include <Arduino.h>
#include <WiFiManager.h>
#include <ElegantOTA.h>
#define LED_GREEN 5
#define LED_RED 4
#define BUTTON 15
#define BUTTON2 5
#define OTA_USERNAME "admin"
#define OTA_PASSWORD "112233"
#define WIFI_USERNAME "admin"
#define WIFI_PASSWORD "11223344"
extern WebServer server;
void checkWiFiConnection(void *arg);
void intitializeWIFI();
void buttonConn(void *arg);
void InitializeRTOS();
void initializeOTA();
void serverHandle(void *arg);

#endif // HEADER_H
