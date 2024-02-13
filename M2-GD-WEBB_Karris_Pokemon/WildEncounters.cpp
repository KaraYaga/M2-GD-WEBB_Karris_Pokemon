#include "WildEncounters.h"
#include <cstdlib> // For rand() function
#include <vector>


WildEncounters::wildPokemon(string wildName, string wildDescription, int life, int level)
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

void GenerateRandomWildPokemon()
{
    // Define a list of wild Pokémon species
    vector<std::string> wildPokemon =
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

    // Create and return the wild Pokémon
    return wildPokemon[randomIndex], "A wild Pokémon appears!", PokemonTypes::DEFAULT);
}