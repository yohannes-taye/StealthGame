// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "FPSObjectiveActor.generated.h"

UCLASS()
class FPSGAME_API AFPSObjectiveActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFPSObjectiveActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void PlayEffects(); 
	UPROPERTY(VisibleAnywhere, Category="Components")
	UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(VisibleAnywhere, Category="Components")
	USphereComponent* SphereComponent;

	UPROPERTY(EditDefaultsOnly,Category="FX")
	UParticleSystem* PickupFx;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
};
