const execSync = require('child_process').execSync;
const express = require('express')
const app = express()
const port = 3000
app.all('/', function (req, res) {
    execSync('cd /home/user/Desktop/73/assignment1/processor; python main.py')
    res.sendFile('processor/index.html', {root: __dirname })
  })
app.use(express.static('processor'))
app.listen(port, () => console.log(`App listening on port ${port}!`))