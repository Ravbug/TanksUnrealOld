// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/DefaultPawn.h"
#include "Components/BoxComponent.h"
#include "Components/BillboardComponent.h"
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

	//smooth movement
	int velocity;
	int maxSpeed = 10;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;
    
    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Test")
    UStaticMesh* Mesh;
    
    //whether or not this tank is computer-controlled
    UPROPERTY(EditAnywhere)
    bool isCOM;
    
    //the name of this tank
    UPROPERTY(EditAnywhere)
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

