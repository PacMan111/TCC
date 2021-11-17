void monitorSerial(){
    static unsigned long serialAnterior;

    if(millis() - serialAnterior > 5000){
      Serial.println("////////////////////////////////////////////////////////////////");
      Serial.print("Temperatura: "); Serial.print(temperatura); Serial.println("*C");
      //Serial.print("Temperatura DS18B20: " ); Serial.println(temperaturaDS);
      Serial.print("TDS:" ); Serial.println(tds);
      //Serial.print("Turbidez: "); Serial.println(turbidez);
      Serial.print("PH: "); Serial.println(PH);
      
      serialAnterior = millis();
    }
}
