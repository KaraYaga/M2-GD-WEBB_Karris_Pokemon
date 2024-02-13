#pragma once
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

// Implementations

WildEncounters::WildEncounters()
{
    // Default constructor implementation
}

WildEncounters::WildEncounters(string wildName, string wildDescription, int life, int level)
{
    mName = wildName;
    mDescription = wildDescription;
    mLife = life;
    mLevel = level;
}

string WildEncounters::wildName()
{
    return mName;
}

string WildEncounters::wildDescription()
{
    return mDescription;
}

void WildEncounters::GenerateRandomWildPokemon()
{
    // Define a list of wild Pokémon species
    vector<string> wildPokemon =
    { "Pidgey",
      "Rattata",
      "Caterpie",
      "Weedle",
      "Pikachu",
      "Spearow",
      "Ekans",
      "Sandshrew"
    };

    // RANDOM choice from List
    int randomIndex = rand() % wildPokemon.size();

    // Assuming you want to print the result, change return type to void
    cout << wildPokemon[randomIndex] << " appears!\n";
}