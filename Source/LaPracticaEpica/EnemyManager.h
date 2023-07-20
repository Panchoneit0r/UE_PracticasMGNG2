// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemies.h"
#include "GameFramework/Actor.h"
#include "EnemyManager.generated.h"

UCLASS()
class LAPRACTICAEPICA_API AEnemyManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemyManager();
	
private:
	float AccumulatedDeltaTime;
	float EnemySpawnTimeSeconds;
	int MaxNumberOfEnemies;
	
	int GetNumberOfEnemies() const;
	
	FVector GetRandomLocationFromReferencePlane() const;
	
	void SpawnEnemy();
	
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Spawner")
	TWeakObjectPtr<AActor> ReferencePlane;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Spawner")
	TArray<TSubclassOf<AActor>> EnemyClass;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Spawner")
	TSubclassOf<AEnemies> EnemiesC;

};
