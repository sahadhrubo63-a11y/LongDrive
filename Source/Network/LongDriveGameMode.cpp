// GitHub Path: /Source/Network/LongDriveGameMode.cpp
#include "LongDriveGameMode.h"
#include "Json.h" // UE5 Json parsing library

ALongDriveGameMode::ALongDriveGameMode()
{
    // ডিফল্ট সেশন সেটআপ
    ActivePlayerCar = "Toyota_SUV";
    ActiveMapLocation = "BD_Bandarban";
    ActiveWeather = "Rainy_Cloudy";
}

void ALongDriveGameMode::StartPlay()
{
    Super::StartPlay();
    UE_LOG(LogTemp, Warning, TEXT("[Game Loop] LongDrive Dedicated Server is ONLINE and listening..."));
}

// ওয়েব পোর্টালের বাটনে চাপ দিলে এই ফাংশনটি ট্রিগার হবে (WebSocket/API Bridge)
void ALongDriveGameMode::OnWebPortalRequestReceived(FString JsonPayload)
{
    TSharedPtr<FJsonObject> JsonObject;
    TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(JsonPayload);

    // JSON ডাটা রিড করা (Step 1 এর app.js থেকে পাঠানো ডাটা)
    if (FJsonSerializer::Deserialize(Reader, JsonObject))
    {
        ActivePlayerCar = JsonObject->GetStringField("selectedCar");
        ActiveMapLocation = JsonObject->GetStringField("selectedMap");
        ActiveWeather = JsonObject->GetStringField("weather");

        UE_LOG(LogTemp, Warning, TEXT("[Network Bridge] Packet Received Successfully!"));
        UE_LOG(LogTemp, Log, TEXT("[Network Bridge] Syncing Player Vehicle: %s"), *ActivePlayerCar);
        
        // ১. কার সিস্টেমকে সিগন্যাল পাঠানো (Step 2 এর সাথে কানেকশন)
        // LoadVehicleProperties(ActivePlayerCar);

        // ২. ম্যাপ ও ডায়নামিক আবহাওয়া লোড করা (Step 3 এর সাথে কানেকশন)
        UE_LOG(LogTemp, Log, TEXT("[Network Bridge] Triggering Map Loader for: %s with weather: %s"), *ActiveMapLocation, *ActiveWeather);
        
        // ৩. ট্রাফিক ও পথচারী AI সচল করা (Step 4 এর সাথে কানেকশন)
        // InitializeTrafficForMap(ActiveMapLocation);
    }
}
