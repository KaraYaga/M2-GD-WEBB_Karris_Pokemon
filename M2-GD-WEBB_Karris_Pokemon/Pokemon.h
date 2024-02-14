#pragma once
#include <iostream>
#include "WildEncounters.h";
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
	Pokemon(); //DEFAULT
	Pokemon(string name, string description, PokemonTypes pokeType, int mLife); //TRAINER
	~Pokemon();

	string getPokemonName();
	string getPokemonDescription();
	PokemonTypes getPokemonType();
	int getLevel();
	int getLife();
	void setInBall(bool value);
	int takeDamage();

	void chooseAbilities();
	void DisplayAbilities();
	void BattleAbility();

};

