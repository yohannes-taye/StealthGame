// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "FPSGameMode.h"
#include "FPSHUD.h"
#include "FPSCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"

AFPSGameMode::AFPSGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Blueprints/BP_Player"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AFPSHUD::StaticClass();
}

void AFPSGameMode::CompleteMission(APawn* InstigatorPawn)
{
	if(InstigatorPawn)
	{
		InstigatorPawn->DisableInput(nullptr);
	}

	TArray<AActor*> ActorQueryResults;
	if(SpectatingViewPoint)
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), SpectatingViewPoint, ActorQueryResults);
	AActor* ViewTarget; 
	if(ActorQueryResults.Num() != 0)
	{
		ViewTarget = ActorQueryResults.Top();
		APlayerController* PlayerController = Cast<APlayerController>(InstigatorPawn->GetController());
		if(PlayerController)
		{
			PlayerController->SetViewTargetWithBlend(ViewTarget,0.5f, EViewTargetBlendFunction::VTBlend_Cubic); 
		}
	}
	
	OnMissionComplete(InstigatorPawn); 
}

