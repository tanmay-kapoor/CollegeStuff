const fs = require("fs");
const { fileURLToPath } = require("url");

//Reading file synchronously
var content = fs.readFileSync('create.txt', 'utf-8');
console.log("Reading synchrnously : \n" + content)

//redding asynchronously
fs.readFile("create.txt", "utf-8", (err, data) => {
    if(!err) {
        console.log("\nReading asynchrnously : \n" + data);
    }
    else {
        throw err;
    }
});


// writing asynchronously to a file 

var data = "Writing asynchronously."
fs.writeFile('write.txt', data, (err) => {
    // throws an error, you could also catch it here
    if (err) throw err;

    console.log('Written in file');
});

data = "Writing Synchronously"
fs.writeFileSync("write2.txt", data, "utf-8");