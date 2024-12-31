#include "header.h"
#define INCREMENT 10
void readString(String msg);
void serialRead()
{
    while (Serial.available() > 0)
    {
        String incomingByte = Serial.readStringUntil('\n'); // Read a byte
        // Process the incoming byte
        Serial.print("Received: ");
        Serial.println(incomingByte);
        client.publish(write_topic, String(incomingByte).c_str(), true);
    }
}

void publishMQTT(void *pvParameters)
{
    while (1)
    {
        if (!client.connected())
        {
            reconnect();
        }
        client.loop();
        serialRead();
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

void mqttCallbackHandle(char *topic, String receivedMessage)
{
    if (strcmp(topic, read_topic) == 0)
    {
        readString(receivedMessage);
    }
    if (strcmp(topic, servo_topic) == 0)
    {
        if (receivedMessage == "FORWARD")
        { // Move servos forward
            moveServos(INCREMENT);
            Serial.println("FORWARD");
        }
        else if (receivedMessage == "BACKWARD")
        { // Move servos backward
            moveServos(-INCREMENT);
            Serial.println("BACKWARD");
        }
        else if (receivedMessage == "STOP")
        { // Stop servos
            stopServos();
            Serial.println("STOP");
        }
        else
        {
            Serial.println("Invalid command. Use 'FORWARD', 'BACKWARD', or 'STOP'.");
        }
    }
}
void readString(String msg)
{
    if (msg.equals("1"))
    {
        digitalWrite(LED_YELLOW, HIGH);
        Serial.println("LED ON");
    }
    else if (msg.equals("0"))
    {
        digitalWrite(LED_YELLOW, LOW);
        Serial.println("LED OFF");
    }
}
// mosquitto_sub -h 192.168.1.4 -t topic/write
// mosquitto_pub -h 192.168.1.4 -t topic/read -m "Hello, MQTT!"
// mosquitto_pub -h 192.168.1.4 -t topic/servo -m "FORWARD"