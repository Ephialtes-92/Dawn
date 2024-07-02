// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BuildComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class DAWN_API UBuildComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UBuildComponent();
	static UBuildComponent* FindBuildComponent(const AActor* Actor) {return Actor ? Actor->FindComponentByClass<UBuildComponent>() : nullptr;}
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

protected:
	virtual void BeginPlay() override;

public:
};
