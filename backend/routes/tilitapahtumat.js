const express = require('express');
const router = express.Router();
const tilitapahtumat = require('../models/tilitapahtumat_model');

router.get('/',function(req,res){
    tilitapahtumat.getAll(function(err,dbResult){
        if(err){
            res.json(err)
        }
        else{
            res.json(dbResult)
        }
    })
});


router.get('/:id', function(req,res){
    tilitapahtumat.getById(req.params.id, function(err,dbResult){
        if (err) {
            res.json(err)
        } else {
            res.json(dbResult[0])
        }
    })
});

router.get('/1/:tili_idtili', function(req,res){
    tilitapahtumat.getByAccountId(req.params.tili_idtili, function(err,dbResult){
        if (err) {
            res.json(err)
        } else {
            res.json(dbResult)
        }
    })
});

router.post('/',function(req,res){
    tilitapahtumat.add(req.body, function(err,dbResult){
        if (err){
            res.json(err)
        } else {
            res.json(dbResult.affectedRows)
        }
    })
});

router.delete('/:id', function(req,res){
    tilitapahtumat.delete(req.params.id,function(err,dbResult){
        if (err){
            res.json(err)
        } else {
            res.json(dbResult.affectedRows)
        }
    })
});

router.put('/', function(req,res){
    tilitapahtumat.update(req.body, function(err,dbResult){
        if (err){
            res.json(err)
        } else {
            res.json(dbResult.affectedRows)
        }
    })
});

module.exports = router;