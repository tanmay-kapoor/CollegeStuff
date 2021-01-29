const express = require("express");
const bodyParser = require("body-parser");
const mongoose = require("mongoose");

const app = express();

app.use(bodyParser.urlencoded({ extended: true }));

const PORT = process.env.PORT || 3000;

mongoose.connect("mongodb://localhost:27017/restDB", {
    useNewUrlParser: true,
    useUnifiedTopology: true,
});

const employeeSchema = new mongoose.Schema({
    name: String,
    age: Number,
    department: String,
});

const Employee = new mongoose.model("Employee", employeeSchema);

app.get("/employees", async (req, res) => {
    const records = await Employee.find();
    res.send(records);
});

app.get("/employees/:id", async (req, res) => {
    try {
        const record = await Employee.find({ _id: req.params.id });
        if (record.length > 0) {
            res.send(record[0]);
        } else {
            res.send("Employee doesn't exist!");
        }
    } catch (err) {
        res.send(err);
    }
});

app.post("/employees/add", (req, res) => {
    const employee = new Employee({
        name: req.body.name,
        age: req.body.age,
        department: req.body.department,
    });
    employee
        .save()
        .then(() => res.send("Added new employee!"))
        .catch((err) => console.log(err));
});

app.put("/employees/:id", async (req, res) => {
    try {
        const updates = {
            name: req.body.name,
            age: req.body.age,
            department: req.body.department,
        };

        const record = await Employee.find({ _id: req.params.id });
        if (record.length > 0) {
            const results = await Employee.updateOne(
                { _id: req.params.id },
                updates
            );
            res.send("Updated full record");
        } else {
            res.send("Employee doesn't exist!");
        }
    } catch (err) {
        console.log(err);
    }
});

app.patch("/employees/:id", async (req, res) => {
    try {
        const updates = {
            age: req.body.age,
            department: req.body.department,
        };

        const record = await Employee.find({ _id: req.params.id });
        if (record.length > 0) {
            const results = await Employee.updateOne(
                { _id: req.params.id },
                updates
            );
            res.send("Updated record partially");
        } else {
            res.send("Employee doesn't exist!");
        }
    } catch (err) {
        console.log(err);
    }
});

app.delete("/employees/:id", async (req, res) => {
    try {
        const result = await Employee.deleteOne({ _id: req.params.id });
        res.send("Deleted specified employee!");
    } catch (err) {
        console.log(err);
    }
});

app.delete("/employees", async (req, res) => {
    try {
        const result = await Employee.deleteMany({});
        res.send("Deleted all records!");
    } catch (err) {
        console.log(err);
    }
});

app.listen(PORT, () => console.log(`Server listening on  PORT ${PORT}`));
