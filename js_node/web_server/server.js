const express = require('express');
const hbs = require('hbs');
const fs = require('fs');
const port = process.env.PORT || 3000;
let app = express();

hbs.registerPartials(__dirname+'/views/partials');
app.set('view engine','hbs');
app.use(express.static(__dirname + '/public'));

app.use((req, res, next)=>{                         //this is a middleware
    var now = new Date().toString();
    const log = `${now}: ${req.url}: ${req.method}\n`;
    fs.appendFile('server.log',log,(err)=>{
        if(err){
            console.log(err);
        }
    })
    next();
})

// app.use((req,res,next)=>{
//     res.render('maintenance.hbs');
// });

hbs.registerHelper('getCurrentYear',()=>{
    return new Date().getFullYear();
})

app.get('/home',(req,res)=>{
    res.render('home.hbs', {
        pageContent: 'this will be the about page'
    });
});

app.get('/json', (req,res)=>{
    res.send({
        hello:'JSON Hello',
        hey:'huhuhu'
    })
})

app.get('/about',(req,res)=>{
    res.render('about.hbs',{
        pageContent: 'this will be the about page'
    });
});

app.listen(port, () => {
    console.log(`server is up on ${port}`);
});