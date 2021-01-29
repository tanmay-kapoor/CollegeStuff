const fs = require("fs");
//create a file
fs.writeFile("create.txt", "Hello, this is Tanmay", (err) => {
    if (err) {
        console.log(err);
    } else {
        console.log("File succesfully created!\n\n");
        //read the file
        fs.readFile("create.txt", "utf8", (err, file) => {
            if (err) {
                console.log(err);
            } else {
                console.log(file);
            }
        });
    }
});
