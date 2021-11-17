void enviarParaESP(){

  textoEnvio =  "T" + String(temperatura);
  textoEnvio += "C" + String(tds);
  textoEnvio += "P" + String(PH);

  Serial.println(textoEnvio);
  
}
