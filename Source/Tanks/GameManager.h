// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.h"
#include "TimerManager.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include <vector>
#include "GameManager.generated.h"

USTRUCT(BlueprintType)
//exposed in the UI for GameManager
//allows the user to customize the number of tanks, whether they are computer controlled, color, spawn location, etc
struct FTankTracker {
    GENERATED_USTRUCT_BODY()
    UPROPERTY(EditAnywhere)
        FColor Color;
    UPROPERTY(EditAnywhere)
        bool isCOM;
    UPROPERTY(EditAnywhere)
        AActor* Spawnpoint;
    UPROPERTY(EditAnywhere)
        bool isEnabled = true;
};

UCLASS()
class TANKS_API AGameManager : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AGameManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
    
	//gets the average location between an array of vectors
    FVector GetAverageLocation(std::vector<FVector> &vectors);

	//calculates the average rotation
	//see the .cpp file for full description
	FRotator GetAverageRotation(std::vector<FRotator> &rotators);
    
    //z offset for the camera root to prevent the camera spring arm from getting confused
    int zPos = 900;

	//increase the camera boom length on 90 degree turns (so that on the narrow side the tanks don't get cut off)
	int rotationOffset = 20;
	const int maxDistance = 2000;
    
	//calculates the distance between the furthest apart vectors
    double MaxDistance(std::vector<FVector>& vectors);

	//resets the tanks after the round ends
	void ResetTanks();

	//for scheduling calls, used to delay starting and stopping rounds
	FTimerHandle TimerHandle;

	//sets up the tank controls
	void SetTankControls(UInputComponent* PlayerInputComponent);
	void EnableAllTanks();

	//if the round has been won
	bool roundWon = false;

	//tracks which round is currently running
	int currentRound = 1;

	//tracks initial setup to prevent duplicate calls
	bool setup = false;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    //for control rerouting
	void MoveTank(float amount, ATank* tank);
    void RotateTank(float amount, ATank* tank);
    void ChargeTank(float amount, ATank* tank);
	UFUNCTION()
		void fireEarly(ATank* tank);
    
	//the wins required to win the whole game
	UPROPERTY(EditAnywhere)
		int WinsNeeded = 5;

	//array of tank properties, which can be configured from the Unreal Editor
    UPROPERTY(EditAnywhere)
    TArray<FTankTracker> TankProperties;
    
	//Implemented in Blueprint
	//spawns a tank with the specified color, transform, and whether or not AI controls it
    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Event")
    ATank* SpawnTank(FColor color, FTransform pos, bool COM);
    
	//camera spring arm reference
    UPROPERTY(EditAnywhere)
    USpringArmComponent* cameraMount;

	//Implemented in Blueprint
	//draws text on the screen showing which round is currently running
	UFUNCTION(BlueprintImplementableEvent, Category = "Event")
		void RoundStarting(int round);

	//Implemented in Blueprint
	//Shows who won and the leaderboard
	UFUNCTION(BlueprintImplementableEvent, Category = "Event")
		void RoundWon(const FString& text, const FString& scoreboard, bool resetLevel=false);

	//Implemented in Blueprint
	//hides any existing on-screen text
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Event")
		void DismissHUD();

	//how long to wait when starting / stopping rounds
	UPROPERTY(EditAnywhere)
		float resetDelay = 3.0f;
    
    //the array of tanks
    TArray<ATank*> tanks;
    
    //there has to be a better way than this
    void moveTank0(float amount);
    void rotateTank0(float amount);
    void moveTank1(float amount);
    void rotateTank1(float amount);
    void chargeTank0(float amount);
    void chargeTank1(float amount);
	TArray<ATank*>players;  
};
