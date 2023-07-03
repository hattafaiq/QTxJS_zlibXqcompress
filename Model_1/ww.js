const WebSocket = require('ws');

const ws = new WebSocket('ws://127.0.0.1:2121');


ws.on('open', function open() {
  ws.send(Buffer.from('fmax1000'));
});

ws.on('message', function incoming(data) {
var tmp = [];
var zlib = require('zlib');

var ok = new Buffer.from(data).toString();
//inflate adalah uncompress
//deflation artinya compress
//ada kemungkinan data yang tidak terkompresi
//note kompresi nomer 9 untuk 5 juga sama
//pengujian 1 menggunakan data string yang dimasukkan ke qbytearray
//berjumlah 1432 karakter, ukurannya(1,4Kb) terkompresi menjadi 696byte
//pengujian 2 berjumlah 515 karakter berukuran 515byte terkompresi menjadi 304byte
//pengujian 3 berjumlah 107 karakter berukuran 107byte terkompresi menjadi 102byte
//pengujian 4 berjumlah 50 karakter berukuran 50byte terkompresi menjadi 60byte XX
//pengujian 5 berjumlah 20 karakter berukuran 30byte terkompresi menjadi 42byte XX
//pengujian 6 berjumlah 5 karakter berukuan 5byte terkompresi menjadui 17byte XX
//pengujian 7 berukuran 30MB data kosong + 1,4K data string terkompresi menjadi 809byte
//pengujian 8 berukuran 100MB data kosong + 1,4K data string terkompresi menjadi 908byte
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
