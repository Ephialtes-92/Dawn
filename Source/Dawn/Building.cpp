// Fill out your copyright notice in the Description page of Project Settings.


#include "Building.h"

#include "Components/BoxComponent.h"

// Sets default values
ABuilding::ABuilding()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	SetRootComponent(DefaultSceneRoot);

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	StaticMeshComponent->SetupAttachment(GetRootComponent());

	OverlapBox = CreateDefaultSubobject<UBoxComponent>(TEXT("OverlapBox"));
	OverlapBox->SetupAttachment(GetRootComponent());


}

// Called when the game starts or when spawned
void ABuilding::BeginPlay()
{
	Super::BeginPlay();
	OverlapBox->OnComponentBeginOverlap.AddDynamic(this, &ABuilding::BeginOverlap);
	OverlapBox->OnComponentEndOverlap.AddDynamic(this, &ABuilding::EndOverlap);
}

// Called every frame
void ABuilding::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABuilding::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (Cast<ABuilding>(OtherActor))
	{
		CanBePlaced = false;
		UE_LOG(LogTemp, Warning, TEXT("Entering Overlap with another building") );
	}
}

void ABuilding::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex)
{
	if (Cast<ABuilding>(OtherActor))
	{
		CanBePlaced = true;
		UE_LOG(LogTemp, Warning, TEXT("Exiting Overlap with another building") );
	}
}

bool ABuilding::CanBuildingBePlaced() const
{
	return CanBePlaced;
}

