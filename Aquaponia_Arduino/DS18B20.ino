void medeTemperatura(){
  barramento.requestTemperatures(); 
  temperatura = barramento.getTempC(sensor);
}
