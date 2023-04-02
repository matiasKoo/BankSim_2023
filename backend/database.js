const mysql = require('mysql');
const connection = mysql.createPool({
  host: '127.0.0.1',
  user: 'pankkiuser', //täytä oma
  password: 'pankkipass', //täytä oma
  database: 'pankkiautomaattidb'
});
module.exports = connection;