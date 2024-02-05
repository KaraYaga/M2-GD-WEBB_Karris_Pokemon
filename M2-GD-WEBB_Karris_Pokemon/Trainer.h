#pragma once
#include <iostream>
using namespace std;

class Trainer
{
private:
	string mName;
	string mLastName;
	string mCatchphrase;
	int mMoney;
	int mLife;
	int mPokeballs;

	string Pokemon[6];

public:
	Trainer(string mName, string mLastName, string mCatchphrase, int mMoney, int mLife, int mPokeballs);
	~Trainer();

	string getTrainerName();
	string getCatchphrase();
	int getMoney();
	int getLife();

	void setPokemon(string pokemon1, string pokemon2, string pokemon3, string pokemon4, string pokemon5, string pokemon6);

};

