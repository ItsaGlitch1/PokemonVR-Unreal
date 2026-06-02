// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <vector>
#include "Pokedex.h"

/**
 * 
 */



class POKEMONVR_API PokemonType
{
public:
	

	PokemonType();
	~PokemonType();

	float GetEffective(Type pkmType);

	float Matchup(Type attacker, Type defender);

private:
	std::vector<Type> superEffective;
	std::vector<Type> notVeryEffective;
	std::vector<Type> noEffect;
};
