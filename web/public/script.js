async function findRoute(){

    const source =
        document.getElementById("source").value.trim();

    const destination =
        document.getElementById("destination").value.trim();

    if(!source || !destination){

        alert(
            "Please enter both cities."
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
                Total Travel Cost : ${data.distance}
            </div>

            <div class="route">
        `;

        for(let i=0;i<data.path.length;i++){

            html += `
                <div class="city">
                    📍 ${data.path[i]}
                </div>
            `;

            if(i !== data.path.length-1){

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