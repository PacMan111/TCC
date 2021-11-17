void medePH(){

 media = 0;

 //Faz 10 medições analógicas do sensor 
 for(int i=0;i<10;i++) { 
   medidas[i]=analogRead(pinoSensorPH);
   delay(30);
 }

 //Faz a media das 6 medidas do meio
 for(int i=2;i<8;i++){
    media += medidas[i];
 }

 //Converte a media das medida para voltagem
 float voltagem=(float)media*5.0/1024/6; 
 
 //PH = -5.70 * voltagem + valor_calibracao;

 //Converte a voltagem em PH
 PH = 7 + ((2.77 - voltagem) / 0.18);

 //PH = 3.5 * voltagem;

}
