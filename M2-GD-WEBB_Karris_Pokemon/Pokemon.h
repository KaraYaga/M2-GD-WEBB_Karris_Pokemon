#pragma once
#include <iostream>
#include "PokemonTypes.h"
#include "Abilities.h"
using namespace std;

class Pokemon
{
private:
    string mName;
    string mDescription;
    PokemonTypes mPokemonType;
    Ability mAbility[4];

    int mLife;
    int mLevel;

    bool inBall;

public:
    Pokemon(string mName, string mDescription, PokemonTypes pokeType); // CUSTOM
    Pokemon();                                                          // DEFAULT
    Pokemon(string name, string description, PokemonTypes pokeType, int mLife); // TRAINER
    Pokemon(string name, string description, int mLife, int mLevel); // WILD
    ~Pokemon();

    // Pokemon Stats
    string getPokemonName();
    string getPokemonDescription();
    PokemonTypes getPokemonType();
    int getLevel();
    int getLife();
    // Abilities
    void setInBall(bool value);
    void takeDamage(int dmg);
    void chooseAbilities();
    void DisplayAbilities();
    int BattleAbility();
    void UseAbilityAgainst(int ability, Pokemon& target);

    // Wild Pokemon
    void GenerateRandomWildPokemon();
};