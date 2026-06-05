// Fill out your copyright notice in the Description page of Project Settings.


#include "Pokemon/PokemonBase.h"
#include "JsonObjectConverter.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"

// Sets default values
APokemonBase::APokemonBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	

}

// Called when the game starts or when spawned
void APokemonBase::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APokemonBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APokemonBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APokemonBase::ReadNatures()
{
	FString path = FPaths::Combine(FPaths::GameSourceDir(), "PokemonVR", "Public", "Data", "PokemonNatures.json");

	FString input;

	IPlatformFile& FileMan = FPlatformFileManager::Get().GetPlatformFile();
	if (!FileMan.FileExists(*path))
	{
		UE_LOG(LogTemp, Error, TEXT("Can't find natures at %s"), *path);
		return;
	}

	if (!FFileHelper::LoadFileToString(input, *path))
	{
		UE_LOG(LogTemp, Error, TEXT("unable to read pokemon natures file"));
	}

	if (FJsonObjectConverter::JsonObjectStringToUStruct(input, natureList, 0, 0))
	{
		UE_LOG(LogTemp, Log, TEXT("loaded pokemon natures"));
	}
}

