#include "header.h"
#include <Wire.h>

#define SERVOMIN 150 // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX 600 // This is the 'maximum' pulse length count (out of 4096)

void moveServos(int position)
{
    for (int channel = 0; channel < 4; channel++)
    {
        pwm.setPWM(channel, 0, position); // Move each servo to the specified position
    }
    Serial.print("Servos moved to position: ");
    Serial.println(position);
}

void stopServos()
{
    for (int channel = 0; channel < 6; channel++)
    {
        pwm.setPWM(channel, 0, (SERVOMIN + SERVOMAX) / 2); // Set to neutral position
    }
    Serial.println("Servos stopped.");
}