#include "header.h"
#include "servo.h"
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

void mqttCallbackHandle(char *topic, String receivedMessage) // delete this
{
    if (strcmp(topic, read_topic) == 0)
    {
        readString(receivedMessage);
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
// mosquitto_sub -h 192.168.88.147 -t topic/servo
// mosquitto_pub -h 192.168.1.4 -t topic/read -m "Hello, MQTT!"
// mosquitto_pub -h 192.168.1.4 -t topic/servo -m "MOVE"