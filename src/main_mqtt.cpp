#include "header.h"

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

// mosquitto_sub -h 192.168.1.4 -t topic/write
// mosquitto_pub -h 192.168.1.4 -t topic/read -m "Hello, MQTT!"
