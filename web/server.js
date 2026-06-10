const express = require("express");
const { exec } = require("child_process");
const path = require("path");

const app = express();

app.use(
    express.static(
        path.join(__dirname, "public")
    )
);

app.get("/", (req, res) => {

    res.sendFile(
        path.join(
            __dirname,
            "public",
            "index.html"
        )
    );
});

app.get("/cities", (req, res) => {

    res.json([
        "Mumbai",
        "Pune",
        "Nashik",
        "Satara",
        "Kolhapur",
        "Belagavi",
        "Ahmednagar",
        "Aurangabad",
        "Jalgaon",
        "Nagpur",
        "Surat",
        "Vadodara",
        "Ahmedabad",
        "Udaipur",
        "Jaipur",
        "Delhi",
        "Agra",
        "Gwalior",
        "Bhopal",
        "Indore",
        "Hyderabad",
        "Bengaluru",
        "Mysuru",
        "Mangaluru",
        "Chennai",
        "Coimbatore",
        "Kochi"
    ]);
});

app.get("/route", (req, res) => {

    const source = req.query.source;
    const destination = req.query.destination;

    if (!source || !destination) {

        return res.status(400).json({
            error: "Source and destination required"
        });
    }

    const exePath = path.join(
        __dirname,
        "..",
        "logic",
        "app.exe"
    );

    const exeDir = path.join(
        __dirname,
        "..",
        "logic"
    );

    exec(
        `"${exePath}" "${source}" "${destination}"`,
        { cwd: exeDir },

        (error, stdout, stderr) => {

            console.log("STDOUT:");
            console.log(stdout);

            console.log("STDERR:");
            console.log(stderr);

            if (error) {

                return res.status(500).json({
                    error: error.message
                });
            }

            try {

                const data = JSON.parse(
                    stdout.trim()
                );

                res.json(data);

            } catch (parseError) {

                res.status(500).json({
                    error: "Invalid JSON returned",
                    stdout: stdout,
                    stderr: stderr
                });
            }
        }
    );
});

app.listen(3000, () => {

    console.log(
        "Server running on port 3000"
    );
});