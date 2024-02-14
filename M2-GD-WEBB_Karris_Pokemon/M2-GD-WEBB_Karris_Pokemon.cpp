// M2-GD-WEBB_Karris_Pokemon.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include "Trainer.h"
#include "PokemonTypes.h"
#include <cstdlib>
#include <ctime> 
using namespace std;

int main()
{

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

        //CHOOSE ABILITIES
        cout << "Now let's get " << defaultPokemon.getPokemonName() << " ready to fight!\n";
        defaultPokemon.chooseAbilities();
        cout << "Wonderful! Here are " << defaultPokemon.getPokemonName() << "'s 4 Abilities!\n";
        defaultPokemon.DisplayAbilities();

        if (player.GetTeam().size() < 6)
        {
            player.CapturePokemon(defaultPokemon);
        }
    }

    if (pokeAnswer == "Custom")
    {
        Pokemon customPokemon;

        cout << "What would you like to name your Pokemon?\n\n";
        string name;
        cin >> name;

        cout << "Please describe your Pokemon so we may update the Pokedex!\n\n";
        string description;
        cin >> description;

        PokemonTypes type = choosePokemonType();

        customPokemon = Pokemon(name, description, type);

        cout << "Your pokemon " << customPokemon.getPokemonName() << "\n" << " has been registered in the Pokedex! Here is a recap :\n" << customPokemon.getPokemonDescription() << "\n\n";

        //CHOOSE ABILITIES
        cout << "Now let's get " << customPokemon.getPokemonName() << " ready to fight!\n";
        customPokemon.chooseAbilities();
        cout << "Wonderful! Here are " << customPokemon.getPokemonName() << "'s 4 Abilities!\n";
        customPokemon.DisplayAbilities();

        if (player.GetTeam().size() < 6)
        {
            player.CapturePokemon(customPokemon);
        }

    }

    cout << "Now that we have registered you and your Pokemon you are set to battle other Trainers and their Pokemon!\n\nEvery Trainer may have up to 6 Pokemon in their team so, we have provided you with 5 standard issue Pokeballs to be able to catch wild ones!\nPlease respect the Pokemon Nature and Health Preservation Act when catching wild Pokemon, and if your Pokemon become injured in battle you can let them rest, give them medicine, or come back here for medical treatment.\n\nTake good care of your Pokemon, and don't forget to visit from time to time!\n\n";

 //ADVENTURING
    bool canAdventure = false;
    bool canBattle = false;

    // Flags to track whether each trainer has been defeated
    bool bigGuyDefeated = false;
    bool bombasticaDefeated = false;
    bool phoenicaDefeated = false;

    //DEFINING ENEMY TRAINERS
    Trainer bigGuy("Big", "Guy");
    bigGuy.SetPokemons(vector<Pokemon>{Pokemon("Snorlax", "Tired...", PokemonTypes::FAIRY, 30), Pokemon("Beebo", "A weird Bee thing.", PokemonTypes::FLYING, 30), Pokemon("Harper", "A cute bunny that likes to play music.", PokemonTypes::FAIRY, 30)});

    Trainer bombastica("Bombastica", "The Bomb");
    bombastica.SetPokemons(vector<Pokemon>{Pokemon("Terry", "He's just a little guy!", PokemonTypes::FAIRY, 30), Pokemon("Rankor", "He's angry! He's red! He's Rankor!", PokemonTypes::DRAGON, 35), Pokemon("Bubalo", "A giant bubble that will explode at any momet!", PokemonTypes::POISON, 35), Pokemon("Marnimar", "A weird set of teeth...", PokemonTypes::GHOST, 40)});

    Trainer phoenica("Phoenica", "La Phoenix");
    phoenica.SetPokemons(vector<Pokemon>{Pokemon("Yoba", "A fallen god, consumed by the Earth.", PokemonTypes::PLANT, 40), Pokemon("Boba", "A pair of strange black balls that stare at you.", PokemonTypes::WATER, 40), Pokemon("Soba", "A... noodle bowl?", PokemonTypes::FAIRY, 45), Pokemon("Phoenix", "The rising sun, the dying ash, your proclaimed DOOM.", PokemonTypes::FLYING, 50)});

    while (canAdventure || canBattle) {
        if (canAdventure) {
            cout << "What would you like to do " << firstname << "? You can challenge Wild Pokemon to try and catch them using your Pokeballs, or fight another Trainer?\n\n(Wild, Trainer)";
            string action;
            cin >> action;

            // WILD Pokemon HUNTING
            if (action == "Wild") {
                cout << "Wonderful! You enter out into the grassy wilds and are surprised by a Pokemon! Would you like to try and catch it?\n(Yes / No)";
                string trytocatch;
                cin >> trytocatch;

                if (trytocatch == "Yes") 
                {
                    //WildEncounters Instance
                    WildEncounters wildEncounter;

                    // Generate a random wild Pokemon
                    wildEncounter.GenerateRandomWildPokemon();

                    // Display  wild Pok�mon
                    cout << "A wild " << wildEncounter.wildName() << " appears!\n";
                    cout << "Would you like to catch it?\n(Yes / No)";
                    string catchPokemon;
                    cin >> catchPokemon;

                    if (catchPokemon == "Yes") 
                    {
                        //Add Battle Logic if Smart Enough
                        // Capture the wild Pok�mon
                        Pokemon wildPokemon = Pokemon(wildEncounter.wildName(), wildEncounter.wildDescription(), PokemonTypes::DEFAULT); // Create a Pok�mon instance
                        wildPokemon.chooseAbilities(); // Choose abilities for the captured Pok�mon
                        player.CapturePokemon(wildPokemon); // Add the captured Pok�mon to the player's team
                        cout << "You successfully caught " << wildPokemon.getPokemonName() << "!\n";
                        player.usePokeball(); // Use a Pokeball
                    }
                    if (catchPokemon == "No")
                    {
                        continue; // Go back to beginning of loop
                    }
                }
                else 
                {
                    continue; // Go back to beginning of loop
                }
            }

            // TRAINER BATTLES
            if (action == "Trainer") 
            {
                Trainer Trainer;
                cout << "You have chosen to battle a Trainer! There are three within this city, who would you like to battle?\n(Big Guy, Bombastica, Phoenica)";
                string fight;
                cin >> fight;

                if (fight == "Big Guy") 
                {
                    if (!bigGuyDefeated) 
                    {
                        cout << "Entering the gym you see a child standing in the center,\n'I am Big Guy!!! I will Guy your Big!!!'\nChoose which Pokemon you wish to fight with.";
                        Trainer.GetTeam();
                        string battlePokemon;
                        cin >> battlePokemon;

                        cout << "Send out " << battlePokemon << "!";

                        int randomIndex = rand() % bigGuy.SetPokemons().size();
                        Pokemon randomPokemon = bigGuy.SetPokemons()[randomIndex];
                        cout << "Big Guy sends out " << randomPokemon.getPokemonName() << "!" << endl;

                        cout << "Which of " << battlePokemon << "'s abilities do you want to use?";

                        battlePokemon.BattleAbility();

                      
                        // Set bigGuyDefeated to true if the player wins
                        bigGuyDefeated = true;
                    }
                    else {
                        cout << "Big Guy has already been defeated." << endl;
                        continue; // Go back to the beginning of the loop to choose action again
                    }
                }
                else if (fight == "Bombastica") 
                {
                    if (!bombasticaDefeated) 
                    {
                        // Battle logic for Bombastica goes here
                        // Set bombasticaDefeated to true if the player wins
                        bombasticaDefeated = true;
                    }
                    else {
                        cout << "Bombastica has already been defeated." << endl;
                        continue; // Go back to the beginning of the loop to choose action again
                    }
                }
                else if (fight == "Phoenica") 
                {
                    if (!phoenicaDefeated) 
                    {
                        // Battle logic for Phoenica goes here
                        // Set phoenicaDefeated to true if the player wins
                        phoenicaDefeated = true;
                    }
                    else 
                    {
                        cout << "Phoenica has already been defeated." << endl;
                        continue; // Go back to the beginning of the loop to choose action again
                    }
                }
            }
        }
        else {
            cout << "You don't have any Pokeballs left to go on an adventure." << endl;
            canAdventure = false; // Update the condition to prevent further adventuring
        }

        // Update the condition for trainer battles
        canBattle = !bigGuyDefeated || !bombasticaDefeated || !phoenicaDefeated;
    }

    cout << "You have defeated all the trainers! How impressive " << firstname << ". You've quite the Trainer.\nThank you for Training with us here at FNAF!\nUntil next time!" << endl;

    return 0;
}