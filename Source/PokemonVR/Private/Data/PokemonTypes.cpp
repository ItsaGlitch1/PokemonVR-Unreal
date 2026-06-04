// Fill out your copyright notice in the Description page of Project Settings.


#include "Data/PokemonTypes.h"
#include "JsonObjectConverter.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"

PokemonTypes::PokemonTypes()
{
	list = new FPokemonTypeArray();
	ReadTypes();
}

PokemonTypes::~PokemonTypes()
{
	delete list;
}

void PokemonTypes::ReadTypes()
{
	FString path = FPaths::Combine(FPaths::GameSourceDir(), "PokemonVR", "Public", "Data", "PokemonTypes.json");

	FString input;

	IPlatformFile& FileMan = FPlatformFileManager::Get().GetPlatformFile();
	if (!FileMan.FileExists(*path))
	{
		UE_LOG(LogTemp, Error, TEXT("Can't find types at %s"), *path);
		return;
	}

	if (!FFileHelper::LoadFileToString(input, *path))
	{
		UE_LOG(LogTemp, Error, TEXT("unable to read pokemon types file"));
	}

	if (FJsonObjectConverter::JsonObjectStringToUStruct(input, list, 0, 0))
	{
		UE_LOG(LogTemp, Log, TEXT("loaded pokemon types"));
	}
}

float PokemonTypes::GetTypeMatchup(FString attackType, FString defenderType)
{
	FPokemonType type;

	for (int i = 0; i < list->types.Num(); ++i)
	{
		if (list->types[i].type.Contains(attackType))
		{
			type = list->types[i];
			break;
		}
	}
	if (type.superEffective.Contains(defenderType)) { return 2; }
	if (type.notVeryEffective.Contains(defenderType)) { return 0.5f; }
	if (type.noEffect.Contains(defenderType)) { return 0; }
	return 1;
}


