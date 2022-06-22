// Fill out your copyright notice in the Description page of Project Settings.


#include "KillEmAllGameMode.h"
#include "EngineUtils.h"
#include "ShooterAIController.h"


void AKillEmAllGameMode::PawnKilled(APawn* PawnKilled)
{
    Super::PawnKilled(PawnKilled);
    
    APlayerController* PlayerController = Cast<APlayerController>(PawnKilled->GetController());
    if (PlayerController!=nullptr)
    {
        EndGame(false); 
    }
    else
    {
        for(AShooterAIController* Controller : TActorRange<AShooterAIController>(GetWorld()))
        {
            if(!Controller->IsDead())
            {
                return;
            }
        }
        EndGame(true);
    }
    
}

void AKillEmAllGameMode::EndGame(bool bIsPlayerWinner)
{
    
    for(AController* Controller :TActorRange<AController>(GetWorld()))
    {
        bool bPlayerWon = Controller->IsPlayerController() == bIsPlayerWinner;
        UE_LOG(LogTemp, Error, TEXT("bPlayerWon for %s Controller is %d"), *Controller->GetName(), bPlayerWon);
        Controller->GameHasEnded(Controller->GetPawn(), bPlayerWon);
    }
}
