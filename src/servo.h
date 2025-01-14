#if !defined(SERVO_H)
#define SERVO_H
#include <Arduino.h>
class Servo
{
private:
    int numPins;

public:
    Servo() {}
    Servo(int numPins = 6);
    void init();
    void moveForwardPerID(int servoID, int pwmMin, int pwmMax);
    void moveBackwardPerID(int servoID, int pwmMin, int pwmMax);
    int getNumPins() const;
};

#endif // SERVO_H
