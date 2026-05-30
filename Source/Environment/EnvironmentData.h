// GitHub Path: /Source/Environment/EnvironmentData.h
#pragma once

#include "CoreMinimal.h"
#include "EnvironmentData.generated.h"

// দেশের নাম নির্ধারণকারী এনাম
UENUM(BlueprintType)
enum class ECountryZone : uint8
{
    Bangladesh    UMETA(DisplayName = "Bangladesh Spots"),
    India         UMETA(DisplayName = "India Spots"),
    Europe_USA    UMETA(DisplayName = "Europe & USA Spots")
};

// আবহাওয়ার ধরণ নির্ধারণকারী এনাম
UENUM(BlueprintType)
enum class EWeatherPreset : uint8
{
    Cloudy        UMETA(DisplayName = "Overcast Cloudy"),
    HeavyRain     UMETA(DisplayName = "Rainy Storm"),
    Midnight      UMETA(DisplayName = "Pitch Black Night")
};

// প্রতিটি স্পটের রিয়ালিস্টিক কনফিগারেশন স্ট্রাকচার
USTRUCT(BlueprintType)
struct FLocationConfig
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Map Info")
    FString SpotName; // যেমন: Bandarban, Kashmir, Switzerland

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Map Info")
    ECountryZone Country;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Terrain Specs")
    bool bHasMountains; // পাহাড়ি রাস্তা থাকবে কি না (দুই সাইডে পাহাড়)

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Terrain Specs")
    bool bHasDenseForest; // বনজঙ্গল থাকবে কি না

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "City Specs")
    bool bIsUrbanCity; // শহরের লোকেশন কি না (ট্রাফিক লাইট, বড় বিল্ডিং, মানুষ)
};
