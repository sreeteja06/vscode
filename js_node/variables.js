var somestring ='pizza is alright';
somestring = somestring.replace('alright', 'wonderful');
console.log(somestring);
var http = require('http');
http.createServer(function(req,res){
    res.writeHead(200,{'content-type': 'text/html'});
    res.write(somestring);
    res.end('dayuum');
}).listen(8080);