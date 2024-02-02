#include "Pokemon.h"
#include <iostream>
using namespace std;

//Pokemon only choose Name and Description
Pokemon::Pokemon(string name, string description)
{
    mName = name;
    mDescription = description;
    mPokemonType = PokemonTypes::NORMAL;
    mLevel = 1;
    mLife = 10;
}
//Pokemon all CUSTOM VALUES
Pokemon::Pokemon(string name, string description, PokemonTypes pokeType, int level, int life) 
{
    mName = name;
    mDescription = description;
    mPokemonType = pokeType;
    mLevel = level;
    mLife = life;
}
//Pokemon all DEFAULT VALUES
Pokemon::Pokemon()
{
    mName = "name";
    mDescription = "description";
    mPokemonType = PokemonTypes::NORMAL;
    mLevel = 1;
    mLife = 10;
}
Pokemon::~Pokemon() {}

string Pokemon::getPokemonName() { return mName; }

string Pokemon::getPokemonDescription() { return mDescription; }

PokemonTypes Pokemon::getPokemonType() { return mPokemonType; }

int Pokemon::getLevel() { return mLevel; }

int Pokemon::getLife() { return mLife; }

void Pokemon::setAbility(string newAbility1, string newAbility2, string newAbility3, string newABility4) { mAbility1 = newAbility1; mAbility2 = newAbility2; mAbility3 = newAbility3; mAbility4 = newAbility4; }

