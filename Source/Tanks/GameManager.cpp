// Fill out your copyright notice in the Description page of Project Settings.

#include "GameManager.h"

// Sets default values
AGameManager::AGameManager()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    cameraMount = CreateDefaultSubobject<USpringArmComponent>("CameraBoom");
}

// Called when the game starts or when spawned
void AGameManager::BeginPlay()
{
	Super::BeginPlay();
	RoundStarting(currentRound);
	GetWorldTimerManager().SetTimer(TimerHandle, this, &AGameManager::EnableAllTanks, resetDelay, false);
}

// Called every frame
void AGameManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    
    //get the camera's desired new location
    std::vector<FVector> vectors;
	std::vector<FRotator> rotations;
    int numAlive = 0;
    ATank* winner = nullptr;
    for (ATank* t : tanks) {
        if (!t->isDefeated) {
            numAlive++;
            vectors.push_back(t->GetActorLocation());
			rotations.push_back(t->GetActorRotation());
            winner = t;
        }
    }
    FVector newLoc = GetAverageLocation(vectors);
    //apply the z offset
    newLoc.Z = zPos;
    
    //move the camera root
    SetActorLocation(newLoc);

	//rotate the camera
	FRotator newRotation = GetAverageRotation(rotations);
	newRotation.Pitch = -70;
	SetActorRotation(newRotation);
    
    //zoom the camera
    double distance = MaxDistance(vectors) * 0.75;
    
    //update the spring arm length (this doesn't work apparently)
    cameraMount->TargetArmLength = distance;
    
    
    //check winner
    if (!roundWon && numAlive < 2) {
		//round has been won
		roundWon = true;
		//FString str = FString("Winner! <Emphasis>Name</>");
        winner->controlEnabled = false;
		winner->wins++;
		FString scoreboard = FString("Scoreboard\n");

		for (ATank* t : tanks) {
			scoreboard += "<Emphasis>" + t->name + "</>		";
			if (t == winner) {
				scoreboard += "<Noteworthy>";
				scoreboard.AppendInt(t->wins);
				scoreboard += "</>\n";
			}
			else {
				scoreboard.AppendInt(t->wins);
				scoreboard += "\n";
			}
		}

		RoundWon(FString("<Emphasis>" + winner->name + "</> won the round!"),scoreboard);

		currentRound++;
		if (winner->wins >= WinsNeeded) {
			//run end game function
			RoundWon(FString("<NoteworthySmall>" + winner->name + "</> won the game!"), scoreboard);
		}
		else {
			GetWorldTimerManager().SetTimer(TimerHandle, this, &AGameManager::ResetTanks, resetDelay, false);
		}
    }
}

// Called to bind functionality to input
void AGameManager::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
    
    //prevent duplicating all the tanks
    if (!setup) {
        //spawn all the tanks
        for (int i = 0; i < TankProperties.Num(); i++) {
            FString name;
            name.AppendInt(i);
            if (TankProperties[i].isCOM) {
                name = "COM " + name;
            }
            else {
                name = "PLAYER " + name;
            }
            ATank* t = SpawnTank(TankProperties[i].Color, TankProperties[i].Spawnpoint->GetActorTransform());
			t->name = name;
            tanks.Add(t);
        }
        //setup wins array
        setup = true;
    }
    
    //setup inputs
	SetTankControls(PlayerInputComponent);
}

//resets the tanks by spawning fresh copies
//for resetting the level after the round
void AGameManager::ResetTanks() {
	roundWon = false;
	RoundStarting(currentRound);
	for (int i = 0; i < TankProperties.Num(); i++) {
		ATank* tank = tanks[i];
		tank->ResetSelf(TankProperties[i].Spawnpoint->GetActorTransform());
	}
	GetWorldTimerManager().SetTimer(TimerHandle, this, &AGameManager::EnableAllTanks, resetDelay, false);
}

//enables the tanks to recieve inputs
void AGameManager::EnableAllTanks() {
	for (ATank* t : tanks) {
		t->controlEnabled = true;
	}
}


void AGameManager::SetTankControls(UInputComponent* PlayerInputComponent) {
	for (int i = 0; i < TankProperties.Num(); i++) {
		ATank* t = tanks[i];
		if (!TankProperties[i].isCOM) {
			switch (i) {
				//todo: make this data driven instead of hard coded
			case 0:
				PlayerInputComponent->BindAxis("P0Forward", this, &AGameManager::moveTank0);
				PlayerInputComponent->BindAxis("P0Rotate", this, &AGameManager::rotateTank0);
				PlayerInputComponent->BindAxis("P0ChargeShot", this, &AGameManager::chargeTank0);
				PlayerInputComponent->BindAction("P0FireEarly", IE_Released, this, &AGameManager::fireEarly0);
				break;
			case 1:
				PlayerInputComponent->BindAxis("P1Forward", this, &AGameManager::moveTank1);
				PlayerInputComponent->BindAxis("P1Rotate", this, &AGameManager::rotateTank1);
				PlayerInputComponent->BindAxis("P1ChargeShot", this, &AGameManager::chargeTank1);
				PlayerInputComponent->BindAction("P1FireEarly", IE_Released, this, &AGameManager::fireEarly1);
				break;
			}
		}
	}
}

///Calculates the average distance between an array of FVectors
FVector AGameManager::GetAverageLocation(std::vector<FVector> &vectors) {
    FVector average = FVector(0,0,0);
    for (FVector v : vectors) {
        average.X += v.X;
        average.Y += v.Y;
        average.Z += v.Z;
    }
    average.X /= vectors.size();
    average.Y /= vectors.size();
    average.Z /= vectors.size();
    return average;
}

//calculates the average rotation of the supplied FRotators
FRotator AGameManager::GetAverageRotation(std::vector<FRotator> &rotators) {
	FRotator average = rotators[0];

	for (int i = 1; i < rotators.size(); i++) {
		FRotator r = rotators[i];
		average += r;
	}
	return average;
}

///Calculates the farthest distance between an array of vectors
double AGameManager::MaxDistance(std::vector<FVector> &vectors) {
    double maxDist = 0;
    for (FVector v : vectors) {
        for (FVector v1 : vectors) {
            if (v != v1) {
                double dist = FVector::Dist(v,v1);
                if (dist > maxDist) {
                    maxDist = dist;
                }
            }
        }
    }
    return maxDist;
}

//move or rotate a tank with a given index
void AGameManager::MoveTank(float amount, int tankID) {
    ATank* t = tanks[tankID];
    t->MoveForward(amount);
}
void AGameManager::RotateTank(float amount, int tankID) {
    ATank* t = tanks[tankID];
    t->Rotate(amount);
}
//shoot or fire early
void AGameManager::ChargeTank(float amount, int TankID) {
    tanks[TankID]->ChargeShot(amount);
}
void AGameManager::FireEarly(int TankID) {
    tanks[TankID]->FireEarly();
}

//there must be a better way than this
void AGameManager::moveTank0(float amount) {
    MoveTank(amount,0);
}
void AGameManager::moveTank1(float amount) {
    MoveTank(amount, 1);
}
void AGameManager::rotateTank0(float amount) {
    RotateTank(amount, 0);
}
void AGameManager::rotateTank1(float amount) {
    RotateTank(amount, 1);
}
void AGameManager::chargeTank0(float amount) {
    ChargeTank(amount, 0);
}
void AGameManager::chargeTank1(float amount) {
    ChargeTank(amount, 1);
}
void AGameManager::fireEarly0() {
    FireEarly(0);
}
void AGameManager::fireEarly1() {
    FireEarly(1);
}

