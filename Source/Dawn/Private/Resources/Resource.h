// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Resource.generated.h"

UCLASS()
class DAWN_API AResource : public AActor
{
	GENERATED_BODY()

public:
	AResource();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Default", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class USceneComponent> DefaultSceneRoot;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Default", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UStaticMeshComponent> StaticMeshComponent;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category= "Default", meta = (AllowPrivateAccess = "true"))
	UDataAsset* ResourceData;

	
};
