const express = require("express");
const app = express();
const bodyParser = require("body-parser");

const path = require('path');
const router = express.Router();

const { json } = require("express/lib/response");

let resultado;

app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: true }));
app.use(express.static("../frontend"));

app.get('/', (req, res) => {
    res.sendFile(path.join(__dirname+"../frontend/index.html"))
});


app.post ('/resultado', (req, res) => {
    res.header('Access-Control-Allow-Origin','*')

    resultado = req.body;
    console.log(resultado);
});

app.get ('/esp', (req,res) =>{
    res.send(resultado);
});

router.get('/limpa/dados', (req,res)=>{
    resultado = ""
    res.send("Limpo")
})

app.use('/', router);
app.listen(process.env.port || 300);




