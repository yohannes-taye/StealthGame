// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSBlackHole.h"

void AFPSBlackHole::OnInnerSphereOverLap(UPrimitiveComponent* PrimitiveComponent, AActor* Actor,
	UPrimitiveComponent* PrimitiveComponent1, int I, bool bArg, const FHitResult& HitResult)
{
	
	if(Actor)
	{
		if(TeleportPoint)
		{
			Actor->SetActorTransform(TeleportPoint->GetTransform());
			if(GEngine)
				GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("Collision with black hole detected"));
			
		}
		// else
		// {
		// 	Actor->Destroy(); 
		// }
	}
}

// Sets default values
AFPSBlackHole::AFPSBlackHole()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	StaticMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision); 
	RootComponent = StaticMeshComponent;
	
	
	SphereComponentGravity = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponentGravity"));
	SphereComponentGravity->SetSphereRadius(GravitySphereRadius);
	SphereComponentGravity->SetupAttachment(RootComponent);

	SphereComponentBlackHole = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponentBlackHole"));
	SphereComponentBlackHole->SetSphereRadius(300);

	SphereComponentBlackHole->OnComponentBeginOverlap.AddDynamic(this, &AFPSBlackHole::OnInnerSphereOverLap);
	SphereComponentBlackHole->SetupAttachment(RootComponent);


	// if(GEngine)
	// {
	// 	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("Is it called during initaliziation?")); 
	// }
	
}

// Called when the game starts or when spawned
void AFPSBlackHole::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFPSBlackHole::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
		
	TArray<UPrimitiveComponent*> OverlappingComponents;
	SphereComponentGravity->GetOverlappingComponents(OverlappingComponents);
	// if(GEngine)
	// 	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("Number of overlapping components: %lld"), OverlappingComponents.Num()));
	for(int i =0; i < OverlappingComponents.Num(); i++)
	{
		
		if(OverlappingComponents[i] && OverlappingComponents[i]->IsSimulatingPhysics())
		{
			const float Radius = SphereComponentGravity->GetScaledSphereRadius();
			OverlappingComponents[i]->AddRadialForce(GetActorLocation(), Radius, Force, ERadialImpulseFalloff::RIF_Constant, true);		
			
		}
	}
}

