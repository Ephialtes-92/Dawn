// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/BaseUIButtonWidget.h"

#include "Components/Button.h"

void UBaseUIButtonWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	
	Button->OnClicked.AddDynamic(this, &UBaseUIButtonWidget::OnSimpleUIButtonClickedEvent);
	Button->OnHovered.AddDynamic(this, &UBaseUIButtonWidget::OnSimpleUIButtonHoveredEvent);
	Button->OnUnhovered.AddDynamic(this, &UBaseUIButtonWidget::OnSimpleUIButtonUnHoveredEvent);
	
}

void UBaseUIButtonWidget::OnSimpleUIButtonClickedEvent()
{
	OnButtonClicked.Broadcast(this, ButtonIndex);
}

void UBaseUIButtonWidget::OnSimpleUIButtonHoveredEvent()
{
	OnButtonHovered.Broadcast(this, ButtonIndex);
}

void UBaseUIButtonWidget::OnSimpleUIButtonUnHoveredEvent()
{
	OnButtonUnHovered.Broadcast(this, ButtonIndex);
}
