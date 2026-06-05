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

UCLASS()
class POKEMONVR_API APokemonBase : public ACharacter
{
	GENERATED_BODY()

public:

	FNatureArray* natureList;

	UINT16 PID;
	bool isShiny;
	EPokemonGender gender;
	//species (pokedex) //Type, Varients, Forms, base stats
	FString nickname;

	int exp;
	UINT8 level; //0-255
	FNature nature;
	//held item
	//ability

	bool isEgg;
	//pokerus

	//met location
	//ball
	FDateTime metDate;
	UINT8 metLevel;

	FString originalTrainer;
	UINT8 friendship; //0-255

	UINT16 hp, atk, def, spa, spd, spe;

	unsigned int hpIV : 5, atkIV : 5, defIV : 5, spaIV : 5, spdIV : 5, speIV : 5; //0-31

	UINT8 hpEV, atkEV, defEV, spaEV, spdEV, speEV; //0-255

	//moves

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
