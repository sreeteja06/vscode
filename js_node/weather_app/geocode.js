const request = require('request');

const connectLocationAPI = (adres, callback) => {
    const address = encodeURIComponent(adres);

    request({
        url: `https://maps.googleapis.com/maps/api/geocode/json?address=${address}`,
        json: true
    }, (error, response, body) => {
        if (error) {
            console.log(error);
            callback("unable to connect to google services");
        } else if (body.status != "OK") {
            callback("unable to locate address");
        } else if(body.status=="OK"){
            callback(undefined, {
                address: body.results[0].formatted_address,
                lat: body.results[0].geometry.location.lat,
                lng: body.results[0].geometry.location.lng
            });
        }
    });
}

module.exports = {
    connectLocationAPI
}