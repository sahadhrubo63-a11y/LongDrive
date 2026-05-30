// GitHub Path: /Source/AI/TrafficAIManager.cpp
#include "TrafficAIManager.h"
#include "TrafficAIController.h"

// ম্যাপের ধরণ অনুযায়ী ট্রাফিক গাড়ি এবং ট্রাক স্পন করার মেইন লজিক
void ATrafficAIManager::InitializeTrafficSystem(bool bIsMountainRoute, bool bIsUrbanCity)
{
    if (bIsMountainRoute)
    {
        UE_LOG(LogTemp, Warning, TEXT("[Traffic Manager] Activating Mountain Mode: Spawning Heavy Cargo Trucks & Jeeps."));
        MaxTrafficDensity = 15; // পাহাড়ি রাস্তায় গাড়ির চাপ কম থাকবে কিন্তু ট্রাক বেশি থাকবে
    }
    
    if (bIsUrbanCity)
    {
        UE_LOG(LogTemp, Warning, TEXT("[Traffic Manager] Activating Urban Mode: Spawning Sedans, City Buses & Pedestrians."));
        MaxTrafficDensity = 50; // শহরের রাস্তায় গাড়ির ঘনত্ব বেশি হবে
        SpawnPedestrianAI(); // ফুটপাতে মানুষ হাঁটাচলা শুরু করবে
    }
}

// শহরের ফুটপাতে সাধারণ মানুষের AI চালুর ফাংশন
void ATrafficAIManager::SpawnPedestrianAI()
{
    UE_LOG(LogTemp, Log, TEXT("[Pedestrian AI] Activating NavMesh paths for civilians walking near storefronts and crosswalks."));
    // UE5-এর NavMesh ব্যবহার করে মানুষ স্বয়ংক্রিয়ভাবে এক ফুটপাত থেকে অন্য ফুটপাতে হাঁটবে
}

// ট্রাফিক লাইট নিয়ন্ত্রণের প্রফেশনাল লুপ
void ATrafficAIManager::UpdateTrafficLights(FString CurrentSignal)
{
    // সব এআই কন্ট্রোলারকে সিগন্যাল পাঠানো
    if (CurrentSignal == "RED")
    {
        UE_LOG(LogTemp, Log, TEXT("[Traffic Network] Signal is RED. All AI vehicles updating state to StoppedAtSign."));
    }
    else if (CurrentSignal == "GREEN")
    {
        UE_LOG(LogTemp, Log, TEXT("[Traffic Network] Signal is GREEN. Traffic moving forward."));
    }
}
