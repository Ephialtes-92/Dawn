// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BuildingManager.generated.h"

class ABuilding;

UCLASS()
class DAWN_API ABuildingManager : public AActor
{
	GENERATED_BODY()


public:	
	// Sets default values for this actor's properties
	ABuildingManager();

	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void SpawnBuilding();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<ABuilding> BuildingToBePlaced;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ABuilding> TypeOfBuildingToBeSpawned;

	UPROPERTY()
	class ADefaultPlayerController* PlayerController = nullptr;

	UPROPERTY()
	class UWorld* GameWorld = nullptr;

	void SnapBuildingToCursor() const;


};
