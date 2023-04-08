// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlataform.generated.h"



UCLASS()
class OBSTACLEASSAULT_API AMovingPlataform : public AActor
{
	GENERATED_BODY()

	FVector StartLocation;
	FVector MoveForward;
	bool CheckDestiny(float DeltaTime);

public:

	AMovingPlataform();

	UPROPERTY(EditAnywhere, Category = "Moving Plataform")
	bool bIsMoving = false;

	UPROPERTY(VisibleAnywhere, Category = "Moving Plataform")
	bool bIsBack = false;

	UPROPERTY(EditAnywhere, Category = "Moving Plataform")
	float Velocity = 5;

	UPROPERTY(EditAnywhere, Category = "Moving Plataform")
	FVector Target;


protected:
	
	virtual void BeginPlay() override;

public:
	
	virtual void Tick(float DeltaTime) override;


};
