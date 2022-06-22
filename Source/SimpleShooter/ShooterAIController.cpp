// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAIController.h"
#include "Kismet/GamePlayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "ShooterCharacter.h"
#include "Components/SceneComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

void AShooterAIController::BeginPlay()
{
    Super::BeginPlay();
    if(AIBehavior != nullptr)
    {
        RunBehaviorTree(AIBehavior);


        APawn* OwnerPawn = GetPawn();
        GetBlackboardComponent()->SetValueAsVector(TEXT("StartingLocation"), OwnerPawn->GetActorLocation());
        AShooterCharacter* ShooterCharacter = Cast<AShooterCharacter>(OwnerPawn);
        GetBlackboardComponent()->SetValueAsVector(TEXT("PatrolLocation"), ShooterCharacter->GetPatrolLocation());

       // FVector PatrolLocation = OwnerPawn->Get
    }
}

void AShooterAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    // APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

    // if(LineOfSightTo(PlayerPawn))
    // {
    //     // SetFocus(PlayerPawn);
    //     // MoveToActor(PlayerPawn, AcceptanceRadius);

    //     GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), PlayerPawn->GetActorLocation());
    //     GetBlackboardComponent()->SetValueAsVector(TEXT("LastKnownPlayerLocation"), PlayerPawn->GetActorLocation());

    // }
    // else
    // {
    //     // ClearFocus(EAIFocusPriority::Gameplay);
    //     // StopMovement();

    //     GetBlackboardComponent()->ClearValue(TEXT("PlayerLocation"));
        

    // }
}

bool AShooterAIController::IsDead() const
{
    AShooterCharacter* ControlledCharacter = Cast<AShooterCharacter>(GetPawn());
    if(ControlledCharacter)
    {
        return ControlledCharacter->IsDeadFunc();
    }

    return false;
}

void AShooterAIController::Chase()
{
    AShooterCharacter* ControlledCharacter = Cast<AShooterCharacter>(GetPawn());
    if(ControlledCharacter)
    {
        ControlledCharacter->GetCharacterMovement()->MaxWalkSpeed = ChaseSpeed;
        ControlledCharacter->SetIsChasing(true);
    }
}

void AShooterAIController::Patrol()
{
    AShooterCharacter* ControlledCharacter = Cast<AShooterCharacter>(GetPawn());
    if(ControlledCharacter)
    {
        ControlledCharacter->GetCharacterMovement()->MaxWalkSpeed = PatrolSpeed;
        ControlledCharacter->SetIsChasing(false);
    }
}

// void AShooterAIController::GameHasEnded(class AActor* EndGameFocus, bool bIsWinner)
// {
//     Super::GameHasEnded(EndGameFocus, bIsWinner);
//     UE_LOG(LogTemp, Warning, TEXT("This is called by %s"), *this->GetName());
// }