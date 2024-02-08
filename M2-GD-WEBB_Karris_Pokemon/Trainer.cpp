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
//DEFAULT CATCHPHRASE
Trainer::Trainer(string firstname, string lastname)
{
    mTrainerName = firstname;
    mTrainerLastName = lastname;
    mCatchphrase = "The three F's of Pokemon! Feeding! Fighting! . . . Friends!";
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

string Trainer::introduceSelf()
{
    return "I'm Trainer " + mTrainerName + " " + mTrainerLastName + " and I'm here to : " + getCatchphrase() + "!\n";
}

//CATCHPHRASE
string Trainer::getCatchphrase() { return mCatchphrase; }
void Trainer::setCatchphrase(string newCatchphrase) 
{
    mCatchphrase = newCatchphrase;
}

int Trainer::getMoney() { return mMoney; }
int Trainer::getPokeballs() { return mPokeballs; }
int Trainer::getLife() { return mTrainerLife; }

//DISPLAY TEAM / PUSH BACK INTO TEAM
vector <Pokemon> Trainer::displayTeam()
{
    return mTeam;
}
