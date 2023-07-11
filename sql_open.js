var mysql = require('mysql');

var db = mysql.createConnection({
    host: "127.0.0.1",
    user: "root",
    password: "password",
    database: "test"
});

db.connect(function(err) {
    if (err) {
    //throw err;
   console.error(err);}
   else{
   console.info("Connected!");}
});
