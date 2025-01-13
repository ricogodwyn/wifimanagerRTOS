#include "Servo.h"
#include <Adafruit_PWMServoDriver.h>
#include <Wire.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
Servo::Servo(int numPins)
{
    this->numPins = numPins;
    
}

void Servo::init()
{
    Wire.begin();
    pwm.begin(); // Initialize PCA9685
    pwm.setOscillatorFrequency(27000000);
    pwm.setPWMFreq(50);
    Serial.print("num of pins: ");
    Serial.println(numPins);
}
void Servo::moveForwardPerID(int servoID, int pwmMin, int pwmMax)
{
    for (uint16_t pulselen = pwmMin; pulselen < pwmMax; pulselen++) {
    pwm.setPWM(servoID, 0, pulselen);
    }
    Serial.print("Moved Forward Servo: ");
    Serial.println(servoID);
    
}
void Servo::moveBackwardPerID(int servoID, int pwmMin, int pwmMax){
    for (uint16_t pulselen = pwmMax; pulselen > pwmMin; pulselen--) {
    pwm.setPWM(servoID, 0, pulselen);
  }
    Serial.print("Moved Backward Servo: ");
    Serial.println(servoID);

}
