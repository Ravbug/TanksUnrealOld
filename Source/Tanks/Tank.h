// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Classes/AIController.h"
#include "Classes/AI/NavigationSystemBase.h"
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
	void RunDriveLoop();
	void RunShootLoop();
	UFUNCTION(BlueprintImplementableEvent, Category = "CustomAI")
		void DriveToLocation(FVector target);
    UFUNCTION(BlueprintImplementableEvent, Category = "CustomAI")
        void PursueActor(AActor* target);
    UFUNCTION(BlueprintImplementableEvent,Category="CustomAI")
        void StopMovement();
    FTimerHandle AITimer;
    bool AIchaseMode = false;   //True = tank will agressively pursue target, false = tank will flee 
		
	//smooth movement
	int velocity;
	int maxSpeed = 10;
    
    //for scaling to make the game framerate independent
    float deltaTime = 0;            //deltatime stored from Tick()
    float evalNormal = 1.0/120;     //1 / the "normal" tick speed. Values in this game assume 120hz is the normal tick speed. To scale, multiply the value by deltaTime/evalNormal
public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;
    
    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
    
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

