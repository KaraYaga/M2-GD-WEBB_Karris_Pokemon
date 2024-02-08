#pragma once
#include <iostream>
#include "Pokemon.h"
#include <vector>
using namespace std;

class Trainer
{
private:
	string mTrainerName;
	string mTrainerLastName;
	string mCatchphrase;
	int mMoney;
	int mTrainerLife;
	int mPokeballs;

	vector <Pokemon> mTeam;

	bool canAdventure = getPokeballs() > 0;
	bool canBattle = !bigGuyDefeated || !bombasticaDefeated || !phoenicaDefeated;

	bool bigGuyDefeated = false;
	bool bombasticaDefeated = false;
	bool phoenicaDefeated = false;

public:
	Trainer(string name, string lastname, string catchphrase);
	Trainer(string name, string lastname);
	Trainer();
	~Trainer();

	string getTrainerName();
	void setCatchphrase(string newCatchphrase);
	string getCatchphrase();
	string introduceSelf();

	int getMoney();
	int getLife();
	int getPokeballs();
	void SetPokemons(vector<Pokemon> team);
	void CapturePokemon(Pokemon captured);

	vector <Pokemon> GetTeam();


};

