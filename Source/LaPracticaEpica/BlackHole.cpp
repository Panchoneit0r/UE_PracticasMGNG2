// Fill out your copyright notice in the Description page of Project Settings.


#include "BlackHole.h"



// Sets default values
ABlackHole::ABlackHole()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Mesh
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComo"));
	MeshComp -> SetCollisionEnabled(ECollisionEnabled::NoCollision);
	RootComponent = MeshComp;

	//Sphere
	SphereCompDestroy = CreateDefaultSubobject<USphereComponent>(TEXT("DestroySphereComp"));
	SphereCompDestroy -> SetSphereRadius(100);
	SphereCompDestroy ->SetupAttachment(MeshComp);

	//Bind Function with OnComponentBegingOverlap
	SphereCompDestroy->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OverlapDestroySphere);

	SphereCompAttract = CreateDefaultSubobject<USphereComponent>(TEXT("AttractSphereComp"));
	SphereCompAttract -> SetSphereRadius(4000);
	SphereCompAttract ->SetupAttachment(MeshComp);

}

void ABlackHole::OverlapDestroySphere(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(OtherActor)
	{
		OtherActor->Destroy();
	}
}

// Called when the game starts or when spawned
void ABlackHole::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABlackHole::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TArray<UPrimitiveComponent*> OverlappingComps;
	SphereCompAttract->GetOverlappingComponents(OverlappingComps);

	for (int i = 0; i<OverlappingComps.Num(); i++)
	{
		UPrimitiveComponent* PrimComp = OverlappingComps[i];

		if(PrimComp && PrimComp->IsSimulatingPhysics())
		{
			const float SphereRadius = SphereCompAttract->GetScaledSphereRadius();
			const float ForceStrength = -2000;

			PrimComp ->AddRadialForce(GetActorLocation(), SphereRadius,ForceStrength,RIF_Constant,true);
		}
	}

}

