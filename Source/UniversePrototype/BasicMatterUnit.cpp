// BasicMatterUnit.cpp
#include "BasicMatterUnit.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/Engine.h"

ABasicMatterUnit::ABasicMatterUnit()
{
    PrimaryActorTick.bCanEverTick = true;
    
    UE_LOG(LogTemp, Log, TEXT("BasicMatterUnit Constructor"));
    
    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    
    Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
    Mesh->SetupAttachment(RootComponent);
    
    // UE会自动给默认网格
    
    Mesh->SetWorldScale3D(FVector(1.0f));
    Mesh->SetSimulatePhysics(true);
    
    Temperature = 293.15f;
}

void ABasicMatterUnit::BeginPlay()
{
    Super::BeginPlay();
    
    UE_LOG(LogTemp, Log, TEXT("BasicMatterUnit BeginPlay"));
    
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, 
            TEXT("BasicMatterUnit Created"));
    }
}

void ABasicMatterUnit::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    
    // 简单冷却
    if (Temperature > 293.15f)
    {
        Temperature -= 0.1f * DeltaTime;
    }
    
    if (GEngine)
    {
        FString Msg = FString::Printf(TEXT("Temp: %.1fK"), Temperature);
        GEngine->AddOnScreenDebugMessage(1, 0.0f, FColor::Yellow, Msg);
    }
}

void ABasicMatterUnit::ReceiveHeat(float HeatAmount)
{
    Temperature += HeatAmount;
    
    UE_LOG(LogTemp, Log, TEXT("Heated: +%.1f, Now: %.1f"), HeatAmount, Temperature);
}