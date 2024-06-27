// Fill out your copyright notice in the Description page of Project Settings.


#include "Framework/SHUD.h"

#include "Blueprint/UserWidget.h"
#include "UI/HudWidget.h"

void ASHUD::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void ASHUD::BeginPlay()
{
	Super::BeginPlay();
}

void ASHUD::CreateHUD()
{
	if(HudClass)
	{
		HUD = CreateWidget<UHudWidget>(GetWorld(), HudClass);
		if(HUD)
		{
			HUD->AddToViewport();
		}
	}
}