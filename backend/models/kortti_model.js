const db = require('../database');
const bcrypt = require('bcryptjs');

const saltRounds=10;

const kortti = {
  getAll: function(callback) {
    return db.query('select * from kortti', callback);
  },
  getById: function(id, callback) {
    return db.query('select * from kortti where idkortti=?', [id], callback);
  },
  add: function(kortti, callback) {
    bcrypt.hash(kortti.PIN, saltRounds, function(err, hash) {
      return db.query(
        'insert into kortti (asiakas_idasiakas,korttinumero,PIN,luottoraja,tili_idtili) values(?,?,?,?,?)',
        [kortti.asiakas_idasiakas, kortti.korttinumero, hash, kortti.luottoraja, kortti.tili_idtili],
        callback
      );
    });
  },
  delete: function(id, callback) {
    return db.query('delete from kortti where idkortti=?', [id], callback);
  },
  update: function(id, kortti, callback) {

    bcrypt.hash(kortti.PIN, saltRounds, function(err, hash) {
      return db.query(
        'update kortti set asiakas_idasiakas=?, korttinumero=?, PIN=?, luottoraja=?, tili_idtili=? where idkortti=?',
        [kortti.asiakas_idasiakas, kortti.korttinumero, hash, kortti.luottoraja, kortti.tili_idtili, id],
        callback
      );
    });
  }
};
module.exports = kortti;