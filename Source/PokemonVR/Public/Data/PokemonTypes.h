// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PokemonTypes.generated.h"

/**
 * 
 */


USTRUCT()
struct FPokemonType
{
	GENERATED_BODY()

	UPROPERTY()
	FString type;
	UPROPERTY()
	TArray<FString> superEffective;
	UPROPERTY()
	TArray<FString> notVeryEffective;
	UPROPERTY()
	TArray<FString> noEffect;
};

USTRUCT()
struct FSaveWrapper
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<FPokemonType> types;
};

class POKEMONVR_API PokemonTypes
{
public:
	PokemonTypes();
	~PokemonTypes();
};
