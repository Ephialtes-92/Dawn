// Fill out your copyright notice in the Description page of Project Settings.


#include "DefaultPlayerController.h"
#include "BuildingManager.h"
#include "Kismet/GamePlayStatics.h"

#include "EnhancedInputSubsystems.h"
#include "PlayerInputActions.h"

void ADefaultPlayerController::AddInputMapping(const UInputMappingContext* InputMapping, const int32 MappingPriority) const
{

	auto InputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());

	if(InputSubsystem)
	{
		ensure(InputMapping);

		if (!InputSubsystem->HasMappingContext(InputMapping))
		{
			InputSubsystem->AddMappingContext(InputMapping, MappingPriority);
		}

	}

}

void ADefaultPlayerController::RemoveInputMapping(const UInputMappingContext* InputMapping) const
{
	auto InputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (InputSubsystem)
	{
		ensure(InputMapping);
		InputSubsystem->RemoveMappingContext(InputMapping);
	}
}

void ADefaultPlayerController::SetInputDefault(const bool Enabled) const
{
	ensureAlwaysMsgf(PlayerInputActions, TEXT("PlayerActionsAsset is NULL!"));

	const UPlayerInputActions* PlayerActions = Cast<UPlayerInputActions>(PlayerInputActions);
	if (PlayerActions)
	{
		ensure(PlayerActions->MappingContextDefault);

		if(Enabled)
		{
			AddInputMapping(PlayerActions->MappingContextDefault, PlayerActions->MapPriorityDefault);
		}
		else
		{
			RemoveInputMapping(PlayerActions->MappingContextDefault);
		}
	}
}

void ADefaultPlayerController::BeginPlay()
{
	Super::BeginPlay();

	bShowMouseCursor = true;

	BuildingManager = Cast<ABuildingManager>(UGameplayStatics::GetActorOfClass(GetWorld(), ABuildingManager::StaticClass()));
	ensureAlwaysMsgf(BuildingManager, TEXT("no instance of BuildingManager foundb!"));

}

void ADefaultPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	auto InputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (InputSubsystem)
	{
		InputSubsystem->ClearAllMappings();
		SetInputDefault();
	}
	auto EnchancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
	auto PlayerInputDataAsset = Cast< UPlayerInputActions>(PlayerInputActions);

	if (EnchancedInputComponent && PlayerInputDataAsset)
	{
		EPlayerInputActions::BindInput(EnchancedInputComponent, PlayerInputDataAsset->LeftClick, ETriggerEvent::Completed, this, 
			&ADefaultPlayerController::HandleLeftClick);
	}

}

void ADefaultPlayerController::HandleLeftClick()
{
	UE_LOG(LogTemp, Warning, TEXT("Left Click Pressed"));

	if (BuildingManager)
	{
		BuildingManager->SpawnBuilding();
	}
}
