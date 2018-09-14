const request = require('request');
const getSummary = (lat,lng,callback) => {
    request({
        url: `https://api.darksky.net/forecast/565c250071b7d5fca7c5b7e3128e097e/${lat},${lng}`,
        json: true
    },(error,response,body)=>{
        if(error){
            callback('unable to reach forecast.io server');
        } else if(response.statusCode!=200){
            callback("somethings wrong, status code:"+response.statusCode);
        }else{
            callback(undefined,body.currently.temperature);
        }
    })
}

module.exports.getSummary = getSummary;




//565c250071b7d5fca7c5b7e3128e097e