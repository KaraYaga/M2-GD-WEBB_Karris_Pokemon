#pragma once
#include <iostream>
#include "PokemonTypes.h"
#include "Abilities.h"
using namespace std;

class Pokemon
{
private:
	string mName;
	string mDescription;
	PokemonTypes mPokemonType;
	Ability mAbility[4];

	int mLife;
	int mLevel;

	bool inBall;

public:
	Pokemon(string mName, string mDescription, PokemonTypes pokeType); //CUSTOM
	Pokemon(string mName, string mDescription, PokemonTypes pokeType, int mLife, int mLevel); //DEFAULT
	Pokemon(); //TRAINER
	~Pokemon();

	string getPokemonName();
	string getPokemonDescription();
	PokemonTypes getPokemonType();
	int getLevel();
	int getLife();

	void chooseAbilities();
	void DisplayAbilities();

};

