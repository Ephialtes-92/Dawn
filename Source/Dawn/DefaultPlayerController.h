// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "DefaultPlayerController.generated.h"

/**
 * 
 */

enum class EControllerState : uint8 
{
	Default,
	PlacingBuilding

};

class UInputMappingContext;

UCLASS()
class DAWN_API ADefaultPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	UFUNCTION()
	void AddInputMapping(const UInputMappingContext* InputMapping, const int32 MappingPriority = 0) const;
	
	UFUNCTION()
	void RemoveInputMapping(const UInputMappingContext* InputMapping) const;

	UFUNCTION()
	void SetInputDefault(const bool Enabled = true) const;

	UFUNCTION()
	UDataAsset* GetInputActionsAsset() const { return PlayerInputActions; };

	void SetState(EControllerState NewState) { State = NewState; }
	EControllerState GetState() const { return State; }


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	virtual void SetupInputComponent() override;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	UDataAsset* PlayerInputActions;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	TObjectPtr<class ABuildingManager> BuildingManager;


private:

	FVector TargetLocation;
	EControllerState State = EControllerState::Default;

	void HandleLeftClick();

};
