// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.h"
#include "TimerManager.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include <vector>
#include <string>
#include "GameManager.generated.h"

USTRUCT(BlueprintType)
struct FTankTracker {
    GENERATED_USTRUCT_BODY()
    UPROPERTY(EditAnywhere)
    FColor Color;
    UPROPERTY(EditAnywhere)
    bool isCOM;
    UPROPERTY(EditAnywhere)
    AActor* Spawnpoint;
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
    
    //z offset for the camera root to prevent the camera spring arm from getting confused
    int zPos = 700;
    
	//calculates the distance between the furthest apart vectors
    double MaxDistance(std::vector<FVector>& vectors);

	//resets the tanks after the round ends
	UFUNCTION()
		void ResetTanks();

	FTimerHandle TimerHandle;

	//sets up the tank controls
	void SetTankControls(UInputComponent* PlayerInputComponent);

	//if the round has been won
	bool roundWon = false;

	int currentRound = 1;

	FRotator GetAverageRotation(std::vector<FRotator> &rotators);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    //for control rerouting
    void MoveTank(float amount, int TankID);
    void RotateTank(float amount, int tankID);
    void ChargeTank(float amount, int TankID);
    void FireEarly(int TankID);
    
	UPROPERTY(EditAnywhere)
		int WinsNeeded = 5;

    UPROPERTY(EditAnywhere)
    TArray<FTankTracker> TankProperties;
    
    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Event")
    ATank* SpawnTank(FColor color, FTransform pos);
    
    UPROPERTY(EditAnywhere)
    USpringArmComponent* cameraMount;
    
    UPROPERTY(EditAnywhere)
    UCameraComponent* camera;

	UPROPERTY(EditAnywhere)
		float resetDelay = 3.0f;
    
	//tracks initial setup to prevent duplicate calls
    bool setup = false;
    
    //the array of tanks
    TArray<ATank*> tanks;
    
    //there has to be a better way
    typedef void func_t(float);
    typedef void (AGameManager::*pmemfunc_t)(float);
    void moveTank0(float amount);
    void rotateTank0(float amount);
    void moveTank1(float amount);
    void rotateTank1(float amount);
    void chargeTank0(float amount);
    void chargeTank1(float amount);
    void fireEarly0();
    void fireEarly1();
    /*
     std::vector<pmemfunc_t> moveTable = { moveTank0,moveTank1 };
     std::vector<pmemfunc_t> rotateTable = { rotateTank0,rotateTank1 };*/
    
};
