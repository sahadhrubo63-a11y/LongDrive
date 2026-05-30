// GitHub Path: /Source/Vehicle/VehicleData.h
#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "VehicleData.generated.h"

// গাড়ির টাইপ নির্ধারণকারী এনাম (Enum)
UENUM(BlueprintType)
enum class EVehicleType : uint8
{
    SUV          UMETA(DisplayName = "SUV Type"),
    Sedan        UMETA(DisplayName = "Sedan Type"),
    Jeep         UMETA(DisplayName = "Off-Road Jeep")
};

// প্রতিটি ব্র্যান্ডের গাড়ির জন্য প্রফেশনাল ডাটা স্ট্রাকচার
USTRUCT(BlueprintType)
struct FVehicleBrandConfig
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Brand Info")
    FString BrandName; // যেমন: Toyota, BMW, Jeep, Mercedes

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Brand Info")
    UTexture2D* BrandLogo; // ব্র্যান্ডের অফিশিয়াল লোগো টেক্সচার

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Vehicle Specs")
    EVehicleType VehicleType;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Vehicle Specs")
    float MaxEngineRPM; // ড্যাশবোর্ডের স্পিডোমিটারের জন্য রিয়ালিস্টিক RPM (যেমন: 7000)

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Interior Config")
    bool HasDigitalDashboard; // গাড়িটির ইন্টেরিয়র কি ডিজিটাল নাকি অ্যানালগ মিটারের?
};
