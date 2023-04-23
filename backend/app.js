var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');
const dotenv = require('dotenv');
const jwt = require('jsonwebtoken');

var indexRouter = require('./routes/index');
var usersRouter = require('./routes/users');
var tiliRouter = require('./routes/tili');
var asiakasRouter = require('./routes/asiakas');
var korttiRouter = require('./routes/kortti');
var loginRouter = require('./routes/login');
var tilitapahtumatRouter = require('./routes/tilitapahtumat');

var app = express();
dotenv.config();

app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

//Suojaamattomat endpointit
app.use('/', indexRouter);
app.use('/users', usersRouter);
app.use('/login',loginRouter);

app.use(authenticateToken); //Tämä middlewarena estää alemmat routet ilman oikeaa tokenia

//Suojatut endpointit
app.use('/tili', tiliRouter);
app.use('/asiakas', asiakasRouter);
app.use('/kortti', korttiRouter);
app.use('/tilitapahtumat', tilitapahtumatRouter);

//Pekan esimerkistä funktio https://peatutor.com/express/Examples/webtoken.php
//Autentikoi siis saamansa tokenin, käytetään middlewarena
function authenticateToken(req, res, next) {
    const authHeader = req.headers['authorization']
    const token = authHeader && authHeader.split(' ')[1]
  
    console.log("token = "+token);
    if (token == null) return res.sendStatus(401)
  
    jwt.verify(token, process.env.MY_TOKEN, (err, user) => {
      console.log(err)
  
      if (err) return res.sendStatus(403)
  
      req.user = user
  
      next()
    })
}


module.exports = app;
