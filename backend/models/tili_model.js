const db = require('../database');
const tilitapahtumat = require('./tilitapahtumat_model');

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
  },
  nosta20: function(id, tili, callback) {
    return db.query(
      'call NostaRahaa(?,20)',
      [id],
      callback
    );
  },
  nosta40: function(id, tili, callback) {
    return db.query(
      'call NostaRahaa(?,40)',
      [id],
      callback
    );
  },
  nosta50: function(id, tili, callback) {
    return db.query(
      'call NostaRahaa(?,50)',
      [id],
      callback
    );
  },
  nosta100: function(id, tili, callback) {
    return db.query(
      'call NostaRahaa(?,100)',
      [id],
      callback
    );
  }
};
module.exports = tili;