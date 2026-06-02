// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include <map>
#include <string>
#include <Data/Pokedex.h>
#include "PokemonBase.generated.h"


UCLASS()
class POKEMONVR_API APokemonBase : public ACharacter
{
	GENERATED_BODY()

public:

	int pokedex;

	int hp, atk, def, spa, spd, spe;

	Type type1, type2;

	int catchrate;

	int exp;

	//growth rate

	//moves

	//std::vector<moves> learnset

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

	
};
