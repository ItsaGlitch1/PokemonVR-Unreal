// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <string>
#include <vector>

/**
 * 
 */

enum Type
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

enum Color
{
	Red,
	Blue,
	Yellow,
	Green,
	Black,
	Brown,
	Purple,
	Gray,
	White,
	Pink
};

enum EggGroup
{
	Monster,
	Fairy,
	HumanLike,
	Field,
	Flying,
	Dragon,
	Bug,
	Water1,
	Water2,
	Water3,
	Grass,
	Amorphous,
	Mineral
};

struct Pokemon
{
	int id;
	std::string name;
	Type types[2];
	//genderRatio
	int hp, atk, def, spa, spd, spe; //base stats
	//abilities
	float height; //meters
	float weight; //kilograms
	Color color;
	std::vector<Pokemon> evos;
	std::vector<EggGroup> eggGroups;
};

class POKEMONVR_API Pokedex
{
public:
	Pokedex();
	~Pokedex();
};
