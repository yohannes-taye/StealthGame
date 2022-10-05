// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "FPSLauncher.generated.h"

UCLASS()
class FPSGAME_API AFPSLauncher : public AActor
{
	GENERATED_BODY()
	
public:
	UFUNCTION()
	void OnLaunchPadOverlap(UPrimitiveComponent* PrimitiveComponent, AActor* Actor, UPrimitiveComponent* PrimitiveComponent1, int I, bool bArg, const FHitResult& HitResult);
	// Sets default values for this actor's properties
	AFPSLauncher();
protected:
	virtual void BeginPlay() override;
public:
	UPROPERTY(EditDefaultsOnly, Category="Components")
	UStaticMeshComponent* LaunchPad;

	UPROPERTY(EditDefaultsOnly, Category="Components")
	UStaticMeshComponent* LaunchPadArrow;

	UPROPERTY(EditDefaultsOnly, Category="Components")
	UBoxComponent* BoxCollider; 

};
