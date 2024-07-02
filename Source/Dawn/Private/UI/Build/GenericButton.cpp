// Fill out your copyright notice in the Description page of Project Settings.


#include "GenericButton.h"
#include "Components/TextBlock.h"

void UGenericButton::NativePreConstruct()
{
	Super::NativePreConstruct();

	if (ButtonTextBlock)
	{
		ButtonTextBlock->SetText(FText::FromString(ButtonText));
	}
}
