// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <vector>

/**
 * 
 */

enum TypeName
{
	None,
	Normal,
	Fire,
	Water,
	Electric,
	Grass,
	Ice,
	Fighting,
	Poison,
	Ground,
	Flying,
	Psychic,
	Bug,
	Rock,
	Ghost,
	Dragon,
	Dark,
	Steel,
	Fairy
};

class POKEMONVR_API PokemonType
{
public:
	

	PokemonType();
	~PokemonType();

	float GetEffective(TypeName pkmType);

	float Matchup(TypeName attacker, TypeName defender);

private:
	std::vector<TypeName> superEffective;
	std::vector<TypeName> notVeryEffective;
	std::vector<TypeName> noEffect;
};
