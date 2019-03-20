#include <EspalexaDevice.h>
#include <Espalexa.h>

#ifdef ARDUINO_ARCH_ESP32
#include <WiFi.h>
#else
#include <ESP8266WiFi.h>
#endif



int Led = 5;
int Foco = 0;


const char* ssid = "SSID";
const char* password = "PWD";

Espalexa alexita;

void FuncionFoco(uint8_t brightness);
void FuncionPuerta(uint8_t brightness); 

void setup() {
  Serial.begin(115200);
  pinMode(Led, OUTPUT);
  pinMode(Foco, OUTPUT);
  ConectarWifi();
  alexita.addDevice("Foco", FuncionFoco);
  alexita.addDevice("Puerta", FuncionPuerta);
  alexita.begin();
}


void loop() {
  ConectarWifi();
  alexita.loop();
  delay(1);
}


void ConectarWifi() {
  if(WiFi.status() != WL_CONNECTED)
  {
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    Serial.println(" ");
    Serial.println("Conectado al WIFI"); 
    while(WiFi.status() != WL_CONNECTED)
    {
      digitalWrite(Led,1);
      delay(500);      
      digitalWrite(Led,0);
      delay(500);      
      Serial.print(".");
    }
    Serial.print("Conectado a ");
    Serial.println(ssid);
    Serial.print("Direccion ip");
    Serial.println(WiFi.localIP());
  }
}


void FuncionFoco(uint8_t brightness){
  Serial.print("Funcion Foco");

  if(brightness)
  {
    digitalWrite(Foco, 1);
    Serial.println("Encendido" );
  }
  else{
    digitalWrite(Foco, 0);
    Serial.println("Apagado" );
    
  }
}

void FuncionPuerta(uint8_t brightness){
  Serial.print("Funcion Puerta");

  if(brightness)
  {
    digitalWrite(Foco, 1);
    Serial.println("Encendido" );
  }
  else{
    digitalWrite(Foco, 0);
    Serial.println("Apagado" );
    
  }
}
