#pragma once
#include "PokemonTypes.h"
#include "Abilities.h"
using namespace std;

class WildEncounters
{
private:
    string mName;
    string mDescription;
    int mLife;
    int mLevel;

public:
    WildEncounters wildPokemon();
    WildEncounters wildPokemon(string wildName, string wildDescription, int life, int level);

    string GetName();
    string GetDescription();

    void GenerateRandomWildPokemon();

};

