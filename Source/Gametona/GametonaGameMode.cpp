// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "GametonaGameMode.h"
#include "GametonaPlayerController.h"
#include "GametonaCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGametonaGameMode::AGametonaGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AGametonaPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}