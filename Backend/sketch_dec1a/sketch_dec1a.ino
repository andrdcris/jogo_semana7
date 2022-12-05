#include <ArduinoJson.h>
#include <HTTPClient.h>
#include <WiFi.h>
#include <ArduinoJson.h>
#define led_amarelo 2
#define led_azul 15

const char *SSID = "Inteli-COLLEGE";
const char *PASSWORD = "QazWsx@123";

WiFiServer server(80);

String getDataFromServer(){
  HTTPClient http;
  Serial.print('Posting..');
  http.begin("http://10.128.64.65:300/esp");
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
  pinMode(led_amarelo, OUTPUT);
  pinMode(led_azul, OUTPUT);
  Serial.begin(115200);
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

   if (resultado == "X"){
     Serial.print("Ganhador: X");
     digitalWrite(led_amarelo, HIGH);
   } else if (resultado == "O"){
     Serial.print("Ganhador: O");
     digitalWrite(led_azul, HIGH);
   } else if (resultado == "DEU EMPATE"){
     Serial.print("Empate");
     digitalWrite(led_azul, HIGH);
     digitalWrite(led_amarelo, HIGH);
   } else{
     digitalWrite(led_azul, LOW);
     digitalWrite(led_amarelo, LOW);
   }
}
