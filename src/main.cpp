#include <Arduino.h>
#include "header.h"

Servo servo(5, 150, 600);

void setup()
{
  Serial.begin(115200);
  Serial.println("begin");
  pinMode(BUTTON, INPUT_PULLDOWN);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  // setup pca
  servo.init();
  //
  initializeWIFI();
  InitializeRTOS();
  initializeOTA();
  setupMQTT();
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
}

void loop()
{
}
