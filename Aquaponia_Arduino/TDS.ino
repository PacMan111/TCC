void medeTDS(){
  gravityTDS.setTemperature(temperatura);  // Compensasão por temperatura
  gravityTDS.update();  //Calculo
  tds = gravityTDS.getTdsValue(); // Pega o valor do TDS
}
