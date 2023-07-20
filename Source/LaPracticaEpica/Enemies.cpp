// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemies.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

#include "LaPracticaEpicaProjectile.h"


// Sets default values
AEnemies::AEnemies()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AEnemies::BeginPlay()
{
	Super::BeginPlay();
}

void AEnemies::ShootProjectile(FTransform Spawn)
{
	if (ProjectileClass)
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;
		GetWorld()->SpawnActor<ALaPracticaEpicaProjectile>(ProjectileClass, Spawn.GetLocation(), Spawn.Rotator(), SpawnParams);
	}
}

// Called every frame
void AEnemies::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);
	if (PlayerController)
	{
		FRotator LookAtRotation = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), PlayerController->GetPawn()->GetActorLocation());
		FRotator NewRotation = FMath::RInterpTo(GetActorRotation(), LookAtRotation, DeltaTime, RotationSpeed);
		SetActorRotation(NewRotation);
	}
	
}


