const mysql = require('mysql');
const connection = mysql.createPool({
  host: '127.0.0.1',
  user: '', //täytä oma
  password: '', //täytä oma
  database: 'pankkiautomaattidb'
});
module.exports = connection;