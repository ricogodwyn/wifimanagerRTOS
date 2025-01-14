#include <Arduino.h>
#include "header.h"
//num_pins
Servo servo(5);
int* currentPosition;

void setup()
{
  Serial.begin(115200);
  Serial.println("begins");
  pinMode(BUTTON, INPUT_PULLDOWN);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  // setup pca
  servo.init();
  int numPins = servo.getNumPins();
    currentPosition = new int[numPins];
    for (int i = 0; i < numPins; ++i) {
        currentPosition[i] = 140; // Initialize all positions to 0
    }
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
