/*void medeTurbidez(){

  voltagemTurbidez = 0;
    for(int i=0; i<800; i++){
        voltagemTurbidez += ((float)analogRead(pinoSensorTurbidez)/1024)*5;
    }
    
    voltagemTurbidez = voltagemTurbidez/800;
    voltagemTurbidez += 0.405;
    
    if(voltagemTurbidez < 2.5){
      turbidez = 3000;
    } else if (voltagemTurbidez > 4.2) {
      turbidez = 0;
      voltagemTurbidez = 4.2;
    }else {
      turbidez = (-1120.4*square(voltagemTurbidez)) + (5742.3*voltagemTurbidez) -4353.8; 
    }

}*/
