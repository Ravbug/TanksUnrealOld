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
    //start the AI loop if is COM
    if (isCOM){
        GetWorldTimerManager().SetTimer(AITimer, this, &ATank::RunDriveLoop, 3, false);
    }
}

// Called every frame
void ATank::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    deltaTime = DeltaTime;
        
    //only run this every tickReset ticks
	if (!isCOM) {
		tick++;
		tick %= tickReset;
		if (tick == 0) {
			//slow down the tank
			velocity -= velocity * 0.05 * deltaTime/evalNormal;
		}
		//move the tank forward
		FVector v = GetActorForwardVector().RotateAngleAxis(90, FVector::UpVector);
		v *= velocity;
		SetActorLocation(GetActorLocation() + v);
	}

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
		if (abs(velocity) < maxSpeed * deltaTime/evalNormal) {
			velocity += amount * deltaTime/evalNormal;
		}
	}
}

//rotates the tank in place
//called by class that controls this tank
void ATank::Rotate(float amount) {
    if (controlEnabled) {
        //scale for deltaTime
        amount *= deltaTime/evalNormal;
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
                currentPower += amount * deltaTime/evalNormal;
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

//AI Functions below

//routine for driving
void ATank::RunDriveLoop(){
   // AAIController* ac = (AAIController*)GetController();
    
    if (AIchaseMode){
        //find the closest tank to target
        //Invoke UFUNCTION to pursue target
        //Invoke shooting routine
        //if gets too close to target, cancel out
        //invert AIchaseMode
        //Invoke cancel movement UFUNCTION, then re-invoke RunDriveLoop
    }
    else{
        //Back up slowly, rotate to face target (maybe try to predict where they'll be?)
        //drive there with a timeout
        FVector target = FVector(0,0,0);
        DriveToLocation(target);
        //invert AIchaseMode
        //invoke cancel movement UFUNCTION, then reinvoke rundriveloop
    }
    
    //see AAIController::MoveToLocation on the documentation
   // UNavFilter_AIControllerDefault nqf;
    //ac->MoveToLocation(FVector(0,0,0));
   // UE_LOG(LogTemp,Warning,TEXT("Running RunDriveLoop"));
    //UNavigationSystem::SimpleMoveToLocation(ac, FVector(0,0,0));
}

//routine for shooting
void ATank::RunShootLoop(){
    if (AIchaseMode){
        //Shoot as often as possible, if area in front of tank is clear
        //rotate to face direction of travel
    }
    else{
        //Shoot faster if target is closer
    }
}
