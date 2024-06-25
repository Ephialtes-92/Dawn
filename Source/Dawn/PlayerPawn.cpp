// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"

/*Camera*/
#include "Components/SceneComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

/*Enhanced Input*/
#include "EnhancedInputComponent.h"
#include "DefaultPlayerController.h"
#include "PlayerInputActions.h"

/*Math*/
#include "Kismet/KismetMathLibrary.h"


// Sets default values
APlayerPawn::APlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneRootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Scene Root"));
	SetRootComponent(SceneRootComponent);

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArmComponent->SetupAttachment(RootComponent);
	SpringArmComponent->TargetArmLength = 2000.f;
	SpringArmComponent->bDoCollisionTest = false;
	//SpringArmComponent->bUsePawnControlRotation = false;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(SpringArmComponent, USpringArmComponent::SocketName);

}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();

	TargetLocation = GetActorLocation();
	TargetRotation = SpringArmComponent->GetRelativeRotation();
	TargetZoom = SpringArmComponent->TargetArmLength;
}


// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CameraBounds();
	/*Move the camera*/
	const FVector InterpolatedLocation = UKismetMathLibrary::VInterpTo(GetActorLocation(), TargetLocation, DeltaTime, MovementSpeed);
	SetActorLocation(InterpolatedLocation);

	/*Rotate the camera*/
	const FRotator InterpolatedRotation = UKismetMathLibrary::RInterpTo(SpringArmComponent->GetRelativeRotation(), TargetRotation, DeltaTime, RotationSpeed);
	SpringArmComponent->SetRelativeRotation(TargetRotation);

	/*Zoom the camera*/
	const float InterpolatedZoom = UKismetMathLibrary::FInterpTo(SpringArmComponent->TargetArmLength, TargetZoom, DeltaTime, ZoomSpeed);
	SpringArmComponent->TargetArmLength = InterpolatedZoom;
}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* Input = CastChecked<UEnhancedInputComponent>(PlayerInputComponent);
	const ADefaultPlayerController* PlayerController = Cast< ADefaultPlayerController>(GetController());

	if (IsValid(Input) && IsValid(PlayerController))
	{
		const UPlayerInputActions* PlayerActions = Cast<UPlayerInputActions>(PlayerController->GetInputActionsAsset());
		if (PlayerActions)
		{
			EPlayerInputActions::BindInput(Input, PlayerActions->Move, ETriggerEvent::Triggered, this, &APlayerPawn::Move);
			EPlayerInputActions::BindInput(Input, PlayerActions->Zoom, ETriggerEvent::Triggered, this, &APlayerPawn::Zoom);
			EPlayerInputActions::BindInput(Input, PlayerActions->Rotate, ETriggerEvent::Triggered, this, &APlayerPawn::Rotate);


		}
	}
}

void APlayerPawn::CameraBounds()
{

	//Clamp movement
	TargetLocation = FVector(TargetLocation.X, TargetLocation.Y, 0.f);
}

void APlayerPawn::Move(const FInputActionValue& Value)
{

	if (!SpringArmComponent)
	{
		return;
	}

	if (Value.GetValueType() == EInputActionValueType::Axis2D)
	{
		FVector MovementDirection = Value.Get<FVector>();

		TargetLocation += SpringArmComponent->GetTargetRotation().RotateVector(MovementDirection) * MovementSpeed;
	}
 	
}

void APlayerPawn::Zoom(const FInputActionValue& Value)
{

	if (Value.GetValueType() == EInputActionValueType::Axis1D)
	{
		const float Zoom = Value.Get<float>() * 100.0f;

		TargetZoom = FMath::Clamp(Zoom + TargetZoom, MinZoom, MaxZoom);
	}

}

void APlayerPawn::Rotate(const FInputActionValue& Value)
{
	if (Value.GetValueType() == EInputActionValueType::Axis1D )
	{
		const float NewYaw = Value.Get<float>();

		TargetRotation = UKismetMathLibrary::ComposeRotators(TargetRotation, FRotator(0.f, NewYaw, 0.f));
	}

}


