#include <ESP8266WiFi.h>

String textoRecebido;

String temperatura;
//String temperaturaDS;
String TDS;
//String Turbidez;
String PH;

//WIFI
String ssid       = "AAA";
String password   = "6SCJ2013";
int ContaFaltaWifi;

void lerSerial();
void destrinchaSerial();
void enviarDados();
void checaWifi();
void reset();

void setup() {

  WiFi.begin(ssid, password);

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
  reset();
  
}
