// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlataform.h"

// Sets default values
AMovingPlataform::AMovingPlataform()
{

	PrimaryActorTick.bCanEverTick = true;
}


void AMovingPlataform::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();

	FVector CurrentLocation = GetActorLocation();
	MoveForward = Target - CurrentLocation;
	MoveForward.Normalize();

	FString test = "My String";
	UE_LOG(LogTemp, Display, TEXT("ff  %s"), *test);

}


void AMovingPlataform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bIsMoving) {
		if (!bIsBack) {
			SetActorLocation(GetActorLocation() += (MoveForward)*Velocity * DeltaTime);

		}
		else {
			SetActorLocation(GetActorLocation() -= (MoveForward)*Velocity * DeltaTime);
		}

		bIsBack = CheckDestiny(DeltaTime);

	}

}
bool AMovingPlataform::CheckDestiny(float DeltaTime) {
	float DistanceTarget = FVector::Dist(GetActorLocation(), Target);
	float DistanceStart = FVector::Dist(GetActorLocation(), StartLocation);

	if (DistanceTarget <= 1 + Velocity * DeltaTime) {
		return true;
	}
	else if (DistanceStart <= 1 + Velocity * DeltaTime) {
		return false;
	}
	else {
		return bIsBack;
	}
}

