var express = require("express");
var app = express();
var bodyParser = require("body-parser");

const path = require('path');
const router = express.Router();

const { json } = require("express/lib/response");

app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: true }));
app.use(express.static("../frontend"));

app.get('/', (req, res) => {
    res.sendFile(path.join(__dirname+"../frontend/index.html"))
});

app.listen(process.env.port || 300);




