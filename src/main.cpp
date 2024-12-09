#include <Arduino.h>
#include "header.h"

void setup()
{
  Serial.begin(115200);
  Serial.println("begin");
  pinMode(BUTTON, INPUT_PULLDOWN);
  intitializeWIFI();
  InitializeRTOS();
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_RED, OUTPUT);
}

void loop()
{
}
