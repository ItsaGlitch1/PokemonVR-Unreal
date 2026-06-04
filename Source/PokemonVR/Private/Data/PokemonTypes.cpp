// Fill out your copyright notice in the Description page of Project Settings.


#include "Data/PokemonTypes.h"
#include "JsonObjectConverter.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"

PokemonTypes::PokemonTypes()
{
}

PokemonTypes::~PokemonTypes()
{
}

void PokemonTypes::GenerateTypeMatchupJson()
{
	TArray<FPokemonType> types;
	EPokemonType type;

	for (int i = 0; i < 17; ++i)
	{
		type = (EPokemonType)i;
		FPokemonType data;
		switch (type)
		{
		case EPokemonType::Normal:
			data.type = "Normal";
			data.superEffective = { };
			data.notVeryEffective = { "Rock", "Steel" };
			data.noEffect = { "Ghost" };
			break;
		case EPokemonType::Fire:
			data.type = "Fire";
			data.superEffective = { "Grass", "Ice", "Bug", "Steel" };
			data.notVeryEffective = { "Fire", "Water", "Rock", "Dragon" };
			data.noEffect = { };
			break;
		case EPokemonType::Water:
			data.type = "Water";
			data.superEffective = { "Fire", "Ground", "Rock" };
			data.notVeryEffective = { "Water", "Grass", "Dragon" };
			data.noEffect = { };
			break;
		case EPokemonType::Electric:
			data.type = "Electric";
			data.superEffective = { "Water", "Flying" };
			data.notVeryEffective = { "Electric", "Grass", "Dragon" };
			data.noEffect = { "Ground" };
			break;
		case EPokemonType::Grass:
			data.type = "Grass";
			data.superEffective = { "Water", "Ground", "Rock" };
			data.notVeryEffective = { "Fire", "Grass", "Poison", "Flying", "Bug", "Dragon", "Steel" };
			data.noEffect = { };
			break;
		case EPokemonType::Ice:
			data.type = "Ice";
			data.superEffective = { "Grass", "Ground", "Flying", "Dragon" };
			data.notVeryEffective = { "Fire", "Water", "Ice", "Steel" };
			data.noEffect = { };
			break;
		case EPokemonType::Fighting:
			data.type = "Fighting";
			data.superEffective = { "Normal", "Ice", "Rock", "Dark", "Steel" };
			data.notVeryEffective = { "Poison", "Flying", "Psychic", "Bug", "Fairy" };
			data.noEffect = { "Ghost" };
			break;
		case EPokemonType::Poison:
			data.type = "Poison";
			data.superEffective = { "Grass", "Fairy" };
			data.notVeryEffective = { "Poison", "Ground", "Rock", "Ghost" };
			data.noEffect = { "Steel" };
			break;
		case EPokemonType::Ground:
			data.type = "Ground";
			data.superEffective = { "Fire", "Electric", "Poison", "Rock", "Steel" };
			data.notVeryEffective = { "Grass", "Bug" };
			data.noEffect = { "Flying" };
			break;
		case EPokemonType::Flying:
			data.type = "Flying";
			data.superEffective = { "Grass", "Fighting", "Bug" };
			data.notVeryEffective = { "Electric", "Rock", "Steel" };
			data.noEffect = { };
			break;
		case EPokemonType::Psychic:
			data.type = "Psychic";
			data.superEffective = { "Fighting", "Poison" };
			data.notVeryEffective = { "Psychic", "Steel" };
			data.noEffect = { "Dark" };
			break;
		case EPokemonType::Bug:
			data.type = "Bug";
			data.superEffective = { "Grass", "Psychic", "Dark" };
			data.notVeryEffective = { "Fire", "Fighting", "Poison", "Flying", "Ghost", "Steel", "Fairy" };
			data.noEffect = { };
			break;
		case EPokemonType::Rock:
			data.type = "Rock";
			data.superEffective = { "Fire", "Ice", "Flying", "Bug" };
			data.notVeryEffective = { "Fighting", "Ground", "Steel" };
			data.noEffect = { };
			break;
		case EPokemonType::Ghost:
			data.type = "Ghost";
			data.superEffective = { "Psychic", "Ghost" };
			data.notVeryEffective = { "Dark" };
			data.noEffect = { "Normal" };
			break;
		case EPokemonType::Dragon:
			data.type = "Dragon";
			data.superEffective = { "Dragon" };
			data.notVeryEffective = { "Steel" };
			data.noEffect = { "Fairy" };
			break;
		case EPokemonType::Dark:
			data.type = "Dark";
			data.superEffective = { "Psychic", "Ghost" };
			data.notVeryEffective = { "Fighting", "Dark", "Fairy" };
			data.noEffect = { };
			break;
		case EPokemonType::Steel:
			data.type = "Steel";
			data.superEffective = { "Ice", "Rock", "Fairy" };
			data.notVeryEffective = { "Fire", "Water", "Electric", "Steel" };
			data.noEffect = { };
			break;
		case EPokemonType::Fairy:
			data.type = "Fairy";
			data.superEffective = { "Fighting", "Dragon", "Dark"};
			data.notVeryEffective = { "Fire", "Poison", "Steel"};
			data.noEffect = { };
			break;
		}

		types.Add(data);
	}

	FSaveWrapper wrapper;
	wrapper.types = types;

	FString output;
	if (FJsonObjectConverter::UStructToJsonObjectString(wrapper, output)) //gotta convert enum to string or int
	{
		UE_LOG(LogTemp, Warning, TEXT("Converted... %s"), *output);
	}
	else { return; }

	FString path = FPaths::Combine(FPaths::ProjectSavedDir(), TEXT("PokemonTypes.json"));
	if (FFileHelper::SaveStringToFile(output, *path))
	{
		UE_LOG(LogTemp, Warning, TEXT("saved to: %s"), *path);
	}
}
