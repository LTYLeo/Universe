#include "SimpleCube.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/Engine.h"

ASimpleCube::ASimpleCube()
{
    PrimaryActorTick.bCanEverTick = true;
    
    // 输出构造函数被调用
    UE_LOG(LogTemp, Warning, TEXT("🔨 SIMPLECUBE CONSTRUCTOR CALLED"));
    
    // 创建根组件
    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    
    // 创建静态网格组件
    UStaticMeshComponent* Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
    Mesh->SetupAttachment(RootComponent);
    
    // UE会自动给一个默认的立方体网格，我们不需要手动加载
    
    // 设置缩放（确保可见）
    Mesh->SetWorldScale3D(FVector(2.0f, 2.0f, 2.0f));  // 2倍大小
    
    // 启用物理
    Mesh->SetSimulatePhysics(true);
    
    UE_LOG(LogTemp, Warning, TEXT("✅ SIMPLECUBE created successfully"));
}

void ASimpleCube::BeginPlay()
{
    Super::BeginPlay();
    
    UE_LOG(LogTemp, Warning, TEXT("📍 SIMPLECUBE BeginPlay at position: %s"), 
           *GetActorLocation().ToString());
    
    // 屏幕显示
    if (GEngine)
    {
        FString Msg = TEXT("🎯 SIMPLE CUBE IS ALIVE!");
        GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, Msg);
    }
}

void ASimpleCube::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    
    // 简单旋转
    AddActorLocalRotation(FRotator(0, 60.0f * DeltaTime, 0));
    
    // 显示位置
    if (GEngine)
    {
        FString PosMsg = FString::Printf(TEXT("Cube at: (%.0f, %.0f, %.0f)"), 
            GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z);
        GEngine->AddOnScreenDebugMessage(1, 0.0f, FColor::Yellow, PosMsg);
    }
}