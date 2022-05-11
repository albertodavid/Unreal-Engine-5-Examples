// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Hero.generated.h"

/**
 * 
 */
UCLASS()
class ARROW_API AHero : public ABasePawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AHero();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	UPROPERTY(EditAnywhere)
	class USpringArmComponent* SpringArm;

	//Missed a Camera, add it in the blueprint
		
	UPROPERTY(EditAnywhere)
	float Speed;

	UFUNCTION()
	void MoveHeroForward(float Value);
	
	UFUNCTION()
	void MoveHeroLateral(float Value);

	UFUNCTION()
	void HeroRotation(float Value);
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};






