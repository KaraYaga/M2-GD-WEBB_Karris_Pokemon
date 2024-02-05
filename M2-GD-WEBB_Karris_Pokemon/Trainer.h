#pragma once
#include <iostream>
#include "Trainer.cpp";
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
	~Trainer();

	string getTrainerName();
	string getCatchphrase();
	int getMoney();
	int getLife();

	void setPokemon(string pokemon1, string pokemon2, string pokemon3, string pokemon4, string pokemon5, string pokemon6);

};

