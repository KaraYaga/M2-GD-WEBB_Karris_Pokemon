#include "Abilities.h"
#include <iostream>
using namespace std;

//ABILITIES LIST

Ability::Ability() {
    mName = "Default";
    mDescription = "Default";
};


Ability::Ability(string name, string description, int dmg) {
    mName = name;
    mDescription = description;
    mDamage = dmg;
}

string Ability::GetName()
{
    return mName;
}
string Ability::GetDescription()
{
    return mDescription;
}