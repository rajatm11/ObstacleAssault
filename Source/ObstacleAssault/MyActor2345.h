// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor2345.generated.h"

UCLASS()
class OBSTACLEASSAULT_API AMyActor2345 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor2345();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere, Category="Moving Platform")
		FVector PlatformVelocity = FVector(100, 0, 0);
	UPROPERTY(EditAnywhere, Category = "Moving Platform")
		float MoveDistance = 100;
	UPROPERTY(EditAnywhere, Category = "Rotating Platform")
		FRotator RotationVelocity = FRotator(10,0,0);

	FVector StartLocation;

	void MovePlatform(float DeltaTime);
	void RotatePlatform(float DeltaTime);

	bool ShouldPlatformReturn() const;
	float GetDistanceMoved() const;
};
