#pragma once
#pragma once
#include <iostream>
#include "PokemonTypes.h"
#include "Abilities.h"
#include <vector>
#include <string>
using namespace std;

class WildEncounters
{
private:
    string mName;
    string mDescription;
    int mLife;
    int mLevel;

public:
    WildEncounters(); // Default
    WildEncounters(string wildName, string wildDescription, int life, int level); // Custom

    string wildName();
    string wildDescription();

    void GenerateRandomWildPokemon();
};