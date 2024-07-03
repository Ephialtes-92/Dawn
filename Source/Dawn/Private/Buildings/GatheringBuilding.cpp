// Fill out your copyright notice in the Description page of Project Settings.


#include "GatheringBuilding.h"


// Sets default values
AGatheringBuilding::AGatheringBuilding()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GatheringRange = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Gathering Range"));
	GatheringRange->SetupAttachment(GetRootComponent());

}

// Called when the game starts or when spawned
void AGatheringBuilding::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGatheringBuilding::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

