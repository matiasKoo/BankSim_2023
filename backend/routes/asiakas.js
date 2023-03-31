const express = require('express');
const router = express.Router();
const asiakas = require('../models/asiakas_model');

router.get('/',function(req,res){
    asiakas.getAll(function(err,dbResult){
        if(err){
            res.json(err)
        }
        else{
            res.json(dbResult)
        }
    })
})


router.get('/:id', function(req,res){
    asiakas.getById(req.params.id, function(err,dbResult){
        if (err) {
            res.json(err)
        } else {
            res.json(dbResult[0])
        }
    })
})

router.post('/',function(req,res){
    asiakas.add(req.body, function(err,dbResult){
        if (err){
            res.json(err)
        } else {
            res.json(dbResult.affectedRows)
        }
    })
})

router.delete('/:id', function(req,res){
    asiakas.delete(req.params.id,function(err,dbResult){
        if (err){
            res.json(err)
        } else {
            res.json(dbResult.affectedRows)
        }
    })
})

router.put('/', function(req,res){
    asiakas.update(req.body, function(err,dbResult){
        if (err){
            res.json(err)
        } else {
            res.json(dbResult.affectedRows)
        }
    })
})

module.exports = router;