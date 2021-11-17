const url = "https://script.google.com/macros/s/AKfycbypIIHYPQhdDOJTjZXxE47MCy3dn0ijYFnvy3Sfyi_Jaxv7tDerMwAdXLZ7pvH_0Qaw/exec?action=24HOURS";
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

let arr_temperaturasDS = []
let arr_PH = []
let arr_TDS = []
let arr_Condutividade = []
let arr_Turbidez = []

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
            data: arr_temperaturasDS
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

var ctx = document.getElementById('graficoTurbidez').getContext('2d');
var graficoTurbidez = new Chart(ctx, {
type: 'line',
data: {
    labels: labels,
    datasets: [
        {
            label: "Turbidez",
            backgroundColor: '#50F',
            borderColor: '#50F',
            data: arr_Turbidez
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

    let valores = responseJson.valores

    var ultimaAtualizacao = ''

    valores.forEach(valor => {
        let ano = valor[0].substring(0, valor[0].indexOf('-'))
        let mes = valor[0].substring(valor[0].indexOf(ano) + 5, valor[0].indexOf(ano) + 7)
        let dia = valor[0].substring(valor[0].indexOf(mes) + 3, valor[0].indexOf('T'))
        let hora = valor[0].substring(valor[0].indexOf('T') + 1, valor[0].indexOf('.'))

        let data

        if(valor[0].length > 0){
            data = dia + "/" + mes + '/' + ano + " " + hora
            ultimaAtualizacao = data;

            labels.push(data)
            arr_TDS.push(valor[2])
            arr_Condutividade.push(parseInt(valor[2]) * 2 / 1000)
            arr_Turbidez.push(valor[3])
            arr_PH.push(valor[4])
            arr_temperaturasDS.push(valor[5])
        }
        
    });

    document.getElementById("tds").innerHTML = valores[valores.length-1][2]
    document.getElementById("turbidez").innerHTML = valores[valores.length-1][3]
    document.getElementById("ph").innerHTML = valores[valores.length-1][4]
    document.getElementById("tempAgua").innerHTML = valores[valores.length-1][5]

    document.getElementById("condEletrica").innerHTML = parseInt(valores[valores.length-1][2]) * 2 /1000

    document.getElementById('horario').innerHTML = `Última atualização: ${ultimaAtualizacao}`

    atualizarGraficos()
    });
}

function atualizarGraficos(){
    graficoTemperatura.data.datasets[0].data = arr_temperaturasDS
    graficoPH.data.datasets[0].data = arr_PH
    graficoCondutividade_TDS.data.datasets[0].data = arr_TDS
    graficoCondutividade_TDS.data.datasets[1].data = arr_Condutividade
    graficoTurbidez.data.datasets[0].data = arr_Turbidez

    graficoTemperatura.update()
    graficoPH.update()
    graficoCondutividade_TDS.update()
    graficoTurbidez.update()
}

getDados();

setInterval(() => {
    labels.splice(0, labels.length)
    arr_TDS.splice(0, arr_TDS.length)
    arr_Condutividade.splice(0, arr_Condutividade.length)
    arr_Turbidez.splice(0, arr_Turbidez.length)
    arr_PH.splice(0, arr_PH.length)
    arr_temperaturasDS.splice(0, arr_temperaturasDS.length)
    getDados();
}, 30000)