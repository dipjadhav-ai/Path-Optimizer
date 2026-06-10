window.onload = async () => {

    try{

        const response =
            await fetch("/cities");

        const cities =
            await response.json();

        const source =
            document.getElementById("source");

        const destination =
            document.getElementById("destination");

        cities.forEach(city => {

            source.innerHTML +=
                `<option value="${city}">
                    ${city}
                </option>`;

            destination.innerHTML +=
                `<option value="${city}">
                    ${city}
                </option>`;
        });
    }

    catch(error){

        console.error(
            "Unable to load cities",
            error
        );
    }
};

async function findRoute(){

    const source =
        document.getElementById("source").value;

    const destination =
        document.getElementById("destination").value;

    if(!source || !destination){

        alert(
            "Please select both cities."
        );

        return;
    }

    try{

        const response =
            await fetch(
                `/route?source=${source}&destination=${destination}`
            );

        const data =
            await response.json();

        const result =
            document.getElementById("result");

        if(data.error){

            result.innerHTML =
            `
                <div class="error">
                    ${data.error}
                </div>
            `;

            return;
        }

        let html = `

            <div class="distance">
                Minimum Travel Cost : ${data.distance}
            </div>

            <div class="stats">

                <div class="stat-card">

                    <div class="stat-title">
                        Cities Visited
                    </div>

                    <div class="stat-value">
                        ${data.path.length}
                    </div>

                </div>

                <div class="stat-card">

                    <div class="stat-title">
                        Stops
                    </div>

                    <div class="stat-value">
                        ${data.path.length - 1}
                    </div>

                </div>

            </div>

            <div class="route">
        `;

        for(let i=0;i<data.path.length;i++){

            html += `
                <div class="city">
                    📍 ${data.path[i]}
                </div>
            `;

            if(i !== data.path.length - 1){

                html += `
                    <div class="arrow">
                        ↓
                    </div>
                `;
            }
        }

        html += `
            </div>
        `;

        result.innerHTML = html;
    }

    catch(error){

        console.error(error);

        document.getElementById("result")
            .innerHTML =
            `
                <div class="error">
                    Unable to connect to server.
                </div>
            `;
    }
}