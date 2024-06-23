// Fill out your copyright notice in the Description page of Project Settings.


#include "DefaultPlayerController.h"
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
	ensureAlwaysMsgf(PlayerActionsAsset, TEXT("PlayerActionsAsset is NULL!"));

	const UPlayerInputActions* PlayerActions = Cast<UPlayerInputActions>(PlayerActionsAsset);
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

void ADefaultPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	auto InputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (InputSubsystem)
	{
		InputSubsystem->ClearAllMappings();
		SetInputDefault();
	}
}
