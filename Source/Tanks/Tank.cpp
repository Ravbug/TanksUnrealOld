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
		targetActor = ClosestTarget();
        GetWorldTimerManager().SetTimer(AITimer, this, &ATank::RunDriveLoop, 3, false);
		GetWorldTimerManager().SetTimer(AIShootTimer, this, &ATank::RunShootLoop, 3, false);
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
    else if (!AIchaseMode && controlEnabled){
        //back up slowly and aim towards target
        FVector v = GetActorForwardVector().RotateAngleAxis(90, FVector::UpVector);
        SetActorLocation(GetActorLocation() + v*(-maxSpeed/2)*deltaTime/evalNormal);
        
        //rotate towards target
        //calculate the angle between the vector
        FVector target = targetActor->GetActorLocation();
        FVector pos = GetActorLocation();
        FRotator newRot = UKismetMathLibrary::FindLookAtRotation(target,pos).Add(0, 90, 0);
        
        FRotator current = GetActorRotation();
        //set the rotation
        if (newRot.Yaw - current.Yaw < 0){
            SetActorRotation(current.Add(0, -2 * deltaTime/evalNormal, 0));
        }
        else{
            SetActorRotation(current.Add(0, 2 * deltaTime/evalNormal, 0));
        }
        
    }
    else if (AIchaseMode && controlEnabled){
        //rotate to face direction of travel
        //FVector v = GetVelocity();
        FVector loc = GetActorLocation();
        FRotator newRot = UKismetMathLibrary::FindLookAtRotation(loc,prevPos).Add(0, 90, 0);
        FRotator current = GetActorRotation();
        //set the rotation
        int rotSpeed = /*fmin(2,newRot.Yaw-current.Yaw)*/ 2;
        if (newRot.Yaw - current.Yaw < 0){
            SetActorRotation(current.Add(0, -rotSpeed * deltaTime/evalNormal, 0));
        }
        else{
            SetActorRotation(current.Add(0, rotSpeed * deltaTime/evalNormal, 0));
        }
        prevPos = loc;
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
	if (isCOM) {
		GetWorldTimerManager().SetTimer(AITimer, this, &ATank::RunDriveLoop, 3, false);
		GetWorldTimerManager().SetTimer(AIShootTimer, this, &ATank::RunShootLoop, 3, false);
		CanShoot = true;
	}
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

// ------------------------------- AI Functions below -------------------------------------

//routine for driving
void ATank::RunDriveLoop(){
   // AAIController* ac = (AAIController*)GetController();
    if (AIchaseMode){
        //find the closest tank to target
        targetActor = ClosestTarget();
        //Invoke UFUNCTION to pursue target
        PursueActor(targetActor);
        //Invoke shooting routine
        //if gets too close to target, cancel out
    }
    else{
        //Invoke cancel movement UFUNCTION, then re-invoke RunDriveLoop
        StopMovement();
        //Back up slowly, rotate to face target (maybe try to predict where they'll be?)
        targetActor = ClosestTarget();

    }
    if (!isDefeated){
		float switchTime = FMath::RandRange(1,5);
        GetWorldTimerManager().SetTimer(AISwapTimer, this, &ATank::SwapChaseMode, switchTime-0.5, false);
        GetWorldTimerManager().SetTimer(AITimer, this, &ATank::RunDriveLoop, switchTime, false);
    }
    
    //see AAIController::MoveToLocation on the documentation
   // UNavFilter_AIControllerDefault nqf;
    //ac->MoveToLocation(FVector(0,0,0));
   // UE_LOG(LogTemp,Warning,TEXT("Running RunDriveLoop"));
    //UNavigationSystem::SimpleMoveToLocation(ac, FVector(0,0,0));
}

//routine for shooting
void ATank::RunShootLoop(){
	//fire (if nothing blocking the turret
	if (CanShoot && controlEnabled) {
		Fire(currentPower);
	}
	//calculate the distance to the target
	if (targetActor) {
		float dist = FVector::Dist(GetActorLocation(), targetActor->GetActorLocation());
		//remap the values into the fire strength range
		currentPower = remapValue(dist, 0, 7000, minPower, maxPower);
		//wait for the amount of time needed to fire this
	}
	if (!isDefeated) {
		float time_delay = remapValue(currentPower, minPower, maxPower, 0.5, 2);
		GetWorldTimerManager().SetTimer(AIShootTimer, this, &ATank::RunShootLoop, time_delay, false);
	}

    if (AIchaseMode){
        //Shoot as often as possible, if area in front of tank is clear
        //rotate to face direction of travel
    }
    else{
        //Shoot faster if target is closer
    }
}

//determines the closest target to the current tank
AActor* ATank::ClosestTarget(){
    FVector pos = GetActorLocation();
    AActor* closest = OtherTanks[0];
    double minDist = 10000;
    for (AActor* a : OtherTanks){
        double dist = FVector::Dist(pos,a->GetActorLocation());
        if (dist < minDist){
            closest = a;
            minDist = dist;
        }
    }
    return closest;
}

float ATank::remapValue(float value, float oldmin, float oldmax, float newmin, float newmax) {
	return newmin + (value - oldmin)*(newmax - newmin) / (oldmax - oldmin);
}
