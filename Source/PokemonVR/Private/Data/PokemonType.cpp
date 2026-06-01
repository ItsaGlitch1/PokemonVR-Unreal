// Fill out your copyright notice in the Description page of Project Settings.


#include "Data/PokemonType.h"

PokemonType::PokemonType()
{

}

PokemonType::~PokemonType()
{
}

float PokemonType::GetEffective(TypeName pkmType)
{
	return 0.0f;
}

float PokemonType::Matchup(TypeName atk, TypeName def)
{
	switch (atk)
	{
	case Normal:
		superEffective = {None};
		notVeryEffective = {Rock, Steel};
		noEffect = {Ghost};
		break;
	case Fire:
		superEffective = {Grass, Ice, Bug, Steel};
		notVeryEffective = {Fire, Water, Rock, Dragon};
		noEffect = {None};
		break;
	case Water:
		superEffective = {Fire, Ground, Rock};
		notVeryEffective = {Water, Grass, Dragon};
		noEffect = {None};
		break;
	case Electric:
		superEffective = {Water, Flying};
		notVeryEffective = {Electric, Grass, Dragon};
		noEffect = {Ground};
		break;
	case Grass:
		superEffective = {Water, Ground, Rock};
		notVeryEffective = {Fire, Grass, Poison, Flying, Bug, Dragon, Steel};
		noEffect = {None};
		break;
	case Ice:
		superEffective = {Grass, Ground, Flying, Dragon};
		notVeryEffective = {Fire, Water, Ice, Steel};
		noEffect = {None};
		break;
	case Fighting:
		superEffective = {Normal, Ice, Rock, Dark, Steel};
		notVeryEffective = {Poison, Flying, Psychic, Bug, Fairy};
		noEffect = {Ghost};
		break;
	case Poison:
		superEffective = {Grass, Fairy};
		notVeryEffective = {Poison, Ground, Rock, Ghost};
		noEffect = {Steel};
		break;
	case Ground:
		superEffective = {Fire, Electric, Poison, Rock, Steel};
		notVeryEffective = {Grass, Bug};
		noEffect = {Flying};
		break;
	case Flying:
		superEffective = {Grass, Fighting, Bug};
		notVeryEffective = {Electric, Rock, Steel};
		noEffect = {None};
		break;
	case Psychic:
		superEffective = {Fighting, Poison};
		notVeryEffective = {Psychic, Steel};
		noEffect = {Dark};
		break;
	case Bug:
		superEffective = {Grass, Psychic, Dark};
		notVeryEffective = {Fire, Fighting, Poison, Flying, Ghost, Steel, Fairy};
		noEffect = {None};
		break;
	case Rock:
		superEffective = {Fire, Ice, Flying, Bug};
		notVeryEffective = {Fighting, Ground, Steel};
		noEffect = {None};
		break;
	case Ghost:
		superEffective = {Psychic, Ghost};
		notVeryEffective = {Dark};
		noEffect = {Normal};
		break;
	case Dragon:
		superEffective = {Dragon};
		notVeryEffective = {Steel};
		noEffect = {Fairy};
		break;
	case Dark:
		superEffective = {Psychic, Ghost};
		notVeryEffective = {Fighting, Dark, Fairy};
		noEffect = {None};
		break;
	case Steel:
		superEffective = {Ice, Rock, Fairy};
		notVeryEffective = {Fire, Water, Electric, Steel};
		noEffect = {None};
		break;
	case Fairy:
		superEffective = {Fighting, Dragon, Dark};
		notVeryEffective = {Fire, Poison, Steel};
		noEffect = {None};
		break;
	}
	
	for (int i = 0; i < superEffective.size(); ++i)
	{
		if (def == superEffective[i]) return 2;
	}

	for (int i = 0; i < notVeryEffective.size(); ++i)
	{
		if (def == notVeryEffective[i]) return 0.5f;
	}

	for (int i = 0; i < noEffect.size(); ++i)
	{
		if (def == noEffect[i]) return 0;
	}

	return 1;
}


