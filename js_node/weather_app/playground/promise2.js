const request = require('request');

var geo = (address) => {
    return new Promise((Response,Reject)=>{
        request({
            url: `https://maps.googleapis.com/maps/api/geocode/json?address=${address}`,
            json: true
        },(error,response,body)=>{
            if(error){
                Reject("something is wrong");
            }
            else if (body.status != "OK"){
                console.log(body);
                Reject("unable to fetch the location");
            }
            else if (bosy.status == "OK"){
                Response({
                    address: body.results[0].formatted_address,
                    lat: body.results[0].geometry.location.lat,
                    lng: body.results[0].geometry.location.lng
                });
            };
        });
    });
}

geo('500050').then((location)=>{
    console.log(location);
}).catch((errMsg)=>{
    console.log(errMsg);
})