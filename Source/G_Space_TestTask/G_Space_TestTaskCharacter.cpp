// Copyright Epic Games, Inc. All Rights Reserved.

#include "G_Space_TestTaskCharacter.h"
#include "GameFramework/PlayerController.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/TT_InventoryComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "Engine/LocalPlayer.h"
#include "UI/InventoryWD/TT_InventoryWD.h"


DEFINE_LOG_CATEGORY(LogTemplateCharacter);

//////////////////////////////////////////////////////////////////////////
// AG_Space_TestTaskCharacter

AG_Space_TestTaskCharacter::AG_Space_TestTaskCharacter()
{
	// Character doesnt have a rifle at start
	bHasRifle = false;
	
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);
		
	// Create a CameraComponent	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->SetRelativeLocation(FVector(-10.f, 0.f, 60.f)); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	// Create a InventoryComponent	
	InventoryComponent = CreateDefaultSubobject<UTT_InventoryComponent>(TEXT("InventoryComponent"));
	

	// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh1P"));
	Mesh1P->SetOnlyOwnerSee(true);
	Mesh1P->SetupAttachment(FirstPersonCameraComponent);
	Mesh1P->bCastDynamicShadow = false;
	Mesh1P->CastShadow = false;
	Mesh1P->SetRelativeLocation(FVector(-30.f, 0.f, -150.f));

}

void AG_Space_TestTaskCharacter::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	// Add Input Mapping Context
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}

}

//////////////////////////////////////////////////////////////////////////// Input

void AG_Space_TestTaskCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AG_Space_TestTaskCharacter::Move);

		// Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AG_Space_TestTaskCharacter::Look);
	}
	else
	{
		UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' Failed to find an Enhanced Input Component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}


void AG_Space_TestTaskCharacter::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add movement 
		AddMovementInput(GetActorForwardVector(), MovementVector.Y);
		AddMovementInput(GetActorRightVector(), MovementVector.X);
	}
}

void AG_Space_TestTaskCharacter::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void AG_Space_TestTaskCharacter::OpenInventory()
{
	if(IsValid(InventoryWD))
	{
		InventoryWD->SetVisibility(ESlateVisibility::Visible);
	}
	else
	{
		if( !InventoryWDClass.IsNull())
		{
			InventoryWD = CreateWidget<UTT_InventoryWD>(GetWorld(), InventoryWDClass.LoadSynchronous());
			if( IsValid(InventoryWD) )
			{
				InventoryWD->InitializeInventoryWD(InventoryComponent);
				InventoryWD->AddToViewport();
				APlayerController* LPlayerController = Cast<APlayerController>(GetController());

				LPlayerController->SetShowMouseCursor(true);
				FInputModeUIOnly LNewUIOnlyInput;
				LNewUIOnlyInput.SetWidgetToFocus(InventoryWD->TakeWidget());
				LPlayerController->SetInputMode(LNewUIOnlyInput);
			}
			
		}
	}
}

void AG_Space_TestTaskCharacter::CloseInventory()
{
	if(IsValid(InventoryWD))
	{
		InventoryWD->SetVisibility(ESlateVisibility::Collapsed);
	}

	APlayerController* LPlayerController = Cast<APlayerController>(GetController());

	LPlayerController->SetShowMouseCursor(false);
	const FInputModeGameOnly LNewGameOnlyInput;
	LPlayerController->SetInputMode(LNewGameOnlyInput);
}
