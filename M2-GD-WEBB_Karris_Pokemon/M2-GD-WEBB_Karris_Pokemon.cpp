// M2-GD-WEBB_Karris_Pokemon.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include "Pokemon.h"
#include "Trainer.h"
#include "PokemonTypes.h"
using namespace std;

int main()
{
    Pokemon pikachu = Pokemon();
    pikachu.chooseAbilities();
    pikachu.DisplayAbilities();

//Setting up PLAYER CHARACTER
    cout << "Hello Trainer! It's good to have a new face around here!\nLets get you registered with the FNAF : French National Association of Friends!\nBecause that's what Pokemon are, our friends!\n\nNow what is your First Name?\n\n";
    string firstname;
    cin >> firstname;

    cout << "And your family's name?\n\n";
    string lastname;
    cin >> lastname;

    cout << "Oh! " << firstname << " you're part of the " << lastname << " family, they're a legacy in the FNAF! Welcome, welcome!\nDid you want to register a new Catchphrase or use your family's?\n\n(New/Family)";
    string phraseAnswer;
    Trainer player;
    cin >> phraseAnswer;

    if (phraseAnswer == "New")
    {
        cout << "Please enter your new Catchphrase " << firstname << " " << lastname << "!\n\n";
        string catchphrase;
        cin >> catchphrase;
        player = Trainer(firstname, lastname, catchphrase);
        cout << "Wonderful choice!\n\n";
    }
    else 
    {
        player = Trainer(firstname, lastname);
        cout << "Wonderful choice : " << player.getCatchphrase() << "! Such a good phrase!\n\n";
    }


 //Setting up FIRST POKEMON
    cout << "Now to get you a Pokemon! Would you like a Starter Pokemon, or create your own?\n\n(Starter / Custom)\n\n";
    string pokeAnswer;
    cin >> pokeAnswer;

    if (pokeAnswer == "Starter")
    {
        Pokemon defaultPokemon = Pokemon();

        cout << "Your pokemon " << defaultPokemon.getPokemonName() << " has been registered in the Pokedex! Here is a recap :\n" << defaultPokemon.getPokemonDescription() << "\n\n";
    }

    if (pokeAnswer == "Custom")
    {
        Pokemon custom;

        cout << "What would you like to name your Pokemon?\n\n";
        string name;
        cin >> name;

        cout << "Please describe your Pokemon so we may update the Pokedex!\n\n";
        string description;
        cin >> description;

        PokemonTypes type = choosePokemonType();

        custom = Pokemon(name, description, type);

        cout << "Your pokemon " << custom.getPokemonName() << "\n" << " has been registered in the Pokedex! Here is a recap :\n" << custom.getPokemonDescription() << "\n\n";
    }

    cout << "Now that we have registered you and your Pokemon you are set to battle other Trainers and their Pokemon!\n\nEvery Trainer may have up to 6 Pokemon in their team so, we have provided you with 5 standard issue Pokeballs to be able to catch wild ones!\nPlease respect the Pokemon Nature and Health Preservation Act when catching wild Pokemon, and if your Pokemon become injured in battle you can let them rest, give them medicine, or come back here for medical treatment.\n\nTake good care of your Pokemon, and don't forget to visit from time to time!\n\n";

//ADVENTURING
    if (player.getPokeballs() > 0)
    {
        cout << "What would you like to do " << firstname << "? You can challenge Wild pokemon to try and catch them using your Pokeballs, or fight another Trainer?\n\n(Wild, Trainer)";
        string action;
        cin >> action;

        //WILD Pokemon Hunting
        if (action == "Wild")
        {
        
            cout << "Wonderful! You enter out into the grassy wilds and are surprised by a pokemon! Would you like to try and catch it?\n(Yes / No)";
            string trytocatch;
            cin >> trytocatch;

            if (trytocatch == "Yes") 
            {
                cout << "You have entered a battle with a wild Pokemon! Choose the Pokemon you would like to battle with!";
            }
            else 
            {

            }

        }

        //TRAINER BATTLE
        if (action == "Trainer")
        {

        }
    }

    else 
    {
        cout << "It looks like you're out of Pokeballs! Why don't you challenge a Trainer to a battle try win some Pokeballs!";
    }

}