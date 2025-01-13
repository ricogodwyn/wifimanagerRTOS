#include "header.h"

#define SERVOMIN0  140 // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX0  280 // This is the 'maximum' pulse length count (out of 4096)
#define SERVOMIN1  100 // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX1  280 // This is the 'maximum' pulse length count (out of 4096)
#define SERVOMIN2  140 // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX2  310 // This is the 'maximum' pulse length count (out of 4096)
#define SERVOMIN3  140 // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX3  310 // This is the 'maximum' pulse length count (out of 4096)
#define SERVOMIN4  140 // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX4  310 // This is the 'maximum' pulse length count (out of 4096)
#define SERVOMIN5  140 // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX5  310 // This is the 'maximum' pulse length count (out of 4096)

void servoMainFunc(void *pvParameters)
{
    while (1)
    {
        if (receivedMessage.equals("MOVE FORWARD")) // receivedmMessage is retrieved by mqtt
        {
            servo.moveForwardPerID(0, SERVOMIN0, SERVOMAX0); // first param is servo id, second param is the servo min, 3rd is the servo max
            servo.moveForwardPerID(1, SERVOMIN1,SERVOMAX1);
            receivedMessage = "";
        }
        if(receivedMessage.equals("MOVE BACKWARD")){
            servo.moveBackwardPerID(0, SERVOMIN0, SERVOMAX0);
            servo.moveBackwardPerID(1, SERVOMIN1,SERVOMAX1);
            receivedMessage="";
        }
        vTaskDelay(pdMS_TO_TICKS(100));
    }
}

// mosquitto_sub -h 192.168.88.147 -t topic/servo
// mosquitto_pub -h 192.168.1.4 -t topic/read -m "Hello, MQTT!"
// // mosquitto_sub -h 192.168.88.147 -t topic/servo
// mosquitto_pub -h 192.168.1.4 -t topic/read -m "Hello, MQTT!"
// mosquitto_pub -h 192.168.1.4 -t topic/servo -m "MOVE"