void medeTDS(){
  gravityTDS.setTemperature(temperatura);  // Compensasão por temperatura
  gravityTDS.update();  //Calculo
  tds = gravityTDS.getTdsValue();
  Serial.println(tds);
}
