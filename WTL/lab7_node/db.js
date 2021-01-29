var mysql = require("mysql");
var connection = mysql.createConnection({
    host: "localhost",
    user: "root",
    password: "fruitninja",
    database: "my_db",
});

connection.query(
    "CREATE TABLE customers (name VARCHAR(255), address VARCHAR(255))",
    (err, results) => {
        if (!err) {
            console.log("created table customers");
        } else {
            console.log(err);
        }
    }
);

connection.query(
    "INSERT INTO customers (name, address) VALUES ('Company Inc', 'Highway 37'), ('Company2 Inc', 'Highway 34'),('Company3 Inc', 'Highway 30')",
    (err, results) => {
        if (!err) {
            console.log("Inserted 3 records in customers");
        } else {
            console.log(err);
        }
    }
);

connection.query("SELECT * FROM customers", (err, records) => {
    if (!err) {
        console.log("\nReading from db:");
        records.forEach((record) => console.log(record));
    } else {
        console.log(err);
    }
});

connection.query(
    "UPDATE customers SET name = 'Company55 Inc' WHERE name = 'Company2 Inc'",
    (err, results) => {
        if (!err) {
            console.log("\nUpdated record 2 :");
            connection.query("SELECT * FROM customers", (err, records) => {
                if (!err) {
                    records.forEach((record) => console.log(record));

                    connection.query(
                        "DELETE FROM customers WHERE name = 'Company3 Inc'",
                        (err, results) => {
                            if (!err) {
                                console.log("\nDeleted record 3 :");
                                connection.query(
                                    "SELECT * FROM customers",
                                    (err, records) => {
                                        if (!err) {
                                            records.forEach((record) =>
                                                console.log(record)
                                            );
                                        } else {
                                            console.log(err);
                                        }
                                    }
                                );
                            } else {
                                console.log(err);
                            }
                        }
                    );
                } else {
                    console.log(err);
                }
            });
        } else {
            console.log(err);
        }
    }
);
