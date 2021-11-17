String textFix = "GET /forms/d/e/1FAIpQLScSQ7fWASvb12ivDXFd3yvD2JXgEwAVyfLHxzEAFTWX9OBy8g/formResponse?ifq&entry.14547279=";
WiFiClientSecure client;

void enviarDados(){

  client.setInsecure();
  
   if (client.connect("docs.google.com", 443) == 1)//Tenta se conectar ao servidor do Google docs na porta 443 (HTTPS)
    {

        String toSend = textFix;

        toSend += temperatura.toInt();
        toSend +=  "&entry.1288122921=";
        toSend += TDS.toInt();
        toSend +=  "&entry.930365680=";
        toSend += PH.toFloat() * 100;
        
        toSend += "&submit=Submit HTTP/1.1";//Completamos o metodo GET para nosso formulario.
        client.println(toSend);//Enviamos o GET ao servidor-
        client.println("Host: docs.google.com");//-
        client.println();//-
        client.stop();//Encerramos a conexao com o servidor

    }
    else
    {
        //Serial.println("Erro ao se conectar");//Se nao for possivel conectar no servidor, ira avisar no monitor.
    }

    delay(1000);
}
