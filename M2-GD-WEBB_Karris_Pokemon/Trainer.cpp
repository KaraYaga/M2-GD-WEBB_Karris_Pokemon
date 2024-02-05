#include "Trainer.h"
#include <iostream>
using namespace std;

//START CUSTOM VALUES
Trainer::Trainer(string firstname, string lastname, string catchphrase)
{
    mTrainerName = firstname;
    mTrainerLastName = lastname;
    mCatchphrase= catchphrase;
    mTrainerLife = 30;
    mMoney = 50;
    mPokeballs = 5;
}

//DEFAULT VALUES
Trainer::Trainer()
{
    mTrainerName = "";
    mTrainerLastName = "";
    mCatchphrase = "The three F's of Pokemon! Feeding! Fighting! . . . Friends!";
    mTrainerLife = 30;
    mMoney = 50;
    mPokeballs = 5;
}

Trainer::~Trainer() {}

string Trainer::getTrainerName() { return mTrainerName, mTrainerLastName; }

string Trainer::getCatchphrase() { return mCatchphrase; }

int Trainer::getMoney() { return mMoney; }

int Trainer::getLife() { return mTrainerLife; }

//void Trainer::setPokemon(string pokemone[6]);