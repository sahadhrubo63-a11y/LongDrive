// GitHub Path: /Source/Network/LongDriveGameMode.h
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "LongDriveGameMode.generated.h"

UCLASS()
class LONGDRIVE_API ALongDriveGameMode : public AGameModeBase
{
    GENERATED_BODY()

public:
    ALongDriveGameMode();

    // ওয়েব পোর্টাল থেকে আসা JSON ডাটা পার্স (Parse) করার ফাংশন
    UFUNCTION(BlueprintCallable, Category = "LongDrive Network")
    void OnWebPortalRequestReceived(FString JsonPayload);

protected:
    // গেমের মেইন সেশন স্টার্ট লুপ
    virtual void StartPlay() override;

private:
    FString ActivePlayerCar;
    FString ActiveMapLocation;
    FString ActiveWeather;
};
