// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSCharacterSpolya.h"
#include "Components/StaticMeshComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
AFPSCharacterSpolya::AFPSCharacterSpolya()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetRelativeLocation(FVector(0.0f, 0.0f, 70.0f));
	Camera->bUsePawnControlRotation = true;
	Camera->SetupAttachment(RootComponent);

	VisibleMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisibleMesh"));
	VisibleMesh->bOwnerNoSee = true;
	VisibleMesh->SetupAttachment(this->GetMesh());
}

// Called when the game starts or when spawned
void AFPSCharacterSpolya::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFPSCharacterSpolya::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFPSCharacterSpolya::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);


	PlayerInputComponent->BindAxis("MoveForward", this, &AFPSCharacterSpolya::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AFPSCharacterSpolya::MoveRight);
	PlayerInputComponent->BindAxis("LookUp", this, &AFPSCharacterSpolya::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookRight", this, &AFPSCharacterSpolya::AddControllerYawInput);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AFPSCharacterSpolya::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AFPSCharacterSpolya::StopJumping);
}

void AFPSCharacterSpolya::MoveForward(float Value)
{
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	AddMovementInput(Direction, Value);
}

void AFPSCharacterSpolya::MoveRight(float Value)
{
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	AddMovementInput(Direction, Value);
}
