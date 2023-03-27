const db = require('../database');

const tili = {
  getAll: function(callback) {
    return db.query('select * from tili', callback);
  },
  getById: function(id, callback) {
    return db.query('select * from tili where idtili=?', [id], callback);
  },
  add: function(tili, callback) {
    return db.query(
      'insert into tili (saldo, tilinumero, asiakas_idasiakas) values(?,?,?)',
      [tili.saldo, tili.tilinumero, tili.asiakas_idasiakas],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from tili where idtili=?', [id], callback);
  },
  update: function(id, tili, callback) {
    return db.query(
      'update tili set saldo=?, tilinumero=?, asiakas_idasiakas=? where idtili=?',
      [tili.saldo, tili.tilinumero, tili.asiakas_idasiakas, id],
      callback
    );
  }
};
module.exports = tili;