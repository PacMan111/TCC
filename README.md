# TCC - Sistema automático de monitoramento de água para aquaponia

Trabalho com a proposta de desenvolver um sistema automático de monitoramento de alguns parâmetros de qualidade da água em um sistema de aquaponia, utilizando microcontroladores e sensores.
Nesse repositório encontram-se os arquivos dos códigos dos microcontroladores, do Arduino Nano na pasta [Aquaponia_Arduino](https://github.com/PacMan111/TCC/tree/main/Aquaponia_Arduino)
o do Wemos D1 mini na pasta [Aquaponia_ESP](https://github.com/PacMan111/TCC/tree/main/Aquaponia_ESP), por fim, o do aplicativo desktop desenvolvido para visualização das informações na pasta [App_Desktop](https://github.com/PacMan111/TCC/tree/main/App_Desktop)

# Instalação do aplicativo

Para fazer a instalação do aplicativo é necessário gerar o arquivo de instalação. Para isso, é necessário ter o NodeJS instalado na máquina, assim como seu gerenciador de pacotes, o NPM.

Acessando a pasta do aplicativo pelo prompt de comando, basta instalar as dependências e gerar o arquivo de instalação utilizando os seguintes comandos:

```
npm install
npm run dist
```

Após o término da execução, será criada uma pasta chamada dist no diretório, onde se encontram os executáveis de instalação.
