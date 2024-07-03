// Fill out your copyright notice in the Description page of Project Settings.


#include "Resource.h"


AResource::AResource()
{
	PrimaryActorTick.bCanEverTick = true;

	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	SetRootComponent(DefaultSceneRoot);

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	StaticMeshComponent->SetupAttachment(GetRootComponent());

}

void AResource::BeginPlay()
{
	Super::BeginPlay();
	
}

void AResource::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

