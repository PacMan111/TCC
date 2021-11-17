void medePH(){

 media = 0;

 //Faz 10 medições analógicas do sensor 
  for(int i=0;i<10;i++) { 
    medidas[i]=analogRead(pinoSensorPH);
    delay(30);
  }

  //Organiza os valors em forma crescente
  for(int i=0;i<9;i++){
    for(int j=i+1;j<10;j++){
      if(medidas[i]>medidas[j]){
        aux=medidas[i];
        medidas[i]=medidas[j];
        medidas[j]=aux;
      }
    }
  }

 //Faz a media das 6 medidas do meio
 for(int i=2;i<8;i++){
    media += medidas[i];
 }

 //Converte a media das medida para voltagem
 float voltagem=(float)media*5.0/1024/6; 

 //Converte a voltagem em PH
 PH = -5.70 * voltagem + valor_calibracao;

}
