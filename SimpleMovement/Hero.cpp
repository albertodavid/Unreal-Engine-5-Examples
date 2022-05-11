/*Made by twitter: @Scthch / github: @albertodavid*/

#include "Hero.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/SpringArmComponent.h"

AHero::AHero()
{
	//We have to also add a Camera
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
}

void AHero::BeginPlay()
{
	Super::BeginPlay();
}

void AHero::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AHero::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//We bind the Axis (projectSettings->input) to the movement functions

	PlayerInputComponent->BindAxis(TEXT("Forward"), this, &AHero::MoveHeroForward);
	PlayerInputComponent->BindAxis(TEXT("Lateral"), this, &AHero::MoveHeroLateral);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &AHero::HeroRotation);
}

void AHero::MoveHeroForward(float Value)
{

	//UE_LOG(LogTemp, Warning, TEXT("%f"), Value);
	
	FVector DeltaSpace = FVector(0,0,0);
	DeltaSpace.X = Value * Speed *  UGameplayStatics::GetWorldDeltaSeconds(this);

	AddActorLocalOffset(DeltaSpace);
}

void AHero::MoveHeroLateral(float Value)
{
	//UE_LOG(LogTemp, Warning, TEXT("%f"), Value);
	
	FVector DeltaSpace = FVector(0,0,0);
	DeltaSpace.Y = Value * Speed *  UGameplayStatics::GetWorldDeltaSeconds(this);

	AddActorLocalOffset(DeltaSpace);
	
}
void AHero::HeroRotation(float Value)
{
	//UE_LOG(LogTemp, Warning, TEXT("%f"), Value);

	FRotator DeltaRotation = FRotator(0,0,0);

	DeltaRotation.Yaw = 100 * Value * UGameplayStatics::GetWorldDeltaSeconds(this),

	AddActorLocalRotation(DeltaRotation);
}
