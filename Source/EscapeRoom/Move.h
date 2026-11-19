// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Move.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPEROOM_API UMove : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMove(); //Update

protected:
	// Called when the game starts
	virtual void BeginPlay() override; //Start

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override; //Update

	UPROPERTY(EditAnywhere)
	FVector moveOffSet;

	FVector targetLocation;

	UPROPERTY(VisibleAnywhere)
	FVector startLocation;

	float speed;

	float moveTime = 4.0;

	bool reachTarget = false;

};
