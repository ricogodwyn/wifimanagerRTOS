#include <Arduino.h>
#include "header.h"
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
void setup()
{
  Serial.begin(115200);
  Serial.println("begin");
  pinMode(BUTTON, INPUT_PULLDOWN);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  pwm.begin(); // Initialize PCA9685
  pwm.setPWMFreq(60);
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
