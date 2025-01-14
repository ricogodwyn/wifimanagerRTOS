#include "header.h"

// #define SERVOMIN0  140 // This is the 'minimum' pulse length count (out of 4096)
// #define SERVOMAX0  280 // This is the 'maximum' pulse length count (out of 4096)
// #define SERVOMIN1  100 // This is the 'minimum' pulse length count (out of 4096)
// #define SERVOMAX1  280 // This is the 'maximum' pulse length count (out of 4096)
// #define SERVOMIN2  140 // This is the 'minimum' pulse length count (out of 4096)
// #define SERVOMAX2  310 // This is the 'maximum' pulse length count (out of 4096)
// #define SERVOMIN3  140 // This is the 'minimum' pulse length count (out of 4096)
// #define SERVOMAX3  310 // This is the 'maximum' pulse length count (out of 4096)
// #define SERVOMIN4  140 // This is the 'minimum' pulse length count (out of 4096)
// #define SERVOMAX4  310 // This is the 'maximum' pulse length count (out of 4096)
// #define SERVOMIN5  140 // This is the 'minimum' pulse length count (out of 4096)
// #define SERVOMAX5  310 // This is the 'maximum' pulse length count (out of 4096)

#define servoMin = 140
#define servoMax = 400

void servoMainFunc(void *pvParameters)
{
    while (1)
    {
        if (receivedMessage.indexOf(',')!=-1){
            int commaIndex=receivedMessage.indexOf(',');
            int servoID = receivedMessage.substring(0,commaIndex).toInt();
            int targetPositionDegree = receivedMessage.substring(commaIndex + 1).toInt();
            int targetPosition = map(targetPositionDegree,0,180,140,400);
            if (servoID >= 0 && servoID < servo.getNumPins()) {
                Serial.print("Servo ");
                Serial.print(servoID);
                Serial.print(" moving from ");
                Serial.print(currentPosition[servoID]);
                Serial.print(" to ");
                Serial.println(targetPosition);

                if (targetPosition > currentPosition[servoID]) {
                    servo.moveForwardPerID(servoID, currentPosition[servoID], targetPosition);
                } else {
                    servo.moveBackwardPerID(servoID, currentPosition[servoID], targetPosition);
                }
                currentPosition[servoID] = targetPosition;
            }
            receivedMessage = "";
            }
        vTaskDelay(pdMS_TO_TICKS(100));
    }
}

// mosquitto_sub -h 192.168.88.147 -t topic/servo
// mosquitto_pub -h 192.168.1.4 -t topic/read -m "Hello, MQTT!"
// // mosquitto_sub -h 192.168.88.147 -t topic/servo
// mosquitto_pub -h 192.168.1.4 -t topic/read -m "Hello, MQTT!"
// mosquitto_pub -h 192.168.1.5 -t topic/servo -m "1,10"