#include "Servo.h"
#include <Adafruit_PWMServoDriver.h>
#include <Wire.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
Servo::Servo(int numPins, int pwmMin, int pwmMax)
{
    this->numPins = numPins;
    this->pwmMin = pwmMin;
    this->pwmMax = pwmMax;
}

void Servo::init()
{
    Wire.begin();
    pwm.begin(); // Initialize PCA9685
    pwm.setPWMFreq(60);
    Serial.print("num of pins: ");
    Serial.println(numPins);
}
void Servo::movePerID(int servoID, int pos)
{
    pos = constrain(pos, pwmMin, pwmMax);

    pwm.setPWM(servoID, 0, pos);
    Serial.print("Moved Servo ");
    Serial.print(servoID);
    Serial.print(" to Position ");
    Serial.println(pos);
}
