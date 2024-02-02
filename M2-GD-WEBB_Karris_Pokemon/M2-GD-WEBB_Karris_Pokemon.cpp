// M2-GD-WEBB_Karris_Pokemon.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include "Pokemon.h"
using namespace std;

int main()
{
    std::cout << "Hello Trainer! Would you like a Starter Pokemon, or create your own? (Starter / Custom)\n";
    string answer;

    cin >> answer;

    if (answer == "Starter") 
    {
        Pokemon defaultPokemon();
    }
    if (answer == "Custom") 
    {
        Pokemon custom;

        cout << "What would you like to name your Pokemon?\n";
        string name = "";

        cout << "Please describe your Pokemon so we may update the Pokedex!\n";
        string description = "";

        PokemonTypes type = choosePokemonType();

        custom = Pokemon(name, description, PokemonTypes::DEFAULT, 1, 10);
    }

}