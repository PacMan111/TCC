void checaWifi(){

static unsigned long ChecaWifiAnterior;

  if (millis() - ChecaWifiAnterior > 120000){
    
    if (WiFi.status() != WL_CONNECTED ) {
    
      WiFi.begin(ssid, password);
      Serial.println("Tentando Conectar WIFI");
      ContaFaltaWifi++;
    
    }else if (WiFi.status() == WL_CONNECTED ){
      Serial.println("WIFI está conectado ");
      ContaFaltaWifi = 0;
    }
    
    ChecaWifiAnterior = millis();
  }
  
  if (ContaFaltaWifi > 5){
    Serial.println("Falha ao conectar ao WiFi, resentando a placa");
    ESP.restart();
  }
  
}
