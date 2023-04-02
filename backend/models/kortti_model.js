const db = require('../database');

const kortti = {
  getAll: function(callback) {
    return db.query('select * from kortti', callback);
  },
  getById: function(id, callback) {
    return db.query('select * from kortti where idkortti=?', [id], callback);
  },
  add: function(kortti, callback) {
    return db.query(
      'insert into kortti (asiakas_idasiakas,korttinumero,PIN,luottoraja,tili_idtili) values(?,?,?,?,?)',
      [kortti.asiakas_idasiakas, kortti.korttinumero, kortti.PIN, kortti.luottoraja, kortti.tili_idtili],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from kortti where idkortti=?', [id], callback);
  },
  update: function(id, kortti, callback) {
    return db.query(
      'update kortti set asiakas_idasiakas=?, korttinumero=?, PIN=?, luottoraja=?, tili_idtili=? where idkortti=?',
      [kortti.asiakas_idasiakas, kortti.korttinumero, kortti.PIN, kortti.luottoraja, kortti.tili_idtili, id],
      callback
    );
  }
};
module.exports = kortti;