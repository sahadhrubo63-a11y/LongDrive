// GitHub Path: /Source/Vehicle/LongDriveVehicle.cpp
#include "LongDriveVehicle.h"
#include "ChaosVehicleMovementComponent.h"

// প্রতি ফ্রেমে গাড়ির ডাটা এবং ড্যাশবোর্ড আপডেট করার ফাংশন
void ALongDriveVehicle::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // ১. রিয়ালিস্টিক ড্যাশবোর্ড ডাটা আপডেট (Speedometer & RPM)
    if (VehicleMovementComponent)
    {
        // m/s থেকে KMPH (কিলোমিটার পার আওয়ার) এ কনভার্ট করার রিয়ালিস্টিক ফর্মুলা
        CurrentSpeedKMPH = VehicleMovementComponent->GetForwardSpeed() * 0.036f; 
        CurrentRPM = VehicleMovementComponent->GetEngineRotationSpeed();
        
        // অনলাইন মাল্টিপ্লেয়ারে অন্য প্লেয়ারদের কাছে স্পিড সিঙ্ক করার লগ
        UE_LOG(LogTemp, Verbose, TEXT("Syncing Online: Speed = %f KMPH"), CurrentSpeedKMPH);
    }
}

// রিয়ালিস্টিক স্টিয়ারিং হুইল রোটেশন লজিক (ককপিট ভিউয়ের জন্য)
void ALongDriveVehicle::UpdateSteeringWheelVisual(float SteeringInput)
{
    // SteeringInput এর মান কিবোর্ড/স্টিয়ারিং হুইল থেকে -1.0 (Left) থেকে 1.0 (Right) আসে
    // আসল গাড়ির স্টিয়ারিং যেহেতু কয়েক চক্কর ঘোরে, তাই আমরা একে ৯০০ ডিগ্রি (900°) রোটেশনে ম্যাপ করব
    float VisualRotationAngle = SteeringInput * 450.0f; 
    
    // এই VisualRotationAngle টি সরাসরি ককপিটের থ্রিডি স্টিয়ারিং মডেলে অ্যাপ্লাই হবে
    UE_LOG(LogTemp, Log, TEXT("Dashboard Steering Wheel Rotated to: %f degrees"), VisualRotationAngle);
}

// ডায়নামিক বৃষ্টি ও ওয়াইপার কন্ট্রোল লজিক
void ALongDriveVehicle::ToggleWipers(bool bIsActive)
{
    bWipersOn = bIsActive;
    if (bWipersOn)
    {
        UE_LOG(LogTemp, Warning, TEXT("Windshield Wipers Activated for Realistic Rain Conditions."));
        // এখানে ককপিটের ওয়াইপার অ্যানিমেশন লজিক ট্রিগার হবে
    }
}
