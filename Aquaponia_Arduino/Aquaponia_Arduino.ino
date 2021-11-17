//Inclusões de bibliotecas e declaração de variáveis e funções

//DS18B20
  #include <OneWire.h>
  #include <DallasTemperature.h>
  OneWire pino(6);
  DallasTemperature barramento(&pino);
  DeviceAddress sensor;
  float temperatura;
  void medeTemperatura();

// TDS
  #include "GravityTDS.h"
  float tds = 0;
  GravityTDS gravityTDS;
  void medeTDS();
  #define pinoSensorTDS A4

//PH
  #define pinoSensorPH A2
  //float valor_calibracao = 21.34;
  unsigned long int media; 
  int medidas[10],aux;
  float PH;
  void medePH();

//Envio pro ESP
  String textoEnvio;
  void enviarParaESP();
    
int delayMedidas = 1000;

void setup() {
  Serial.begin(9600); 

  //Inicializa a biblioteca de mediçaõ do TDS
  gravityTDS.setPin(pinoSensorTDS);
  gravityTDS.setAref(5.0);
  gravityTDS.setAdcRange(1024); 
  gravityTDS.begin();

  //Inicializa a biblioteca de temperatura
  barramento.begin();
  barramento.getAddress(sensor, 0);  

  delay(1000); 
}

void loop() {
  static unsigned long medidasAnterior;
    
  if(millis() - medidasAnterior > delayMedidas){

    medeTemperatura();
    medePH();
    medeTDS();
    enviarParaESP();
    
    medidasAnterior = millis();
  }
}
