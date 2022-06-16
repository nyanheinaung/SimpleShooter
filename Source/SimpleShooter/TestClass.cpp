// Fill out your copyright notice in the Description page of Project Settings.


#include "TestClass.h"

// Sets default values for this component's properties
UTestClass::UTestClass()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTestClass::BeginPlay()
{
	Super::BeginPlay();

	// ...
	UE_LOG(LogTemp, Warning, TEXT("Test-1"));
	
	TestFunc();
	
}


// Called every frame
void UTestClass::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTestClass::TestFunc()
{
	UE_LOG(LogTemp, Warning, TEXT("Parent"));
}