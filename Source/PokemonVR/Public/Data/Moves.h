// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <string>
#include <vector>
#include "Pokedex.h"

/**
 * 
 */

enum MoveCategory
{
	Physical,
	Special,
	Status
};

enum BattleStat
{
	Attack,
	Defense,
	SpecialAttack,
	SpecialDefense,
	Speed,
	Accuracy,
	Evasiveness
};

enum NonVolatileStatus
{
	Burn,
	Freeze,
	Paralysis,
	Poison,
	BadPoison,
	Sleep
};

enum VolatileStatus
{
	Drowsy,
	Confusion,
	InLove
};

struct MoveData
{
	int id;
	int accuracy;
	int basePow;
	MoveCategory category;
	std::string name;
	int pp;
	int priority;
	Type type;
	//other effects
};

class POKEMONVR_API Moves
{
public:
	Moves();
	~Moves();

	bool Flinch(float chance);
	void StatChange(BattleStat stat, int change);
	void OHKO();
	void InflictStatus();
};
