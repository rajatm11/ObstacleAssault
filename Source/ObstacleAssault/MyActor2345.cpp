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
	
}

// Called every frame
void AMyActor2345::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MyVector.Z = MyVector.Z + 1;
	SetActorLocation(MyVector);
}

