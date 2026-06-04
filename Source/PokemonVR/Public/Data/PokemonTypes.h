// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PokemonTypes.generated.h"

/**
 * 
 */

UENUM()
enum class EPokemonType
{
	Normal, Fire, Water, Electric, Grass, Ice, Fighting, Poison, Ground, Flying, Psychic, Bug, Rock, Ghost, Dragon, Dark, Steel, Fairy
};

USTRUCT()
struct FPokemonType
{
	GENERATED_BODY()

	FString type;
	TArray<FString> superEffective;
	TArray<FString> notVeryEffective;
	TArray<FString> noEffect;
};

USTRUCT()
struct FSaveWrapper
{
	GENERATED_BODY()

	TArray<FPokemonType> types;
};

class POKEMONVR_API PokemonTypes
{
public:
	PokemonTypes();
	~PokemonTypes();

	static void GenerateTypeMatchupJson();
};
