// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BaseUIButtonWidget.generated.h"



class UButton;
class UImage;
class UTextBlock;
class UBaseUIButtonWidget;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FButtonClicked, UBaseUIButtonWidget*, Button, int, Index);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FButtonHovered, UBaseUIButtonWidget*, Button, int, Index);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FButtonUnHovered, UBaseUIButtonWidget*, Button, int, Index);


/**
 * 
 */
UCLASS()
class UBaseUIButtonWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeOnInitialized() override;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UButton> Button;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UImage> ButtonImage;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr < UTextBlock> ButtonText;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FButtonClicked OnButtonClicked;
	
	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FButtonHovered OnButtonHovered;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FButtonUnHovered OnButtonUnHovered;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Settings")
	int32 ButtonIndex;

protected:

	UFUNCTION()
	void OnSimpleUIButtonClickedEvent();

	UFUNCTION()
	void OnSimpleUIButtonHoveredEvent();
	
	UFUNCTION()
	void OnSimpleUIButtonUnHoveredEvent();


};
