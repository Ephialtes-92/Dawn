// Fill out your copyright notice in the Description page of Project Settings.


#include "BuildItemWidget.h"

#include "GenericButton.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Data/BuildItemDataAsset.h"
#include "Dawn/DefaultPlayerController.h"
#include "Dawn/Build/BuildComponent.h"
#include "Kismet/GamePlayStatics.h"

void UBuildItemWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (PlaceBuildButton)
	{
		PlaceBuildButton->Button->OnClicked.AddDynamic(this, &UBuildItemWidget::OnPlaceBuildItemSelected);
	}

	verify((PlayerController = Cast<ADefaultPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0))) != nullptr);
	BuildComponent = UBuildComponent::FindBuildComponent(PlayerController);
}

void UBuildItemWidget::OnPlaceBuildItemSelected()
{
}

void UBuildItemWidget::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	Data = Cast<UBuildItemDataAsset>(ListItemObject);
	if (Data)
	{
		TitleText->SetText(Data->TitleText);
		Image->SetBrushFromTexture((Data->Image.LoadSynchronous()));
	}
}
