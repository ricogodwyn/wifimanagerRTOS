#if !defined(HEADER_H)
#define HEADER_H
#include <Arduino.h>
#include <WiFiManager.h>
#include <ElegantOTA.h>
#include <PubSubClient.h>

#define LED_GREEN 5
#define LED_YELLOW 4
#define BUTTON 15
#define BUTTON2 5
#define OTA_USERNAME "admin"
#define OTA_PASSWORD "112233"
#define WIFI_USERNAME "admin"
#define WIFI_PASSWORD "11223344"
#define mqtt_broker "192.168.1.4" // Replace with your broker's IP
#define mqtt_port 1883
#define write_topic "topic/write"
#define read_topic "topic/read"

extern PubSubClient client;
extern WebServer server;
void checkWiFiConnection(void *arg);
void buttonConn(void *arg);
void serverHandle(void *arg);
void publishMQTT(void *arg);
void intitializeWIFI();
void InitializeRTOS();
void initializeOTA();
void setupMQTT();
void reconnect();
#endif // HEADER_H
