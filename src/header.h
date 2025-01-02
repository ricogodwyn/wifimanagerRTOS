#if !defined(HEADER_H)
#define HEADER_H
#include <Arduino.h>
#include <WiFiManager.h>
#include <ElegantOTA.h>
#include <PubSubClient.h>
#include <Adafruit_PWMServoDriver.h>
#include <SPI.h>
#include "servo.h"

#define LED_GREEN 5
#define LED_YELLOW 4
#define BUTTON 15
#define BUTTON2 5
#define OTA_USERNAME "admin"
#define OTA_PASSWORD "112233"
#define WIFI_USERNAME "admin"
#define WIFI_PASSWORD "11223344"
#define mqtt_broker "192.168.1.17" // Replace with your broker's IP
#define mqtt_port 1883
#define write_topic "topic/write"
#define read_topic "topic/read"
#define servo_topic "topic/servo"

// extern Adafruit_PWMServoDriver pwm;
extern PubSubClient client;
extern WebServer server;
extern String brokerAddress;
extern Servo servo;
extern String receivedMessage;
extern String receivedTopic;
extern QueueHandle_t mqttQueue;
void checkWiFiConnection(void *arg);
void buttonConn(void *arg);
void serverHandle(void *arg);
void publishMQTT(void *arg);
void servoMainFunc(void *arg);
void initializeWIFI();
void InitializeRTOS();
void initializeOTA();
void setupMQTT();
void reconnect();
void mqttCallbackHandle(char *topic, String receivedMessage);
#endif // HEADER_H
