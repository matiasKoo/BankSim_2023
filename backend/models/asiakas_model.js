const db = require('../database');

const asiakas = {
    getAll: function(callback){
        return db.query('select * from asiakas', callback);
    },
    getById: function(id,callback){
        return db.query('select * from asiakas where idasiakas=?',
        [id],callback)
    },
    add: function(asiakas,callback){
        return db.query('insert into asiakas (fname, lname, henkilotunnus) values(?,?,?)',
        [asiakas.fname, asiakas.lname, asiakas.henkilotunnus],
        callback)
    },
    delete: function(id,callback){
        return db.query('delete from asiakas where idasiakas=?',[id],callback)
    },
    update: function(asiakas,callback){
        return db.query('update asiakas set fname=?,lname=?,henkilotunnus=? where idasiakas=?',
        [asiakas.fname, asiakas.lname, asiakas.henkilotunnus, asiakas.id],callback)
    }
}

module.exports = asiakas;