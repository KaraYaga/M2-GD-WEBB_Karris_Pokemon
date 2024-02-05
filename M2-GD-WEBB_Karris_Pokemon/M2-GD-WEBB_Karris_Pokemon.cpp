// M2-GD-WEBB_Karris_Pokemon.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include "Pokemon.h"
#include "Trainer.h"
using namespace std;

int main()
{
//Setting up PLAYER CHARACTER
    std::cout << "Hello Trainer! It's good to have a new face around here!\nLets get you registered with the FNAF : French National Association of Friends!\nBecause that's what Pokemon are, our friends!\nNow what is your First Name?";
    string firstname = "";

    std::cout << "And your family's name?";
    string lastname = "";

    std::cout << "Oh!" << firstname << " you're part of the " << lastname << " family, they're a legacy in the FNAF! Welcome, welcome!\nDid you want to register a new Catchphrase or use your family's? (New/Family)";
    string answer;

    cin >> answer;

    if (answer == "New") 
    {

    }
    if (answer == "Family") 
    {

    }


 //Setting up FIRST POKEMON
    std::cout << "Would you like a Starter Pokemon, or create your own? (Starter / Custom)\n";
    string answer;

    cin >> answer;

    if (answer == "Starter") 
    {
        Pokemon defaultPokemon = Pokemon();

        std::cout << "Your pokemon" << defaultPokemon.getPokemonName() << " has been registered in the Pokedex!";
    }

    if (answer == "Custom")
    {
        Pokemon custom;

        cout << "What would you like to name your Pokemon?\n";
        string name = "";

        cout << "Please describe your Pokemon so we may update the Pokedex!\n";
        string description = "";

        PokemonTypes type = choosePokemonType();

        custom = Pokemon(name, description, type);

        std::cout << "Your pokemon" << custom.getPokemonName() << " has been registered in the Pokedex!";
    }

    std::cout << "Now that we have registered you and your Pokemon you are set to battle other Trainers and their Pokemon!\nEvery Trainer may have up to 6 Pokemon in their team, we have provided you with 5 standard issue Pokeballs to be able to catch wild ones!\nPlease respect the Pokemon Nature and Health Preservation Act when catching wild Pokemon.\nIf your Pokemon become injured in battle you can let them rest, give them medicine, or come back here for medical treatmen.\nTake good care of your Pokemon, and don't forget to visit from time to time!";
    

}