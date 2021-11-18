#include <ESP8266WiFi.h>

String textoRecebido;
String temperatura;
String TDS;
String PH;

//WIFI
String ssid       = "Nome_Da_Rede_WiFi";
String password   = "Senha_Da_Rede_WiFi";
int ContaFaltaWifi;
void checaWifi();

void lerSerial();
void enviarDados();

void setup() {
  WiFi.begin(ssid, password); //Conecta ao WiFi
  Serial.begin(9600);
}

void loop() {

  lerSerial();

  static unsigned long enviarDadosAnterior;

  if(millis() - enviarDadosAnterior > 300000){
    if(temperatura != "" && TDS != "" && PH != ""){
        enviarDados();
    }
    enviarDadosAnterior = millis();
  }

  checaWifi();
}
