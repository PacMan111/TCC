void enviarParaESP(){

  //Modifica a variável textoEnvio com os valores da medidas para enviar para o ESP
  textoEnvio =  "T" + String(temperatura);
  textoEnvio += "C" + String(tds);
  textoEnvio += "P" + String(PH);

  //Envia a variavel via comunicação Serial para o ESP
  Serial.println(textoEnvio);
}
