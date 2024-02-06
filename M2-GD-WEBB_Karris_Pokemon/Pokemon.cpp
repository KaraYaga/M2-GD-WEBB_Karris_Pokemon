#include "Pokemon.h"
#include <iostream>

//LEVEL 1 CUSTOM VALUES
Pokemon::Pokemon(string name, string description, PokemonTypes pokeType)
{
    mName = name;
    mDescription = description;
    mPokemonType = pokeType;
    mLevel = 1;
    mLife = 10;
}

//LEVEL 1 DEFAULT VALUES
Pokemon::Pokemon()
{
    mName = "Fluffalump";
    mDescription = "A small pink fluff, scientists are unsure what Fluffalumps are made of.\nSome believe it's fur, other's believe it's a mist. What is known is getting your head stuck in a Fluffalump's body is lethal!\nThe Fluffalump has two wings that hover beside it's strange body, and they are well known for their melodious humming sounds.\nWhen several Fluffalumps are together it sounds like a chorus of notes humming together!\nScientists belive Fluffalumps use this to attract mates, and identify one another, so cute!\n\n";
    mPokemonType = PokemonTypes::FAIRY;
    mPokemonType = PokemonTypes::POISON;
    mLevel = 1;
    mLife = 10;
}

Pokemon::~Pokemon() {}

string Pokemon::getPokemonName() { return mName; }

string Pokemon::getPokemonDescription() { return mDescription; }

PokemonTypes Pokemon::getPokemonType() { return mPokemonType; }

int Pokemon::getLevel() { return mLevel; }

int Pokemon::getLife() { return mLife; }

Abilities::addAbility;
