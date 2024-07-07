// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Dawn/Building.h"
#include "Dawn/Private/Data/Resources/EResourceType.h"
#include "GatheringBuilding.generated.h"

UCLASS()
class DAWN_API AGatheringBuilding : public ABuilding
{
	GENERATED_BODY()

public:
	AGatheringBuilding();
	
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void BeginOverlapWithResource(UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);

	UFUNCTION()
	void EndOverlapWithResource(UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex);


protected:
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Default", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> GatheringRange;

private:
	
	UPROPERTY(EditDefaultsOnly, Category = "Default", meta = (AllowPrivateAccess = "true"))
	EResourceType ResourceType;
	
};
