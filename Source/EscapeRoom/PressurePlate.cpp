// Fill out your copyright notice in the Description page of Project Settings.


#include "PressurePlate.h"

UPressurePlate::UPressurePlate()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UPressurePlate::BeginPlay()
{
	Super::BeginPlay();
	if (moveActor != nullptr)
	{
		moveComponent = moveActor->FindComponentByClass<UMove>();
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("MOVE COMPONENT IS NULL"));
	}

	if (isPressurePlate)
	{
		OnComponentBeginOverlap.AddDynamic(this, &UPressurePlate::OnOverlapBegin);
		OnComponentEndOverlap.AddDynamic(this, &UPressurePlate::OnOverlapEnd);
	}
}

void UPressurePlate::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UPressurePlate::Trigger(bool triggerValue)
{
	isTriggered = triggerValue;
	if (moveComponent)
	{
		moveComponent->SetShouldMove(isTriggered);
	}
}

void UPressurePlate::OnOverlapBegin(UPrimitiveComponent* overlapedComp, AActor* otherActor, UPrimitiveComponent* otherComp, int32 otherBodyIndex, 
	bool bFromSweep, const FHitResult& sweepResult)
{
	if (otherActor && otherActor->ActorHasTag("Player"))
	{
		activatorCount++;
		if (!isTriggered && activatorCount == 1)
		{
			Trigger(true);
		}

		UE_LOG(LogTemp, Display, TEXT("On Player Overlap")); //print("") = UE_LOG(LogTemp, Display, TEXT("On Player Overlap");
	}

}

void UPressurePlate::OnOverlapEnd(UPrimitiveComponent* overlapedComp, AActor* otherActor, UPrimitiveComponent* otherComp, int32 otherBodyIndex)
{
	if (otherActor && otherActor->ActorHasTag("Player"))
	{
		activatorCount--;
		if (isTriggered && activatorCount == 0)
		{
			Trigger(false);
		}

		UE_LOG(LogTemp, Display, TEXT("No Player")); //print("") = UE_LOG(LogTemp, Display, TEXT("On Player Overlap");
	}
}
