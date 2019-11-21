// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "sidescrolling_actionCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include <EngineGlobals.h>
#include <Runtime/Engine/Classes/Engine/Engine.h>
#include <GameFramework/Actor.h>
#include "GameFramework/Actor.h"
#include "GenericPlatform/GenericPlatformProcess.h"
#include "Engine/World.h"
#include "Runtime/Engine/Classes/Components/ActorComponent.h"


//allows me to use print() for debuging
#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Red, TEXT(text))

Asidescrolling_actionCharacter::Asidescrolling_actionCharacter()
{

	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate when the controller rotates.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Create a camera boom attached to the root (capsule)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->bAbsoluteRotation = true; // Rotation of the character should not affect rotation of boom
	CameraBoom->bDoCollisionTest = false;
	CameraBoom->TargetArmLength = 750.f;
	CameraBoom->SocketOffset = FVector(0.f,0.f,75.f);
	CameraBoom->RelativeRotation = FRotator(0.f,180.f,0.f);

	// Create a camera and attach to boom
	SideViewCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("SideViewCamera"));
	SideViewCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	SideViewCameraComponent->bUsePawnControlRotation = false; // We don't want the controller rotating the camera

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Face in the direction we are moving..
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->GravityScale = 2.f;
	GetCharacterMovement()->AirControl = 0.80f;
	GetCharacterMovement()->JumpZVelocity = 750.f;
	GetCharacterMovement()->GroundFriction = 3.f;
	GetCharacterMovement()->MaxWalkSpeed = 600.f;
	GetCharacterMovement()->MaxFlySpeed = 600.f;

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)
}

//////////////////////////////////////////////////////////////////////////
// Input

void Asidescrolling_actionCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// 
	/* basic ue4 jump settings *turned off*.
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	*/

	PlayerInputComponent->BindAxis("MoveRight", this, &Asidescrolling_actionCharacter::MoveRight);
	PlayerInputComponent->BindTouch(IE_Released, this, &Asidescrolling_actionCharacter::TouchStopped);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &Asidescrolling_actionCharacter::doublejump);
	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &Asidescrolling_actionCharacter::sprinton);
	PlayerInputComponent->BindAction("Sprint", IE_Released, this, &Asidescrolling_actionCharacter::sprintoff);
}

//look mechanic
void Asidescrolling_actionCharacter::MoveRight(float Value)
{
	// add movement in that direction
	AddMovementInput(FVector(0.f,-1.f,0.f), Value);
}

//srpint mechanic
void Asidescrolling_actionCharacter::sprinton()
{
	//on shift press, increase walk speed.
	if (GetCharacterMovement()->IsWalking() == true)
	{
		GetCharacterMovement()->MaxWalkSpeed = 1200.f;
	}
}

void Asidescrolling_actionCharacter::sprintoff()
{
	//on shift release decrease max walk speed
	GetCharacterMovement()->MaxWalkSpeed = 600.f;
}

//doublejump bool initialization
bool allowdoublejump = NULL;

void Asidescrolling_actionCharacter::doublejump()
{
	//if on the ground, allow jump()
	if (GetCharacterMovement()->IsWalking() == true)
	{
		Jump();
		allowdoublejump = true;
	}
	//if off the ground and double jump bool conditions are met, allow a second impulse which acts as a second jump
	if (GetCharacterMovement()->IsWalking() == false && allowdoublejump == true)
	{
		GetCharacterMovement()->AddImpulse(GetCapsuleComponent()->GetUpVector() * 1000, true);
		allowdoublejump = false;
	}
}


//beinplay
void Asidescrolling_actionCharacter::BeginPlay()
{
	Super::BeginPlay();

/* TIMER
	GetWorld()->GetTimerManager().SetTimer(_loopTimerHandle, this, &Asidescrolling_actionCharacter::onTimerEnd, 2.f, false);
*/
}

void Asidescrolling_actionCharacter::attack()
{

}

//ue4 function to get jump end
void Asidescrolling_actionCharacter::TouchStopped(const ETouchIndex::Type FingerIndex, const FVector Location)
{	
	StopJumping();
}


//eventick
void Asidescrolling_actionCharacter::Tick(float a) {

}


//timer ending function.
int Asidescrolling_actionCharacter::onTimerEnd()
{
	return NULL;
}
