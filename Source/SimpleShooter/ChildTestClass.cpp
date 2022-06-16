// Fill out your copyright notice in the Description page of Project Settings.


#include "ChildTestClass.h"

// Called when the game starts
void UChildTestClass::BeginPlay()
{
	Super::BeginPlay();

    UE_LOG(LogTemp, Warning, TEXT("Test0"));
	// ...
	TestFunc();

  
	
}

void UChildTestClass::TestFunc()
{
 
    Super::TestFunc();

	UE_LOG(LogTemp, Warning, TEXT("Child"));
    
 
}