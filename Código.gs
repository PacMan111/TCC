function doGet(e){

  var sheetAnalise = SpreadsheetApp.openByUrl("https://docs.google.com/spreadsheets/d/16BlCP9uPgg7C7jh3w7Cz3-USq5H-ByWKL2zgcWoABwE/edit#gid=0").getSheetByName('Análise') //Acessa a planilha que tem os últimos valores

  var sheet24Horas = SpreadsheetApp.openByUrl("https://docs.google.com/spreadsheets/d/16BlCP9uPgg7C7jh3w7Cz3-USq5H-ByWKL2zgcWoABwE/edit#gid=1909251125").getSheetByName('24hrs') // Acessa a planilha que contém os valores das últimas 24 horas

  var response = {
    ultimosValores: {},
    valores24Horas: []
  }

  var ultimosValores = sheetAnalise.getRange(2, 7, 1, 5).getValues() // Pega os valores das células F2 - K2

  response.ultimosValores.hora = new Date(ultimosValores[0][0])
  response.ultimosValores.hora.setHours(response.ultimosValores.hora.getHours() - 4) // Diminui 4 horas da data pois o script pega com 4 horas a mais
  response.ultimosValores.temperatura = ultimosValores[0][1]
  response.ultimosValores.tds = ultimosValores[0][2]
  response.ultimosValores.pH = ultimosValores[0][4]

  var valores24Horas = sheet24Horas.getRange(5, 1, 25, 4).getValues() // Pega os valores das últimas 24 horas

  for(let i = 0; i<valores24Horas.length; i++){ // Loop para fazer a correção do horário
    if(valores24Horas[i][0].length == null){
      valores24Horas[i][0] = new Date(valores24Horas[i][0])
      valores24Horas[i][0].setHours(  valores24Horas[i][0].getHours() - 4) // Diminui 4 horas da data pois o script pega com 4 horas a mais
    }
  }

  response.valores24Horas = valores24Horas

  return ContentService.createTextOutput(JSON.stringify(response)).setMimeType(ContentService.MimeType.JSON); // Retorna o JSON com todos os valores

}