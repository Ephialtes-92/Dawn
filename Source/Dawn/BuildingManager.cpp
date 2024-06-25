// Fill out your copyright notice in the Description page of Project Settings.


#include "BuildingManager.h"
#include "Building.h"

#include "GameFramework/PlayerController.h"
#include "Engine/World.h"


// Sets default values
ABuildingManager::ABuildingManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABuildingManager::BeginPlay()
{
	Super::BeginPlay();

	GameWorld = GetWorld();
	if (GameWorld)
	{
		PlayerController = GameWorld->GetFirstPlayerController();

		//if (PlayerController)
		//{
		//	PlayerController->bShowMouseCursor = true;
		//}
		if (TypeOfBuildingToBeSpawned)
		{
			BuildingToBePlaced = GameWorld->SpawnActor<ABuilding>(TypeOfBuildingToBeSpawned);
		}
	}

}

// Called every frame
void ABuildingManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

