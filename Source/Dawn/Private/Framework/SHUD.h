// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SHUD.generated.h"

class UHudWidget;
/**
 * 
 */
UCLASS(Abstract)
class ASHUD : public AHUD
{
	GENERATED_BODY()

public:
	//ASHUD();
	virtual void Tick(float DeltaSeconds) override;

	UFUNCTION()
	void CreateHUD();

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Settings|UI");
	TSubclassOf<UUserWidget> HudClass;

	UPROPERTY()
	UHudWidget* HUD;
	
};
