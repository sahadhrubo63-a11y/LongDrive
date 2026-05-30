// GitHub Path: /Source/Environment/EnvironmentManager.cpp
#include "EnvironmentManager.h"
#include "Components/SkyAtmosphereComponent.h"

// প্লেয়ারের সিলেক্ট করা লোকেশন এবং আবহাওয়া লোড করার মেইন ফাংশন
void AEnvironmentManager::ApplyEnvironmentSetup(FLocationConfig SelectedSpot, EWeatherPreset SelectedWeather)
{
    UE_LOG(LogTemp, Warning, TEXT("Loading LongDrive Map: %s (%s)"), *SelectedSpot.SpotName, *DynamicSkyStatus);

    // ১. পাহাড় ও বনজঙ্গলের প্রসিডিউরাল টেক্সচার লোড লজিক
    if (SelectedSpot.bHasMountains)
    {
        UE_LOG(LogTemp, Log, TEXT("[Terrain] Activating Mountainous Cliff meshes on sides."));
    }
    if (SelectedSpot.bHasDenseForest)
    {
        UE_LOG(LogTemp, Log, TEXT("[Terrain] Spawning Tropical Trees and Foliage."));
    }

    // ২. রিয়ালিস্টিক আবহাওয়া এবং লাইটিং ক্যালকুলেশন (UE5 Lumen integration)
    switch (SelectedWeather)
    {
        case EWeatherPreset::Cloudy:
            SetSkyOpacity(0.9f); // আকাশ মেঘলা করা
            SetDirectSunlightIntensity(0.1f); // সূর্যের আলো কমিয়ে দেওয়া
            break;

        case EWeatherPreset::HeavyRain:
            SetSkyOpacity(1.0f);
            bSpawnRainParticles = true; // বৃষ্টির ইফেক্ট চালু করা
            // পূর্বের কোডের চাকার ঘর্ষণ (Friction) কমানোর ফাংশনকে এখানে ট্রিগার করা হবে
            UE_LOG(LogTemp, Warning, TEXT("[Weather] Rain particles enabled. Wet road material applied."));
            break;

        case EWeatherPreset::Midnight:
            SetDirectSunlightIntensity(0.0f); // সূর্য ডুবিয়ে দেওয়া
            bEnableCityStreetLights = true; // শহরের বাতি ও হেডলাইট অন করা
            UE_LOG(LogTemp, Log, TEXT("[Weather] Time set to 00:00. Night mode active."));
            break;
    }
}

// ট্রাফিক লাইট এবং মানুষের AI সিস্টেম ইনিশিয়েট করা (শহরের জন্য)
void AEnvironmentManager::SetupUrbanElements(FLocationConfig SelectedSpot)
{
    if (SelectedSpot.bIsUrbanCity)
    {
        UE_LOG(LogTemp, Log, TEXT("[City AI] Activating Traffic Light Loop & Pedestrian AI Pathfinding."));
        // এখানে শহরের বড় বিল্ডিং এবং মানুষের হাঁটার পাথ তৈরি হবে
    }
}
