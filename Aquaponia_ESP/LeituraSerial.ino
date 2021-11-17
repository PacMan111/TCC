void lerSerial(){

  static unsigned long leituraAnterior;

  if(millis() - leituraAnterior > 950){
    if (Serial.available()){
      textoRecebido = Serial.readStringUntil('\n');
    }

    Serial.println(textoRecebido);

    if (textoRecebido != "" && textoRecebido.indexOf("T") >= 0 && textoRecebido.indexOf("C") > 0 && textoRecebido.indexOf("P") > 0){
      destrinchaSerial();  
    }
    
    leituraAnterior = millis();

    textoRecebido = "";
  }
  
}



// T-4C289.35D35.75Z3000.00P16.85


void destrinchaSerial(){

  temperatura = textoRecebido.substring(textoRecebido.indexOf("T") + 1, textoRecebido.indexOf("C"));
  
  TDS = textoRecebido.substring(textoRecebido.indexOf("C") + 1, textoRecebido.indexOf("P"));
  
  PH = textoRecebido.substring(textoRecebido.indexOf("P") + 1, textoRecebido.length());

  Serial.print("Temperatura: "); Serial.println(temperatura);

  Serial.print("TDS: "); Serial.println(TDS);

  Serial.print("PH: "); Serial.println(PH);

}
