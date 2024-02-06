#pragma once
#include <iostream>
#include "PokemonTypes.h"
using namespace std;

class Pokemon
{
private:
	string mName;
	string mDescription;
	PokemonTypes mPokemonType;
	string Abilities[4];

	int mLife;
	int mLevel;

	bool inBall;

public:
	Pokemon(string mName, string mDescription, PokemonTypes pokeType);
	Pokemon();
	~Pokemon();

	string getPokemonName();
	string getPokemonDescription();
	PokemonTypes getPokemonType();
	int getLevel();
	int getLife();

	void setAbilities(string newAbility1, string newAbility2, string newAbility3, string newAbility4);

};

