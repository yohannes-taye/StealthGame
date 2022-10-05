// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "FPSBlackHole.generated.h"

UCLASS()
class FPSGAME_API AFPSBlackHole : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AFPSBlackHole();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	UPROPERTY(EditDefaultsOnly, Category="Components")
	UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(EditDefaultsOnly, Category="Components")
	USphereComponent* SphereComponentGravity;

	UPROPERTY(EditDefaultsOnly, Category="Components")
	USphereComponent* SphereComponentBlackHole;

	UPROPERTY(EditAnywhere, Category="Fun")
	AFPSBlackHole* TeleportPoint; 
	
	UFUNCTION()
	void OnInnerSphereOverLap(UPrimitiveComponent* PrimitiveComponent, AActor* Actor, UPrimitiveComponent* PrimitiveComponent1, int I, bool bArg, const FHitResult& HitResult);
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category="Fx")
	float Force = -2000; 

	UPROPERTY(EditAnywhere, Category="Fx")
	float GravitySphereRadius = 33000;

	UPROPERTY(EditAnywhere, Category="Fx")
	float BlackHoleSphereRadius = 100;

	UPROPERTY(EditAnywhere, Category="FX")
	float PushBackRadius = 3000.0f;

	UPROPERTY(EditAnywhere, Category="FX")
	float PushBackForce = 3000.0f;
};
