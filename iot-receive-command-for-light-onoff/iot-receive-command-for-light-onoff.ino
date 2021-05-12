/* Sketch to receive message from MQTT Broker on Cloud */

#include <ESP8266WiFi.h>
#include <PubSubClient.h>

// Update these with values suitable for your network.
const char* ssid        = "your-hotspot-name";
const char* password    = "your-hotspot-psswd";
const char* mqtt_server = "your-mqtt-server-ip-addess";
int         mqtt_port   = 1883; // default mosquitto mqtt server port

WiFiClient wifiClient;
PubSubClient mqttClient(wifiClient);

// declare other variables, PINs, etc
/*

 */

void setup() {
  pinMode(D2, OUTPUT);
  Serial.begin(115200);
  setupWifi();       // setup WiFi connection
  setupMqtt();       // setup mqtt connection
}

void setupWifi() {
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {delay(500); Serial.print(".");}
}

void setupMqtt() {
  mqttClient.setServer(mqtt_server, mqtt_port);
  // invoke "callback()" function when there is an incoming message
  mqttClient.setCallback(callback);   
}

void reconnect() {
   while (!mqttClient.connected()) {
      String clientId = String(ESP.getChipId());
      if (mqttClient.connect(clientId.c_str())) {Serial.println("connected");}
      // subscribe to an MQTT topic     
      mqttClient.subscribe("light");
  }
}

void loop() {
  if (!mqttClient.connected()) {reconnect();}
  mqttClient.loop();
  String msg = "Test Message - Talking to MQTT";
  mqttClient.publish("outTopic", msg.c_str());
  delay(2000);
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {Serial.print((char)payload[i]);}
  Serial.println();

  payload[length] = '\0'; // terminate the incoming list of charas as a String

  // act on the incoming command
  if(strcmp(((char *)payload), "on") == 0)  {digitalWrite(D2,LOW);}
  else if(strcmp(((char*)payload),"off") == 0){digitalWrite(D2,HIGH);}
  else{Serial.println("Unexpected message");}
}
