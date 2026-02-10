// BasicMatterUnit.h
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BasicMatterUnit.generated.h"

UCLASS()
class UNIVERSEPROTOTYPE_API ABasicMatterUnit : public AActor
{
    GENERATED_BODY()
    
public:    
    ABasicMatterUnit();

protected:
    virtual void BeginPlay() override;

public:    
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Matter")
    float Temperature;

    UFUNCTION(BlueprintCallable, Category="Matter")
    void ReceiveHeat(float HeatAmount);

private:
    UPROPERTY(VisibleAnywhere)
    class UStaticMeshComponent* Mesh;
};