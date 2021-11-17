void checaWifi(){

static unsigned long ChecaWifiAnterior;

if (millis() - ChecaWifiAnterior > 120000){


if (WiFi.status() != WL_CONNECTED ) {
    
    WiFi.begin(ssid, password);
    Serial.println("Tentando Conectar WIFI");
    ContaFaltaWifi++;
    
    } // if

else if (WiFi.status() == WL_CONNECTED ){
    Serial.println("WIFI está conectado ");
    ContaFaltaWifi = 0;

    } // else if


  ChecaWifiAnterior = millis();
  } // if millis


  
} // void


void reset(){
  if (ContaFaltaWifi > 4){

  Serial.println("Acho que vou resetar, wifi não fala comigo... ");
  ESP.restart();

  }
}
