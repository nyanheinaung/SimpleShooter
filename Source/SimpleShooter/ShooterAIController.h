// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "ShooterAIController.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLESHOOTER_API AShooterAIController : public AAIController
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	bool IsDead() const;

private:
//	float AcceptanceRadius = 200.f;

	UPROPERTY(EditAnywhere)
	class UBehaviorTree* AIBehavior;

// public:
// 	virtual void GameHasEnded(class AActor* EndGameFocus = nullptr, bool bIsWinner = false) override;

public:
	void Chase();

	float ChaseSpeed = 300.f;

	void Patrol();

	float PatrolSpeed = 150.f;
};
