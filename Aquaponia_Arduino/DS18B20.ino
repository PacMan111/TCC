void medeTemperatura(){
  barramento.requestTemperatures(); //Pede as temperaturas para a biblioteca
  temperatura = barramento.getTempC(sensor); //Pega a temperatura em Celsius
}
