var http = require("http");

var myvar = 'World';
function start() {
  function onRequest(request, response) {
    console.log("Request received.");
    response.writeHead(200, {"Content-Type": "text/html"});
    response.write("<h1>Hello "+ exports.myvar +'</h1>');
    response.end();
  }

  http.createServer(onRequest).listen(8888);
  console.log("Server has started.");
}

exports.start = start;
exports.myvar = myvar;
//start();
