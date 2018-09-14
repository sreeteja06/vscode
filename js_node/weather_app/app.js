const request = require('request');
const yargs = require('yargs');
const mapsAPI = require('./geocode');
const getWeather = require('./getWeather');

const argv = yargs
.options({
    a: {
        alias: 'address',
        describe: 'address to fetch weather',
        string: true
    },
    d: {
        alias: 'default',
        describe: 'show the temperature at default location',
    }
})
.help()
.alias('help','h')
.argv;
console.log(argv);
mapsAPI.connectLocationAPI(argv.address, (errorMessage, results) => {
    if(errorMessage){
        return console.log(errorMessage);
    } else {
        getWeather.getSummary(results.lat,results.lng, (errorMSG, result)=>{
            if(errorMSG){
                console.log(errorMSG);
            }
            else{
                console.log(result);
            }
        });
        console.log(JSON.stringify(results, undefined, 2));
    }
});
