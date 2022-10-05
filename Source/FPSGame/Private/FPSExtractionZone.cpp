// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSExtractionZone.h"

#include "FPSCharacter.h"
#include "FPSGameMode.h"
#include "Components/DecalComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AFPSExtractionZone::AFPSExtractionZone()
{

	OverlapComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	OverlapComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	OverlapComponent->SetCollisionResponseToChannels(ECR_Ignore);
	OverlapComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	OverlapComponent->SetBoxExtent(FVector(200.0f));
	OverlapComponent->SetHiddenInGame(false);
	RootComponent = OverlapComponent;

	OverlapComponent->OnComponentBeginOverlap.AddDynamic(this, &AFPSExtractionZone::OnOverlap);


	DecalComponent = CreateDefaultSubobject<UDecalComponent>(TEXT("DecalComponent"));
	DecalComponent->DecalSize = FVector(200.0f);
	DecalComponent->SetupAttachment(RootComponent); 
	
}

void AFPSExtractionZone::OnOverlap(UPrimitiveComponent* PrimitiveComponent, AActor* Actor,
	UPrimitiveComponent* PrimitiveComponent1, int I, bool bArg, const FHitResult& HitResult)
{

	AFPSCharacter* MyPawn = Cast<AFPSCharacter>(Actor);
	if(MyPawn == nullptr)
		return; 
	if(MyPawn->bIsCaryingObjective)
	{
		AFPSGameMode* GM = Cast<AFPSGameMode>(GetWorld()->GetAuthGameMode());
		if(GM)
		{
		 
			GM->CompleteMission(MyPawn); 
		}
	}
	else
	{
		UGameplayStatics::PlaySound2D(GetWorld(), ObjectieveNotPickedUpSound); 
	}
}

