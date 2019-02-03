// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"

// Sets default values
ATank::ATank()
{
    // Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
    
    //Billboard = CreateDefaultSubobject<UBillboardComponent>("Billboard");
    Mesh = CreateDefaultSubobject<UStaticMesh>("Mesh");
    //RootComponent = Mesh;
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void ATank::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    
    //only run this every tickReset ticks
    tick++;
    tick %= tickReset;
    if (tick == 0) {
        //slow down the tank
        velocity *= 0.99999999999;
    }
    //move the tank forward
    FVector v = GetActorForwardVector().RotateAngleAxis(90, FVector::UpVector);
    v *= velocity;
    SetActorLocation(GetActorLocation() + v);

	//engine sounds
	FVector Vvel = GetVelocity();
	float vel = abs(Vvel.X) + abs(Vvel.Y);

	if (!isDefeated) {
		if (vel > 0) {
			//driving sound
			if (!lastSource) {
				setAudioSource(true);
				lastSource = true;
			}
		}
		else {
			//idle sound
			if (lastSource) {
				setAudioSource(false);
				lastSource = false;
			}
		}
	}
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);  
}

void ATank::ResetSelf(FTransform newTransform) {
	currentPower = minPower;
	isDefeated = false;
	SetActorTransform(newTransform);
	SetSelfVisibility(true);
	health = maxHealth;
	setHealthBar(1);
	setDistanceBar(0, false);
}

//called from whatever is controlling the tank
//changes the velocity which moves the tank
void ATank::MoveForward(float amount) {
	if (controlEnabled) {
		if (abs(velocity) < maxSpeed) {
			velocity += amount;
		}
	}
}

//rotates the tank in place
//called by class that controls this tank
void ATank::Rotate(float amount) {
    if (controlEnabled) {
        SetActorRotation(GetActorRotation().Add(0, amount, 0));
    }
}

//Begins charging up a shot
//a different method handles firing early
void ATank::ChargeShot(float amount) {
    if (controlEnabled) {
        if (amount > 0) {
            //is the max power exceeded? if not, add to the power
            if (currentPower < maxPower) {
                currentPower += amount;
				setDistanceBar((currentPower-minPower) / (maxPower-minPower), true);
				playShotCharnging(true);
            }
            //if so, fire the shot and reset the power
            else {
                Fire(maxPower);
				setDistanceBar(0, false);
                fired = true;
                currentPower = minPower;
            }
        }
    }
}

//fires a shot early (fire button released)
void ATank::FireEarly() {
    if (controlEnabled) {
        //if the tank hasn't aready fired a full power shell
        if (!fired) {
            //Fire(int) is implemented in blueprint sublcass
            Fire(currentPower);
			setDistanceBar(0, false);
            currentPower = minPower;
        }
        //reset fired variable
        else {
            fired = false;
			setDistanceBar(0, false);
        }
    }
}

//take damage
//this is called by explosion from blueprints
void ATank::Damage(int amount) {
	if (!isDefeated) {
		health -= amount;
		setHealthBar(health / maxHealth);
		if (health <= 0) {
			isDefeated = true;
			controlEnabled = false;
			//Die() is implemented in blueprint subclass
			Die();
		}
	}
}
