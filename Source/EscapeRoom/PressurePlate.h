// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "Move.h"
#include "PressurePlate.generated.h"

/**
 * 
 */
UCLASS( ClassGroup = (Custom), meta = (BlueprintSpawnableComponent) )
class ESCAPEROOM_API UPressurePlate : public UBoxComponent
{
	GENERATED_BODY()

public:
	UPressurePlate(); //UTriggerComponent

protected:
	// Called when the game starts
	virtual void BeginPlay() override; //Start

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override; //Update

	void Trigger(bool triggerValue);

	UPROPERTY(EditAnywhere)
	bool isPressurePlate = false;

	UPROPERTY(VisibleAnywhere)
	bool isTriggered = false;

	UPROPERTY(EditAnywhere)
	AActor* moveActor;

	UMove* moveComponent;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* overlapedComp, AActor* otherActor, UPrimitiveComponent* otherComp, int32 otherBodyIndex, 
		bool bFromSweep, const FHitResult& sweepResult);

	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* overlapedComp, AActor* otherActor, UPrimitiveComponent* otherComp, int32 otherBodyIndex);
};
