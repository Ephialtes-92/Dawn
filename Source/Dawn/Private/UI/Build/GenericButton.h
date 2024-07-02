﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GenericButton.generated.h"


class UButton;
class UTextBlock;
/**
 * 
 */
UCLASS(Abstract)
class DAWN_API UGenericButton : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativePreConstruct() override;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UButton* Button;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* ButtonTextBlock;

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Settings")
	FString ButtonText;
};
