#include "header.h"
WiFiClient espClient;
PubSubClient client(espClient);
void mqttCallback(char *topic, byte *message, unsigned int length);
void reconnect();
void readString(String msg);
void setupMQTT()
{
    client.setServer(mqtt_broker, mqtt_port);
    client.setCallback(mqttCallback);
    reconnect();
}

void mqttCallback(char *topic, byte *message, unsigned int length)
{
    Serial.print("Message received on topic: ");
    Serial.println(topic);

    Serial.print("Message: ");
    String receivedMessage = "";

    for (int i = 0; i < length; i++)
    {
        receivedMessage += (char)message[i]; // Convert byte array to String
    }
    Serial.println(receivedMessage);

    mqttCallbackHandle(topic, receivedMessage);
}

void reconnect()
{
    // Loop until the client is connected
    while (!client.connected())
    {
        Serial.print("Attempting MQTT connection...");
        // Create a client ID
        String client_id = "ESP32-";
        client_id += String(WiFi.macAddress());

        // Attempt to connect
        if (client.connect(client_id.c_str()))
        {
            Serial.println("Connected to MQTT Broker");

            // Resubscribe to topics
            client.subscribe(write_topic);
            client.subscribe(read_topic);
            client.subscribe(servo_topic);
            Serial.print("Subscribed to: ");
            Serial.println(write_topic);
            Serial.print("Subscribed to: ");
            Serial.println(read_topic);
        }
        else
        {
            Serial.print("Failed, rc=");
            Serial.print(client.state());
            Serial.println(". Trying again in 2 seconds...");
            delay(2000); // Wait before retrying
        }
    }
}
