// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor2345.h"

// Sets default values
AMyActor2345::AMyActor2345()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor2345::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();

	UE_LOG(LogTemp, Display, TEXT("MoveDistance : %f"), MoveDistance);
	
}

// Called every frame
void AMyActor2345::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
}

void AMyActor2345::MovePlatform(float DeltaTime)
{
	if (ShouldPlatformReturn()) {

		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		StartLocation = StartLocation + MoveDirection * MoveDistance;
		SetActorLocation(StartLocation);
		PlatformVelocity = -PlatformVelocity;
	}
	else {
		FVector CurrentLocation = GetActorLocation();
		CurrentLocation = CurrentLocation + (PlatformVelocity * DeltaTime);
		SetActorLocation(CurrentLocation);
	}
}

void AMyActor2345::RotatePlatform(float DeltaTime)
{
	UE_LOG(LogTemp, Display, TEXT("RotatePlatform"));
}

bool AMyActor2345::ShouldPlatformReturn()
{	
	return GetDistanceMoved() > MoveDistance;
}

float AMyActor2345::GetDistanceMoved()
{
	return FVector::Dist(StartLocation, GetActorLocation());
}

