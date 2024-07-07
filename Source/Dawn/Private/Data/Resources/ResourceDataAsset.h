// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "EResourceType.h"
#include "ResourceDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class DAWN_API UResourceDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	EResourceType ResourceType; 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	float GatherRate;

	
};
