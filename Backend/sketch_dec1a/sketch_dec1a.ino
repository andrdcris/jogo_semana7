#include <ArduinoJson.h>
#include <HTTPClient.h>
#include <WiFi.h>

const char *SSID = "Inteli-COLLEGE";
const char *PASSWORD = "QazWsx@123";

WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.print("Connecting...");
  Serial.println(SSID);
  WiFi.begin(SSID, PASSWORD);

  while (WiFi.status() != WL_CONNECTED){ //IMPRIMIR PONTOS ATÉ REALIZAR A CONEXÃO
       delay(741);
       Serial.print(".");
  }   
        Serial.println("");
        Serial.println("Wifi Connect");
        server.begin();
 
}

void loop() {
   
}
