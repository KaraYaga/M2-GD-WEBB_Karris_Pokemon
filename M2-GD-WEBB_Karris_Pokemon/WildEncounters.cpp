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
  {
    ("Frutiger", ("What a sweet little bubble!", 20)),
    ("Orion", ("It's said you can see constellations in it's eyes.", 20)),
    ("Aero", ("A plant that looks like it's made of glass! She sways back and forth.", 20)),
    ("Flutter", ("It's tiny wings can barely hold up it's huge body!", 30)),
    ("Twilight", ("You can only fully see this Pokemon when the sun is setting! Otherwise it's a mist...", 30)),
    ("Pinkamina", ("One of the funniest Pokemon around! Be careful her laughter is contagious, and you can never stop!", 35)),
    ("Grim", ("He may look sad but that's just because bones can't show emotions, he's actually quite happy!", 35)),
    ("Glorbo", ("Glorbo can absolve you of your sins.", 40)),
    ("Etn", ("Etn is the sweetest pokemon there is! Etn is our personal favorite, and is always registered as Number 1!", 45)),
   };

    // RANDOM choice from List
    int randomIndex = rand() % wildPokemon.size();

    // Assuming you want to print the result, change return type to void
    cout << wildPokemon[randomIndex] << " appears!\n";
}