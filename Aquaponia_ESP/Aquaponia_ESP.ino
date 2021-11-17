#include <ESP8266WiFi.h>

String textoRecebido;

String temperatura;
String TDS;
String PH;

//WIFI
String ssid       = "VIRUS";
String password   = "6SCJ2013";
int ContaFaltaWifi;

void lerSerial();
void enviarDados();
void checaWifi();

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
