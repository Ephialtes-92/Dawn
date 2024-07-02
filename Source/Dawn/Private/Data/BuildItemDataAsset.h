// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Data/BuildData.h"
#include "BuildItemDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class DAWN_API UBuildItemDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	/*Type of this item, set in Native parent class*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category= "Data Settings")
	FPrimaryAssetType DataType;

	virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId(DataType, GetFName());
	}
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Display")
	TEnumAsByte<EBuildAssetFilter> BuildAssetFilter;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Configuration")
	FText TitleText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Configuration")
	TSoftObjectPtr<UTexture2D> Image;

};
