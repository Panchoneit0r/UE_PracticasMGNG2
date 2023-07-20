// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyManager.h"

#include "EngineUtils.h"

// Sets default values
AEnemyManager::AEnemyManager() :

	AccumulatedDeltaTime(0.0f), EnemySpawnTimeSeconds(3.0),
	MaxNumberOfEnemies(5)

{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

int AEnemyManager::GetNumberOfEnemies() const
{
	int LivingEnemies=0;
	for(TActorIterator<AActor>ActorItr(GetWorld(),EnemiesC);ActorItr;++ActorItr)
	{
		LivingEnemies++;
	}

	return LivingEnemies;
}

FVector AEnemyManager::GetRandomLocationFromReferencePlane() const
{
	FVector RandomLocation;
	FVector Origin;
	FVector BoundsExtend;

	ReferencePlane->GetActorBounds(false,Origin,BoundsExtend);

	RandomLocation = FMath::RandPointInBox(FBox::BuildAABB(Origin,BoundsExtend));

	return RandomLocation;

	
}

void AEnemyManager::SpawnEnemy()
{
	FVector EnemySpawnLocation = GetRandomLocationFromReferencePlane();
	int randomEnemy = FMath::FRandRange(0, 3);
	
	GetWorld()->SpawnActor(EnemyClass[randomEnemy],&EnemySpawnLocation);
}

// Called when the game starts or when spawned
void AEnemyManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AccumulatedDeltaTime += DeltaTime;
	if((AccumulatedDeltaTime >= EnemySpawnTimeSeconds)&&(GetNumberOfEnemies() < MaxNumberOfEnemies))
	{
		SpawnEnemy();
		AccumulatedDeltaTime = 0.0f;
	}

}





















