#include "Abilities.h"
#include <iostream>
using namespace std;

//ABILITY STATS
Ability::Ability() 
{
    mName = "Default";
    mDescription = "Default";
};


Ability::Ability(string name, string description, int dmg, int uses)
{
    mName = name;
    mDescription = description;
    mDamage = dmg;
    mUses = uses;
}

string Ability::GetName()
{
    return mName;
}
string Ability::GetDescription()
{
    return mDescription;
}
int Ability::doDamage() 
{
    pokemon.mLife - mDamage;
}