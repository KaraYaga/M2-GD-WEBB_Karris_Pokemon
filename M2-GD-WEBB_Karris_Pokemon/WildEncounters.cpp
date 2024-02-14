//#pragma once
//#include <iostream>
//#include "PokemonTypes.h"
//#include "Abilities.h"
//#include <vector>
//#include <string>
//using namespace std;
//
//class WildEncounters
//{
//private:
//    string mName;
//    string mDescription;
//    int mLife;
//    int mLevel;
//
//public:
//    WildEncounters(); // Default
//    WildEncounters(string wildName, string wildDescription, int life, int level); // Custom
//
//    string wildName();
//    string wildDescription();
//
//    void GenerateRandomWildPokemon();
//};
//
//// Implementations
//
//WildEncounters::WildEncounters()
//{
//    // Default constructor implementation
//}
//
//WildEncounters::WildEncounters(string wildName, string wildDescription, int life, int level)
//{
//    mName = wildName;
//    mDescription = wildDescription;
//    mLife = life;
//    mLevel = level;
//}
//
//string WildEncounters::wildName() { return mName; }
//string WildEncounters::wildDescription() { return mDescription; }
//
//void WildEncounters::GenerateRandomWildPokemon()
//{
//    // Define a list of wild Pokémon species
//    vector<WildEncounters> wildPokemon =
//    {
//        WildEncounters("Frutiger", "What a sweet little bubble!", 20, 1),
//        WildEncounters("Orion", "It's said you can see constellations in its eyes.", 20, 1),
//        WildEncounters("Aero", "A plant that looks like it's made of glass! She sways back and forth.", 20, 1),
//        WildEncounters("Flutter", "It's tiny wings can barely hold up its huge body!", 30, 2),
//        WildEncounters("Twilight", "You can only fully see this Pokemon when the sun is setting! Otherwise, it's a mist...", 30, 2),
//        WildEncounters("Pinkamina", "One of the funniest Pokemon around! Be careful her laughter is contagious, and you can never stop!", 35, 3),
//        WildEncounters("Grim", "He may look sad but that's just because bones can't show emotions, he's actually quite happy!", 35, 3),
//        WildEncounters("Glorbo", "Glorbo can absolve you of your sins.", 40, 4),
//        WildEncounters("Etn", "Etn is the sweetest pokemon there is! Etn is our personal favorite, and is always registered as Number 1!", 45, 5),
//    };
//    // RANDOM choice from List
//    int randomIndex = rand() % wildPokemon.size();
//
//    // Assign the values to the current instance's member variables
//    mName = wildPokemon[randomIndex].mName;
//    mDescription = wildPokemon[randomIndex].mDescription;
//
//    // Print the result
//    std::cout << mName << " appears!\n" << mDescription;
//}