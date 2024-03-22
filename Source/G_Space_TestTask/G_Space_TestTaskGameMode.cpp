// Copyright Epic Games, Inc. All Rights Reserved.

#include "G_Space_TestTaskGameMode.h"
#include "G_Space_TestTaskCharacter.h"
#include "UObject/ConstructorHelpers.h"

AG_Space_TestTaskGameMode::AG_Space_TestTaskGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
