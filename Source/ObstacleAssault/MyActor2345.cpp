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
}

// Called every frame
void AMyActor2345::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Move Platform Forward
		//get current location
	FVector CurrentLocation = GetActorLocation();	
		//Add vector to that location
	CurrentLocation = CurrentLocation + (PlatformVelocity * DeltaTime);
		//Set the location
	SetActorLocation(CurrentLocation);

	//Send Platform back if gone too far
		//check how far we've move
	float DistanceMoved = FVector::Dist(StartLocation, CurrentLocation);
	    // Reverse direction of motion if gone too far
	if (DistanceMoved > MoveDistance) {
		
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		StartLocation = StartLocation + MoveDirection * MoveDistance;
		SetActorLocation(StartLocation);
		PlatformVelocity = -PlatformVelocity;
	}
		
}

