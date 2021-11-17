void medePH(){
  
 for(int i=0;i<10;i++) { 
   medidas[i]=analogRead(pinoSensorPH);
   delay(30);
 }
 
 for(int i=0;i<9;i++){
    for(int j=i+1;j<10;j++){
        if(medidas[i]>medidas[j]){
           aux=medidas[i];
           medidas[i]=medidas[j];
           medidas[j]=aux;
        }
    }
 }
 
 media=0;
 
 for(int i=2;i<8;i++){
    media+=medidas[i];
 }
 
 float voltagem=(float)media*5.0/1024/6; 
 
 //PH = -5.70 * voltagem + valor_calibracao;

 PH = 7 + ((2.77 - voltagem) / 0.18);

 //PH = 3.5 * voltagem;

 Serial.println(voltagem);
}
