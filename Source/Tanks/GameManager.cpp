// Fill out your copyright notice in the Description page of Project Settings.

#include "GameManager.h"

// Sets default values
AGameManager::AGameManager()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//create a camera spring arm
    cameraMount = CreateDefaultSubobject<USpringArmComponent>("CameraBoom");
}

// Called when the game starts or when spawned
void AGameManager::BeginPlay()
{
	Super::BeginPlay();
	//draw the text showing the round
	RoundStarting(currentRound);

	//schedule the first round to start by enabling the tanks
	GetWorldTimerManager().SetTimer(TimerHandle, this, &AGameManager::EnableAllTanks, resetDelay, false);
}

// Called every frame
//DeltaTime is for scaling 
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
	FRotator newRotation = /*GetAverageRotation(rotations)*/ GetActorRotation();

	//determine the rotation offset
	double distance = MaxDistance(vectors) * 0.5;
	float pitch = /*abs(sin(newRotation.Yaw*PI / 180)) * rotationOffset * (distance / maxDistance)*/ 20 * (distance / maxDistance);

	newRotation.Pitch = -50 - pitch;
	SetActorRotation(newRotation);
    
    //zoom the camera 
    //update the spring arm length
    cameraMount->TargetArmLength = distance * 1.2;
    
    //check winner
    if (!roundWon && numAlive < 2) {
		//round has been won
		roundWon = true;
		//FString str = FString("Winner! <Emphasis>Name</>");
        winner->controlEnabled = false;
		winner->wins++;
		FString scoreboard = FString("Scoreboard\n");

		//setup the scoreboard string
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

		//display the scores
		RoundWon(FString("<Emphasis>" + winner->name + "</> won the round!"),scoreboard);

		currentRound++;
		//does the winner have the required number of wins?
		if (winner->wins >= WinsNeeded) {
			//if so, they are the game winner!
			//show the scores, and siganl to reset the map
			RoundWon(FString("<NoteworthySmall>" + winner->name + "</> won the game!"), scoreboard,true);
		}
		else {
			//otherwise, reset the tanks and start a new round
			GetWorldTimerManager().SetTimer(TimerHandle, this, &AGameManager::ResetTanks, resetDelay, false);
		}
    }
}

// Called to bind functionality to input
void AGameManager::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{    
    //prevent duplicating all the tanks
    if (!setup) {
		//avoid setting up twice
		Super::SetupPlayerInputComponent(PlayerInputComponent);

        //spawn all the tanks
        for (int i = 0; i < TankProperties.Num(); i++) {
            if (TankProperties[i].isEnabled){
                FString name;
                name.AppendInt(i);
                if (TankProperties[i].isCOM) {
                    name = "COM " + name;
                }
                else {
                    name = "PLAYER " + name;
                }
				//spawn a tank and get a pointer to it
                ATank* t = SpawnTank(TankProperties[i].Color, TankProperties[i].Spawnpoint->GetActorTransform(),TankProperties[i].isCOM);

				//setup attributes, and add it to the tank array
				t->Init(name,TankProperties[i].isCOM);
				tanks.Add(t);		
            }
        }
        //tell the COMs who the other tanks are
        for (ATank* t : tanks){
            if (t->isCOM){
                t->OtherTanks = TArray<ATank*>(tanks);
				//remove pointer to tank's self so it can't target itself
                t->OtherTanks.Remove(t);
            }
        }
        //mark setup as complete, so duplicate calls don't run
        setup = true;
    }
    
    //setup inputs
	SetTankControls(PlayerInputComponent);
}

//Resets the tanks locations and other attributes
//For resetting the level after the round
void AGameManager::ResetTanks() {
	roundWon = false;
	RoundStarting(currentRound);
	for (ATank* tank : tanks) {
		tank->ResetSelf();
	}
	GetWorldTimerManager().SetTimer(TimerHandle, this, &AGameManager::EnableAllTanks, resetDelay, false);
}

//Enables the tanks to recieve inputs
void AGameManager::EnableAllTanks() {
	for (ATank* t : tanks) {
		t->controlEnabled = true;
	}
}

/*Sets the connections to the controllers for human-controlled tanks
* @param (UInputComponent*) PlayerInputComponent: Reference to the player input component object
*/
void AGameManager::SetTankControls(UInputComponent* PlayerInputComponent) {
	int playerTankID = 0;
	for (ATank* t: tanks) {
		if (!t->isCOM) {
			//Fire Early Action
			FInputActionBinding fireEarlyBinding = FInputActionBinding(FName(*FString::Printf(TEXT("P%iFireEarly"),playerTankID)), IE_Released);	//declare action binding
			FInputActionHandlerSignature fireEarlySignature;												//create handler which binds to the function
			fireEarlySignature.BindUFunction(this, FName("fireEarly"), t);									//bind it to the action binding
			fireEarlyBinding.ActionDelegate = fireEarlySignature;											//connect the signature and the binding with the delegate
			PlayerInputComponent->AddActionBinding(fireEarlyBinding);										//add the action binding to the inputcomponent

			//move forward axis
			/*FInputAxisBinding moveForwardBinding = FInputAxisBinding(FName(*FString::Printf(TEXT("P%iForward"), playerTankID)));
			FInputAxisHandlerSignature moveForwardSignature;
			moveForwardSignature.BindUFunction(this, FName("MoveTank"), t);
			moveForwardBinding.AxisDelegate = FInputAxisUnifiedDelegate(moveForwardSignature);
			PlayerInputComponent->AxisBindings.Add(moveForwardBinding);*/

			//PlayerInputComponent->BindAxis<FSomeDelegate, AGameManager, ATank*>("P0Forward", this, &AGameManager::MoveTank, t);

			switch (playerTankID) {
				//todo: make this data driven instead of hard coded
				//need to find a way to pass the pointer, in a way similar to above with FireEarly
			case 0:
				PlayerInputComponent->BindAxis("P0Forward", this, &AGameManager::moveTank0);
				PlayerInputComponent->BindAxis("P0Rotate", this, &AGameManager::rotateTank0);
				PlayerInputComponent->BindAxis("P0ChargeShot", this, &AGameManager::chargeTank0);		
				break;
			case 1:
				PlayerInputComponent->BindAxis("P1Forward", this, &AGameManager::moveTank1);
				PlayerInputComponent->BindAxis("P1Rotate", this, &AGameManager::rotateTank1);
				PlayerInputComponent->BindAxis("P1ChargeShot", this, &AGameManager::chargeTank1);
				break;
			default:
				//logs an error if no controls are setup (example: 3 human controlled tanks)
				UE_LOG(LogTemp, Error, TEXT("Unable to set controls for Tank %i, no defined in Input"), playerTankID);
			}
			players.Add(t);
			playerTankID++;
		}
	}
}

/*Calculates the average distance between a set of FVectors
* @param (std::vector<FVector>) &vectors: a vector of FVectors to calculate the average distance
* @return (FVector): FVector representing the average x, y, and z coordinates of the FVectors
*/
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

/*Calculates the average rotation between a set of FRotators
* @param (std::vector<FRotator>) &vectors: a vector of FRotators to calculate the average rotation
* @return (FRotator): FRotator representing the average rotation
*/
FRotator AGameManager::GetAverageRotation(std::vector<FRotator> &rotators) {
	FRotator average = rotators[0];

	for (int i = 1; i < rotators.size(); i++) {
		FRotator r = rotators[i];
		average += r;
	}
	return average;
}

/*Calculates the maximum distance between a set of FVectors
* @param (std::vector<FVector>) &vectors: a vector of FVectors to calculate the maximum distance
* @return (double): the distance between the two FVectors that are furthest apart
*/double AGameManager::MaxDistance(std::vector<FVector> &vectors) {
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

//Signals a tank to fire early
//@param (ATank*) tank: Tank pointer to signal
void AGameManager::fireEarly(ATank * tank)
{
	tank->FireEarly();
}

//Signal a tank to move
//@param (float) amount: amount to move
//@param (ATank*) tank: Tank pointer to signal
void AGameManager::MoveTank(float amount, ATank* tank) {
	tank->MoveForward(amount);
}
//Signal a tank to rotate
//@param (float) amount: amount to rotate
//@param (ATank*) tank: Tank pointer to signal
void AGameManager::RotateTank(float amount, ATank* tank) {
    tank->Rotate(amount);
}
//Signal a tank to charge its shot
//@param (float) amount: amount to charge
//@param (ATank*) tank: Tank pointer to signal
void AGameManager::ChargeTank(float amount, ATank* tank) {
    tank->ChargeShot(amount);
}


//there must be a better way than this
//hard-codes which tank pointer to use, until I can figure out how to send the pointer in the AxisBinding
void AGameManager::moveTank0(float amount) {
    MoveTank(amount,players[0]);
}
void AGameManager::moveTank1(float amount) {
    MoveTank(amount, players[1]);
}
void AGameManager::rotateTank0(float amount) {
    RotateTank(amount, players[0]);
}
void AGameManager::rotateTank1(float amount) {
    RotateTank(amount, players[1]);
}
void AGameManager::chargeTank0(float amount) {
    ChargeTank(amount, players[0]);
}
void AGameManager::chargeTank1(float amount) {
    ChargeTank(amount, players[1]);
}
