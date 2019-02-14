// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Classes/Kismet/KismetMathLibrary.h"
#include "Tank.generated.h"

UCLASS()
class TANKS_API ATank : public APawn
{
    GENERATED_BODY()
    
public:
    // Sets default values for this pawn's properties
    ATank();
    
protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;
    
    int minPower = 15, maxPower=45;
    float currentPower = minPower;
    bool fired = false;
    //for increasing the deceleration time (smooth movement)
    int tick = 0, tickReset = 3;

	//true = driving, false = idling
	UFUNCTION(BlueprintImplementableEvent, Category = "Actor")
		void setAudioSource(bool source);
	bool lastSource = false;
    
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Actor")
		void setDistanceBar(float value, bool visible);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Actor")
		void playShotCharnging(bool state);

	//for custom AI, since Behavior Trees are too complex for this basic of a project
	UFUNCTION(BlueprintCallable, Category="CustomAI")
		void RunDriveLoop();
	void RunShootLoop();
	UFUNCTION(BlueprintImplementableEvent, Category = "CustomAI")
		void DriveToLocation(FVector target);
    UFUNCTION(BlueprintImplementableEvent, Category = "CustomAI")
        void PursueActor(AActor* target);
    UFUNCTION(BlueprintImplementableEvent,BlueprintCallable,Category="CustomAI")
        void StopMovement();
    FTimerHandle AITimer;
	FTimerHandle AIShootTimer;
    FTimerHandle AISwapTimer;
    void SwapChaseMode(){AIchaseMode = !AIchaseMode;}
	UPROPERTY(BlueprintreadWrite, Category="CustomAI")
	  bool AIchaseMode = false;   //True = tank will agressively pursue target, false = tank will flee
    UPROPERTY(BlueprintReadWrite,Category="CustomAI")
        bool CanShoot = true;          //determines if the AI can shoot without damaging itself (object close to barrel)
    FVector targetPos;
    FVector prevPos;
    AActor* targetActor;
    AActor* ClosestTarget();
    
	//smooth movement
	int velocity;
	int maxSpeed = 10;

	//remaps a value to fit a new high/low
	float remapValue(float value, float oldmin, float oldmax, float newmin, float newmax);
    
    //for scaling to make the game framerate independent
    float deltaTime = 0;            //deltatime stored from Tick()
    float evalNormal = 1.0/120;     //1 / the "normal" tick speed. Values in this game assume 120hz is the normal tick speed. To scale, multiply the value by deltaTime/evalNormal
public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;
    
    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
    
    //For AI, holds a list of targets if Is COM
    TArray<ATank*> OtherTanks;   //array of possible targets
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Test")
    UStaticMesh* Mesh;
    
    //whether or not this tank is computer-controlled
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    bool isCOM;
    
    //the name of this tank
    UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Actor")
    FString name;
    
    //fires a shell
    UFUNCTION(BlueprintImplementableEvent, Category = "Actor")
    void Fire(int power);
    
    //the tank explodes and removes itself
    UFUNCTION(BlueprintImplementableEvent, Category = "Actor")
    void Die();

	UFUNCTION(BlueprintImplementableEvent, Category = "Actor")
		void setHealthBar(float value);

	//resets tank to default values
	void ResetSelf(FTransform newTransform);
    
	UFUNCTION(BlueprintImplementableEvent, Category = "Actor")
		void SetSelfVisibility(bool visible);

    //the tank gets damaged by explosions
    UFUNCTION(BlueprintCallable, Category="Actor")
    virtual void Damage(int amount);
   
    
    //stats
	float maxHealth = 100;
	int health = maxHealth;
    bool controlEnabled = false;
    
    //Controls
    //movement (called by the tank controller class)
    void MoveForward(float amount);
    void Rotate(float amount);
    //when shot is charging up
    void ChargeShot(float amount);
    void FireEarly();
    
    bool isDefeated = false;
	int wins = 0;
};

