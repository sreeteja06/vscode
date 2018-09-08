var http = require('http');
var dt = require('./export_module');
http.createServer(function (req, res){
    res.writeHead(200,{'content-type':'text/html'});
    res.end('hello world' + dt.mydatetime());
}).listen(8080);