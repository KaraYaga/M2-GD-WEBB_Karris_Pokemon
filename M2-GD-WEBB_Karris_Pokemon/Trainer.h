#pragma once
#include <iostream>
#include "Pokemon.h"
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

	string Pokemon[6];

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

	void setPokemon(string pokemon1, string pokemon2, string pokemon3, string pokemon4, string pokemon5, string pokemon6);

};

