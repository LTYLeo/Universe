#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SimpleCube.generated.h"

UCLASS()
class UNIVERSEPROTOTYPE_API ASimpleCube : public AActor
{
    GENERATED_BODY()
    
public:    
    ASimpleCube();

protected:
    virtual void BeginPlay() override;

public:    
    virtual void Tick(float DeltaTime) override;
};