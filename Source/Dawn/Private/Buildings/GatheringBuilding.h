// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Dawn/Building.h"
#include "GatheringBuilding.generated.h"

enum class EResourceType : uint8;

UCLASS()
class DAWN_API AGatheringBuilding : public ABuilding
{
	GENERATED_BODY()

public:
	AGatheringBuilding();
	
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;


private:
	
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Default", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> GatheringRange;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Default", meta = (AllowPrivateAccess = "true"))
	EResourceType ResourceType;

	


};
