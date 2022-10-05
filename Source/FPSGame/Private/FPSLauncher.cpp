// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSLauncher.h"

void AFPSLauncher::OnLaunchPadOverlap(UPrimitiveComponent* PrimitiveComponent, AActor* Actor,
	UPrimitiveComponent* PrimitiveComponent1, int I, bool bArg, const FHitResult& HitResult)
{
	//TODO: REMOVE_SCREEN_DEBUG_MESSAGE
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Overlap working"));
	}	
}

// Sets default values
AFPSLauncher::AFPSLauncher()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	LaunchPad = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LaunchPad"));
	LaunchPad->SetupAttachment(RootComponent); 
	LaunchPadArrow = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LaunchPadArrow"));
	LaunchPadArrow->SetupAttachment(RootComponent);
	BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollider"));
	BoxCollider->SetBoxExtent(FVector(1000));
	BoxCollider->OnComponentBeginOverlap.AddDynamic(this, &AFPSLauncher::OnLaunchPadOverlap); 
	BoxCollider->SetupAttachment(RootComponent);
	
}

void AFPSLauncher::BeginPlay()
{
	Super::BeginPlay();

}


 
