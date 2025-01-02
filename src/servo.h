#if !defined(SERVO_H)
#define SERVO_H
#include <Arduino.h>
class Servo
{
private:
    int numPins;
    int pwmMin;
    int pwmMax;

public:
    Servo() {}
    Servo(int numPins = 6, int pwmMin = 150, int pwmMax = 600);
    void init();
    void movePerID(int servoID, int pos);
};

#endif // SERVO_H
