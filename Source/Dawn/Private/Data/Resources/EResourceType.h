#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EResourceType : uint8
{
	Wood UMETA(DisplayName = "Wood"),
	Stone UMETA(DisplayName = "Stone")
};