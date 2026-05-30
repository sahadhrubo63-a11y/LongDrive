// LongDrive Online Interface Logic

function updateSelection() {
    let brand = document.getElementById("carBrand").value;
    let loc = document.getElementById("location").value;
    
    document.getElementById("status").innerText = `Selected: ${brand} | Location: ${loc}. Ready to sync.`;
}

function startLongDrive() {
    let brand = document.getElementById("carBrand").value;
    let loc = document.getElementById("location").value;

    document.getElementById("status").innerText = `Connecting to UE5 Server... Launching LongDrive in ${loc}!`;
    
    const sessionData = {
        gameName: "LongDrive",
        selectedCar: brand,
        selectedMap: loc,
        weather: "Rainy_Cloudy",
        timestamp: new Date().toISOString()
    };

    console.log("Sending session data to Unreal Engine Dedicated Server:", sessionData);
}
