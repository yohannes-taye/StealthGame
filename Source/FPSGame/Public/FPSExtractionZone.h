// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "FPSExtractionZone.generated.h"

UCLASS()
class FPSGAME_API AFPSExtractionZone : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AFPSExtractionZone();

	UPROPERTY(EditDefaultsOnly, Category="FX")
	USoundBase* ObjectieveNotPickedUpSound; 

protected:

	UPROPERTY(EditDefaultsOnly, Category="Component")
	UBoxComponent* OverlapComponent;

	UPROPERTY(EditDefaultsOnly, Category="Component")
	UDecalComponent* DecalComponent; 
	
	UFUNCTION()
	void OnOverlap(UPrimitiveComponent* PrimitiveComponent, AActor* Actor, UPrimitiveComponent* PrimitiveComponent1, int I, bool bArg, const FHitResult& HitResult);
};
