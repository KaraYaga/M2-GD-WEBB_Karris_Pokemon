#include "Trainer.h"
#include <iostream>
using namespace std;

//START CUSTOM VALUES
Trainer::Trainer(string name, string lastname, string catchphrase)
{
    mName = name;
    mLastName = lastname;
    mCatchphrase= catchphrase;
    mLife = 30;
    mMoney = 50;
    mPokeballs = 5;
}

//DEFAULT VALUES
Trainer::Trainer()
{
    mName = "Fluffalump\n";
    mLastName = "A small pink fluff, scientists are unsure what Fluffalumps is made of.\nSome believe it's fur, other's believe it's a mist. What is known is getting your head stuck in a Fluffalump's body is lethal!\nThe Fluffalump has two wings that hover beside it's strange body, and they are well known for their melodious humming sounds.\nWhen several Fluffalumps are together it sounds like a chorus of notes humming together! Scientists belive Fluffalumps use this to attract mates, and identify one another, so cute!\n";
    mCatchphrase = "";
    mLife = 30;
    mMoney = 50;
    mPokeballs = 5;
}

Trainer::~Trainer() {}

string Trainer::getTrainerName() { return mName, mLastName; }

string Trainer::getCatchphrase() { return mCatchphrase; }

int Trainer::getMoney() { return mMoney; }

int Trainer::getLife() { return mLife; }

void Trainer::setPokemon(string pokemone[6]);

}


