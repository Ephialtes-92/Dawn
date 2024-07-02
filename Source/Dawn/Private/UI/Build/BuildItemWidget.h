// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "Blueprint/UserWidget.h"
#include "BuildItemWidget.generated.h"

class UBuildComponent;
class ADefaultPlayerController;
class UBuildItemDataAsset;
class UGenericButton;
class UImage;
class UTextBlock;
/**
 * 
 */
UCLASS(Abstract)
class DAWN_API UBuildItemWidget : public UUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()

public:
	virtual void NativeOnInitialized() override;

	UPROPERTY(meta = (BindWidget))
	UGenericButton* PlaceBuildButton;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TitleText;

	UPROPERTY(meta = (BindWidget))
	UImage* Image;

protected:
	UFUNCTION()
	void OnPlaceBuildItemSelected();

	//Begin IUserObjectListEntry Interface
	virtual void NativeOnListItemObjectSet(UObject* ListItemObject) override;;
	//End IUserObjectListEntry Interface

	UPROPERTY()
	ADefaultPlayerController* PlayerController;
	
	UPROPERTY()
	UBuildItemDataAsset* Data;

	UPROPERTY()
	UBuildComponent* BuildComponent;


	

};
