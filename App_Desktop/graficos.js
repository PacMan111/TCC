const url = "https://script.google.com/macros/s/AKfycbz3LNO6KmwctGSD-M6JvUuOSc8OkHXSK7ibzFJYBls9rmR7ayyJLYvwvbZZ3oJRxMUH/exec";
const fetch = require('node-fetch');

var Chart = require('chart.js');

var options = {
    scales:{
        x: {
            display: false
        }
    }
}

let labels = []

let arr_temperaturas = []
let arr_PH = []
let arr_TDS = []
let arr_Condutividade = []

var ctx = document.getElementById('graficoTemperatura').getContext('2d');
var graficoTemperatura = new Chart(ctx, {
type: 'line',
data: {
    labels: labels,
    datasets: [
        {
            label: "Temperatura da Água",
            backgroundColor: '#50F',
            borderColor: '#50F',
            data: arr_temperaturas
        }
    ]
},
options: options
});

var ctx = document.getElementById('graficoPH').getContext('2d');
var graficoPH = new Chart(ctx, {
    type: 'line',
    data: {
        labels: labels,
        datasets: [
            {
                label: "PH",
                backgroundColor: '#50F',
                borderColor: '#50F',
                data: arr_PH
            }
        ]
    },
    options: options
});

var ctx = document.getElementById('graficoCondutividade_TDS').getContext('2d');
var graficoCondutividade_TDS = new Chart(ctx, {
    type: 'line',
    data: {
        labels: labels,
        datasets: [
            {
                label: "Total de Solidos Dissolvidos",
                backgroundColor: '#AAF',
                borderColor: '#AAF',
                data: arr_TDS
            },
            {
                label: "Condutividade Elétrica",
                backgroundColor: '#50F',
                borderColor: '#50F',
                data: arr_Condutividade
            }
        ]
    },
    options: options
});

function getDados(){

    let settings = {
        method: "Get",
        redirect: 'follow',
     };
   
    fetch(url, settings)
    .then(res => {
        return res.json();
    })
    .then(responseJson => {

        let valores24Horas = responseJson.valores24Horas
        let ultimosValores = responseJson.ultimosValores

        console.log(valores24Horas)
        console.log(ultimosValores)

        valores24Horas.forEach(valor => {
            if(valor[0].length > 0){
                labels.push(converterDatas(valor[0]))
                arr_temperaturas.push(valor[1])
                arr_TDS.push(valor[2])
                arr_Condutividade.push(parseInt(valor[2]) * 2 / 1000)
                arr_PH.push(parseFloat(valor[3]) / 100)
            }
        });


        let dataUltimaAtt = converterDatas(ultimosValores.hora)

        document.getElementById("tempAgua").innerHTML = ultimosValores.temperatura
        document.getElementById("tds").innerHTML = ultimosValores.tds
        document.getElementById("ph").innerHTML = parseFloat(ultimosValores.pH) / 100
        document.getElementById("condEletrica").innerHTML = parseInt(ultimosValores.tds) * 2 /1000
        document.getElementById('horario').innerHTML = `Última atualização: ${dataUltimaAtt}`

        atualizarGraficos()
    });
}

function atualizarGraficos(){
    graficoTemperatura.data.datasets[0].data = arr_temperaturas
    graficoPH.data.datasets[0].data = arr_PH
    graficoCondutividade_TDS.data.datasets[0].data = arr_TDS
    graficoCondutividade_TDS.data.datasets[1].data = arr_Condutividade

    graficoTemperatura.update()
    graficoPH.update()
    graficoCondutividade_TDS.update()
}

loop()

setInterval(() => {
    loop()
}, 30000)

function loop(){
    getDados()
    labels.splice(0, labels.length)
    arr_TDS.splice(0, arr_TDS.length)
    arr_Condutividade.splice(0, arr_Condutividade.length)
    arr_PH.splice(0, arr_PH.length)
    arr_temperaturas.splice(0, arr_temperaturas.length)
}

function converterDatas(dataGoogle){
    
   if(dataGoogle != null && dataGoogle != undefined && dataGoogle != ""){
    let ano = dataGoogle.substring(0, dataGoogle.indexOf('-'))
    let mes = dataGoogle.substring(dataGoogle.indexOf(ano) + 5, dataGoogle.indexOf(ano) + 7)
    let dia = dataGoogle.substring(dataGoogle.indexOf(mes) + 3, dataGoogle.indexOf('T'))
    let hora = dataGoogle.substring(dataGoogle.indexOf('T') + 1, dataGoogle.indexOf('.'))

    return dia + "/" + mes + '/' + ano + " " + hora
   }

   return ''
}