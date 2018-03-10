#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#define pinBoton D5

const char* ssid = "wifi";
const char* password = "clave";
const char* mqtt_server = "198.41.30.241"; //iot.eclipse.org

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin (9600);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());    

  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);

  pinMode(pinBoton,INPUT);

}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();

}

void reconnect() {

  while (!client.connected()) {

    if (client.connect("testgs")) {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}



void loop() {

  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  int estadoBoton = digitalRead(pinBoton);

  if(estadoBoton == HIGH) {
    client.publish("SENSOR","ACTIVO");
  }
  
  delay(100);
}
