// Fill out your copyright notice in the Description page of Project Settings.


#include "Resource.h"


AResource::AResource()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AResource::BeginPlay()
{
	Super::BeginPlay();
	
}

void AResource::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

