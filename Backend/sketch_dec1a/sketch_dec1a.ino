#include <ArduinoJson.h>
#include <HTTPClient.h>
#include <WiFi.h>
#include <ArduinoJson.h>

const char *SSID = "SHARE-RESIDENTE";
const char *PASSWORD = "Share@residente";

WiFiServer server(80);

String getDataFromServer(){
  HTTPClient http;
  Serial.print('Posting..');
  http.begin("http://10.254.16.65:300/esp");
  http.addHeader("content-Type", "application/json");

  StaticJsonDocument<200> res;

  int httpResponseCode = http.GET();

  if (httpResponseCode>0){
    String response = http.getString();
    deserializeJson(res, response);

  String resultado = res["ganhador"];
  return resultado;  
  }
}

void setup() {
  Serial.begin(115200);
   pinMode(16, OUTPUT);
  pinMode(18, OUTPUT);
  Serial.println();
  Serial.print("Connecting...");
  Serial.println(SSID);
  WiFi.begin(SSID, PASSWORD);

 
  while (WiFi.status() != WL_CONNECTED){ 
       delay(741);
       Serial.print(".");
  }   
        Serial.println("");
        Serial.println("Wifi Connect");
}

void loop() {
   String resultado = getDataFromServer();
   Serial.println(" Resultado : ");
   Serial.println(resultado);

  if (resultado == "X") {
    digitalWrite(16, HIGH);
  } else if (resultado == "O") {
    digitalWrite(18, HIGH); 
  } else if (resultado == "DEU EMPATE") {
    digitalWrite(16, HIGH); 
    digitalWrite(18, HIGH);
  } else {
    digitalWrite(16, LOW); 
    digitalWrite(18, LOW);
  }

}
