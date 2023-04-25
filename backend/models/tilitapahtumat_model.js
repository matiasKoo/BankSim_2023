const db = require('../database');

const tilitapahtumat = {
    getAll: function(callback){
        return db.query('select * from tilitapahtumat', callback);
    },
    getById: function(id,callback){
        return db.query('select * from tilitapahtumat where idtilitapahtumat=?',
        [id],callback)
    },
    getByAccountId: function(id,callback){
        return db.query('select * from tilitapahtumat where tili_idtili=? ORDER BY aika DESC',
        [id],callback)
    },
    add: function(tilitapahtumat,callback){
        return db.query('insert into tilitapahtumat (tili_idtili, maara, aika) values(?,?,CURRENT_TIMESTAMP)',
        [tilitapahtumat.tili_idtili, tilitapahtumat.maara, tilitapahtumat.aika],
        callback)
    },
    delete: function(id,callback){
        return db.query('delete from tilitapahtumat where idtilitapahtumat=?',[id],callback)
    },
    update: function(tilitapahtumat,callback){
        return db.query('update tilitapahtumat set tili_idtili=?,maara=?,aika=CURRENT_TIMESTAMP where idtilitapahtumat=?',
        [tilitapahtumat.tili_idtili, tilitapahtumat.maara, tilitapahtumat.aika, tilitapahtumat.id],callback)
    }
}

module.exports = tilitapahtumat;