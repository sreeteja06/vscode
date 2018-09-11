var http = require('http');
var url = require('url');
http.createServer(function(req,res){
    res.writeHead(200,{'Content-Type':'text/html'});
    res.write('hello');
    var hell = req.url;
    var q = url.parse(req.url,true).query; 
    res.end('del');
}).listen(8080);