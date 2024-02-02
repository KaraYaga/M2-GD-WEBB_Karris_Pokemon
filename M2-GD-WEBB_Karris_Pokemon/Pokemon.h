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
	string mAbility1;
	string mAbility2;
	string mAbility3;
	string mAbility4;

	int mLife;
	int mLevel;

public:
	Pokemon(string mName, string mDescription);
	Pokemon(string name, string description, PokemonTypes pokeType, int level, int life);
	Pokemon();
	~Pokemon();

	string getPokemonName();
	string getPokemonDescription();
	PokemonTypes getPokemonType();
	int getLevel();
	int getLife();

	void setAbility(string newAbility1, string newAbility2, string newAbility3, string newAbility4);

};

