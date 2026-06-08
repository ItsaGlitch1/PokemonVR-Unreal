// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "../Data/PokemonTypes.h"
#include "PokemonBase.generated.h"


UENUM()
enum class EPokemonGender
{
	Unknown, Male, Female
};

UENUM()
enum class EPokerus
{
	None, Infected, Cured
};

USTRUCT()
struct FNature
{
	GENERATED_BODY()

	UPROPERTY()
	FString name;

	UPROPERTY()
	FString plus;

	UPROPERTY()
	FString minus;

	void SetNature(FString _name, FString _plus, FString _minus)
	{
		name = _name;
		plus = _plus;
		minus = _minus;
	}
};

USTRUCT()
struct FNatureArray
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<FNature> nature;
};

USTRUCT()
struct FPokemonStats
{
	GENERATED_BODY()
	UPROPERTY()
	unsigned int hp;
	UPROPERTY()
	unsigned int atk;
	UPROPERTY()
	unsigned int def;
	UPROPERTY()
	unsigned int spa;
	UPROPERTY()
	unsigned int spd;
	UPROPERTY()
	unsigned int spe;
};


USTRUCT()
struct FPokemon
{
	GENERATED_BODY()

	UPROPERTY()
	unsigned int PID;

	UPROPERTY()
	bool isShiny;

	UPROPERTY()
	EPokemonGender gender;

	//species (pokedex) //Type, Varients, Forms, base stats

	UPROPERTY()
	FString nickname;

	UPROPERTY()
	int exp;

	UPROPERTY()
	unsigned int level; //0-255

	UPROPERTY()
	FNature nature;

	//held item

	//ability

	UPROPERTY()
	bool isEgg;

	UPROPERTY()
	EPokerus pokerus;

	//met location

	//ball

	UPROPERTY()
	FDateTime metDate;

	UPROPERTY()
	unsigned int metLevel;

	UPROPERTY()
	FString originalTrainer;

	UPROPERTY()
	unsigned int friendship; //0-255

	UPROPERTY()
	FPokemonStats stats;

	UPROPERTY()
	FPokemonStats ivs; //0-31

	UPROPERTY()
	FPokemonStats evs; //0-255

	//moves
};

UCLASS()
class POKEMONVR_API APokemonBase : public ACharacter
{
	GENERATED_BODY()

public:

	FNatureArray* natureList;

	

	// Sets default values for this character's properties
	APokemonBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void ReadNatures();
};
