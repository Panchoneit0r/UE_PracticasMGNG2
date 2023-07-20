// Copyright Epic Games, Inc. All Rights Reserved.

#include "LaPracticaEpicaGameMode.h"
#include "LaPracticaEpicaCharacter.h"
#include "UObject/ConstructorHelpers.h"

ALaPracticaEpicaGameMode::ALaPracticaEpicaGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
