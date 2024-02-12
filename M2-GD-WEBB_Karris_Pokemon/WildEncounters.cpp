#include "WildEncounters.h"
#include <cstdlib> // For rand() function
#include <vector>


void WildEncounters::wildPokemon(string wildName, string wildDescription, int life, int level)
{
    mName = wildName;
    mDescription = wildDescription;
    mLife = life;
    mLevel = level;
}

string Ability::GetName()
{
    return mName;
}
string Ability::GetDescription()
{
    return mDescription;
}