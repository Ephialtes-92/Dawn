// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "EnhancedInputComponent.h"
#include "PlayerInputActions.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class DAWN_API UPlayerInputActions : public UDataAsset
{
	GENERATED_BODY()

public:
	/*Default Player Mapping Context*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Default")
	class UInputMappingContext* MappingContextDefault;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Default")
	int32 MapPriorityDefault;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Default")
	UInputAction* Move;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Default")
	UInputAction* Zoom;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Default")
	UInputAction* Rotate;

	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Default")
	UInputAction* ToggleRotation;

	
};

namespace EPlayerInputActions
{
	template<class T, class FuncType>
	void BindInput(UEnhancedInputComponent* Input, const UInputAction* Action, ETriggerEvent Event, T* Obj, FuncType TriggerFunc)
	{
		if (TriggerFunc)
		{
			Input->BindAction(Action, Event, Obj, TriggerFunc);
		}
	}

}
