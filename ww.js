const WebSocket = require('ws');

const ws = new WebSocket('ws://127.0.0.1:2121');


ws.on('open', function open() {
  ws.send(Buffer.from('fmax1000'));
});

ws.on('message', function incoming(data) {
var tmp = [];
var zlib = require('zlib');

var ok = new Buffer.from(data).toString();
zlib.inflate(data, function(err, data) {
    console.log("in the inflate callback:", data);
    console.log("to string:", data.toString("utf8") );});
    
const _x = Buffer.from(data, 'utf8');
console.log('raw lengths', _x.length);
console.log('byte to string',data.toString("hex") );
console.log(ok);
console.log(data);
console.log(data);
console.log("----------------------------");
    
});
