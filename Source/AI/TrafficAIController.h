// GitHub Path: /Source/AI/TrafficAIController.h
#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TrafficAIController.generated.h"

// ট্রাফিক গাড়ির বর্তমান অবস্থা নির্ধারণকারী এнам
UENUM(BlueprintType)
enum class ETrafficState : uint8
{
    Cruising      UMETA(DisplayName = "Driving Normally"),
    StoppedAtSign UMETA(DisplayName = "Stopped at Traffic Light"),
    Braking       UMETA(DisplayName = "Obstacle Detected / Braking"),
    OffRoadYield  UMETA(DisplayName = "Yielding on Narrow Mountain Pass")
};

UCLASS()
class LONGDRIVE_API ATrafficAIController : public AAIController
{
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintReadWrite, Category = "Traffic AI")
    ETrafficState CurrentState;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Traffic AI")
    float SafeFollowingDistance = 1500.0f; // সামনের গাড়ি থেকে ১৫ মিটার নিরাপদ দূরত্ব (Unreal Units)

    // সামনের কোনো বাধা বা প্লেয়ারের গাড়ি ডিটেক্ট করার ফাংশন
    UFUNCTION(BlueprintCallable, Category = "Traffic AI")
    void CheckForObstacles();

    // ট্রাফিক লাইটের সিগন্যাল রিসিভ করার ফাংশন
    UFUNCTION(BlueprintCallable, Category = "Traffic AI")
    void OnTrafficLightChanged(FString LightColor);
};
