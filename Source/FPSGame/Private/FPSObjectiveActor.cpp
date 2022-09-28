// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSObjectiveActor.h"

#include "Kismet/GameplayStatics.h"

// Sets default values
AFPSObjectiveActor::AFPSObjectiveActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	RootComponent = StaticMeshComponent;
	StaticMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	
	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent")) ;
	SphereComponent->SetupAttachment(RootComponent);
	SphereComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	SphereComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	SphereComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn,ECollisionResponse::ECR_Overlap);
}

// Called when the game starts or when spawned
void AFPSObjectiveActor::BeginPlay()
{
	Super::BeginPlay();
	PlayEffects();
}

void AFPSObjectiveActor::PlayEffects()
{
	if(PickupFx)
	{
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), PickupFx, GetActorLocation());
	}
}

// Called every frame
void AFPSObjectiveActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AFPSObjectiveActor::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
}

