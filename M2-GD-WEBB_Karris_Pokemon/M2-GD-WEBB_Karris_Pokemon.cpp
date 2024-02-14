// M2-GD-WEBB_Karris_Pokemon.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include "Trainer.h"
#include "PokemonTypes.h"
#include <limits>
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

    std::cout << "Oh! " << firstname << " you're part of the " << lastname << " family, they're a legacy in the FNAF! Welcome, welcome!\nDid you want to register a new Catchphrase or use your family's?\n\n(New/Family)\n\n";
    string phraseAnswer;
    Trainer player;
    std::cin >> phraseAnswer;

    if (phraseAnswer == "New")
    {
        std::cout << "Please enter your new Catchphrase " << firstname << " " << lastname << "!\n\n";
        string catchphrase;
        std::cin >> catchphrase;
        player = Trainer(firstname, lastname, catchphrase);
        std::cout << "Wonderful choice!\n\n";
    }
    else
    {
        player = Trainer(firstname, lastname);
        std::cout << "Wonderful choice : " << player.getCatchphrase() << "! Such a good phrase!\n\n";
    }


//Setting up FIRST POKEMON
    std::cout << "Now to get you a Pokemon! Would you like a Starter Pokemon, or create your own?\n\n(Starter / Custom)\n\n";
    string pokeAnswer;
    std::cin >> pokeAnswer;


    if (pokeAnswer == "Starter")
    {
        Pokemon* defaultPokemon = new Pokemon();

        std::cout << "Your pokemon " << defaultPokemon->getPokemonName() << " has been registered in the Pokedex! Here is a recap :\n" << defaultPokemon->getPokemonDescription() << "\n\n";

        //CHOOSE ABILITIES
        std::cout << "Now let's get " << defaultPokemon->getPokemonName() << " ready to fight!\n";
        defaultPokemon->chooseAbilities();
        cout << "Wonderful! Here are " << defaultPokemon->getPokemonName() << "'s 4 Abilities!\n";
        defaultPokemon->DisplayAbilities();

        if (player.GetTeam().size() < 6)
        {
            player.CapturePokemon(*defaultPokemon);
        }
    }

    if (pokeAnswer == "Custom")
    {
        Pokemon* customPokemon = new Pokemon();

        cout << "What would you like to name your Pokemon?\n\n";
        string name;
        getline(cin, name); // Read the entire line including spaces

        cout << "Please describe your Pokemon so we may update the Pokedex!\n\n";
        string description;
        getline(cin, description); // Read the entire line including spaces

        PokemonTypes type = choosePokemonType();

        customPokemon = new Pokemon(name, description, type);

        cout << "Your pokemon " << customPokemon->getPokemonName() << "\n" << " has been registered in the Pokedex! Here is a recap :\n" << customPokemon->getPokemonDescription() << "\n\n";

        //CHOOSE ABILITIES
        cout << "Now let's get " << customPokemon->getPokemonName() << " ready to fight!\n\n";
        customPokemon->chooseAbilities();
        cout << "Wonderful! Here are " << customPokemon->getPokemonName() << "'s 4 Abilities!\n\n";
        customPokemon->DisplayAbilities();

        if (player.GetTeam().size() < 6)
        {
            player.CapturePokemon(*customPokemon);
        }

    }

    cout << "Now that we have registered you and your Pokemon you are set to battle other Trainers and their Pokemon!\n\nEvery Trainer may have up to 6 Pokemon in their team so, we have provided you with 5 standard issue Pokeballs to be able to catch wild ones!\nPlease respect the Pokemon Nature and Health Preservation Act when catching wild Pokemon, and if your Pokemon become injured in battle you can let them rest, give them medicine, or come back here for medical treatment.\n\nTake good care of your Pokemon, and don't forget to visit from time to time!\n\n";

    //ADVENTURING BOOLS
    bool canAdventure = true;
    bool canBattle = true;

    // Flags to track whether each trainer has been defeated
    bool bigGuyDefeated = false;
    bool bombasticaDefeated = false;
    bool phoenicaDefeated = false;

    //DEFINING ENEMY TRAINERS
    Trainer bigGuy("Big", "Guy");
    vector<Pokemon*> bigGuyPokemons = vector<Pokemon*>{
        new Pokemon("Minnie Bitty", "So small you can't even see it!", PokemonTypes::FAIRY, 30), 
        new Pokemon("Beebo", "A weird Bee thing.", PokemonTypes::FLYING, 30),
        new Pokemon("Harper", "A cute bunny that likes to play music.", PokemonTypes::FAIRY, 30)};

    bigGuy.SetPokemons(bigGuyPokemons);

    //Trainer bombastica("Bombastica", "The Bomb");
    //bombastica.SetPokemons(vector<Pokemon>{Pokemon("Terry", "He's just a little guy!", PokemonTypes::FAIRY, 30), Pokemon("Rankor", "He's angry! He's red! He's Rankor!", PokemonTypes::DRAGON, 35), Pokemon("Bubalo", "A giant bubble that will explode at any momet!", PokemonTypes::POISON, 35), Pokemon("Marnimar", "A weird set of teeth...", PokemonTypes::GHOST, 40)});

    //Trainer phoenica("Phoenica", "La Phoenix");
    //phoenica.SetPokemons(vector<Pokemon>{Pokemon("Yoba", "A fallen god, consumed by the Earth.", PokemonTypes::PLANT, 40), Pokemon("Boba", "A pair of strange black balls that stare at you.", PokemonTypes::WATER, 40), Pokemon("Soba", "A... noodle bowl?", PokemonTypes::FAIRY, 45), Pokemon("Phoenix", "The rising sun, the dying ash, your proclaimed DOOM.", PokemonTypes::FLYING, 50)});

    //ADVENTURE OPTIONS
    while (canAdventure || canBattle) 
    {
        if (canAdventure) 
        {
            std::cout << "What would you like to do " << firstname << "? You can challenge Wild Pokemon to try and catch them using your Pokeballs, or fight another Trainer?\n\n(Wild, Trainer)\n\n";
            string action;
            cin >> action;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer

            // WILD Pokemon HUNTING
            if (action == "Wild")
            {
                std::cout << "Wonderful! You enter out into the grassy wilds and are surprised by a Pokemon!\n\n";

                // Generate a random wild Pokemon
                Pokemon* wildPokemon = new Pokemon();
                wildPokemon->GenerateRandomWildPokemon();
                std::cout << "Would you like to catch it?\n\n(Yes / No)\n\n";
                string catchPokemon;
                cin >> catchPokemon;

                if (catchPokemon == "Yes")
                {
                    // Capture the wild Pokémon
                    player.CapturePokemon(*wildPokemon); // Add the captured Pokémon to the player's team
                    std::cout << "You successfully caught " << wildPokemon->getPokemonName() << "!\n";
                    wildPokemon->chooseAbilities();

                    if (player.GetTeam().size() < 6)
                    {
                        player.CapturePokemon(*wildPokemon);
                    }

                    player.usePokeball(); // Use a Pokeball
                }
                else if (catchPokemon == "No")
                {
                    // Continue the adventure or any other desired action
                    delete wildPokemon; // Delete the allocated memory for the wild Pokemon if not captured
                }
                else
                {
                    // Handle invalid input
                    std::cout << "Invalid choice. Please enter 'Yes' or 'No'.\n";
                    delete wildPokemon; // Delete the allocated memory for the wild Pokemon in case of invalid input
                }
            }

            // TRAINER BATTLES
            if (action == "Trainer")
            {
                std::cout << "You have chosen to battle a Trainer! There is one gym, run by Big Guy, let's go fight!\n\n(Big Guy)\n\n";  //(Bombastica, Phoenica)
                string fight;
                getline(cin, fight);
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer

                //FIGHT BIG GUY
                if (fight == "Big Guy")
                {
                    if (!bigGuyDefeated)
                    {
                        //Enter Battle
                        std::cout << "Entering the gym you see a child standing in the center,\n'I am Big Guy!!! I will Guy your Big!!!'\n\nChoose which Pokemon you wish to fight with.\n\n";

                        //Choose Pokemon to Fight With
                        player.DisplayTeam();
                        int battlePokemon;
                        cin >> battlePokemon;
                        Pokemon* chosenOne = player.GetTeam()[battlePokemon - 1];
                        chosenOne->setInBall(false);
                        std::cout << "You sent out " << chosenOne->getPokemonName() << "!\n\n";
                        std::cout << player.getCatchphrase() << endl;

                        //Trainer randomly sends out Pokemon
                        int randomIndex = rand() % bigGuy.GetTeam().size();
                        Pokemon* randomPokemon = bigGuy.GetTeam()[randomIndex];
                        std::cout << "Big Guy sends out " << randomPokemon->getPokemonName() << "!\n\n";

                        while (randomPokemon->getLife() > 0)
                        {
                            //Choose Ability for Fight
                            std::cout << "Which of " << battlePokemon << "'s abilities do you want to use?";
                            chosenOne->DisplayAbilities();
                            chosenOne->BattleAbility();

                            //FIGHT
                            int battlechoice = chosenOne->BattleAbility();
                            chosenOne->UseAbilityAgainst(battlechoice, *randomPokemon);

                        }

                        // Check if Big Guy's team is defeated
                        bool bigGuyTeamDefeated = false;
                        for (const auto& pokemon : bigGuy.GetTeam())
                        {
                            if (randomPokemon->getLife() <= 0) {
                                bigGuyTeamDefeated = true;
                                break; // No need to continue i-+
                            }
                        }
                        if (bigGuyTeamDefeated)
                        {
                            // Set bigGuyDefeated to true if the player wins and calculate rewards
                            std::cout << "You have successfully defeated Big Guy! You've gained a Pokeball and some money!\n\n";
                            //Rewards
                            bigGuyDefeated = true;
                            player.gainPokeball();
                            player.winMoney();
                        }

                        // Check if the player's team is alive
                        bool playerTeamAlive = true;
                        for (const auto& pokemon : player.GetTeam())
                        {
                            if (chosenOne->getLife() <= 0)
                            {
                                playerTeamAlive = false;
                                break; // No need to continue if at least one Pokemon is alive
                            }
                        }
                        if (!playerTeamAlive)
                        {
                            cout << "I'm sorry Trainer... it looks like all your Pokemon have fainted. You'll have to come back later and try again.\n";
                            continue;
                        }
                    }
                    else if (bigGuyDefeated == true)
                    {
                        break;
                    }
                }
            }
                 //FIGHT BOMBASTICA
                 //else if (fight == "Bombastica")
                 //{
                 //    if (!bombasticaDefeated)
                 //    {
                 //        // Battle logic for Bombastica goes here
                 //        // Set bombasticaDefeated to true if the player wins
                 //        bombasticaDefeated = true;
                 //    }
                 //    else {
                 //        cout << "Bombastica has already been defeated." << endl;
                 //        continue; // Go back to the beginning of the loop to choose action again
                 //    }
                 //}

                 ////FIGHT PHOENICA
                 //else if (fight == "Phoenica")
                 //{
                 //    if (!phoenicaDefeated)
                 //    {
                 //        // Battle logic for Phoenica goes here
                 //        // Set phoenicaDefeated to true if the player wins
                 //        phoenicaDefeated = true;
                 //    }
                 //    else
                 //    {
                 //        cout << "Phoenica has already been defeated." << endl;
                 //        continue; // Go back to the beginning of the loop to choose action again
                 //    }
                 //}
        }
        //If cannot Adventure but CAN battle
        else if (player.getPokeballs() <= 0)
        {
            cout << "You don't have any Pokeballs left to go on an adventure.\n\n";
            canAdventure = false; // Update the condition to prevent further adventuring
            continue;

        }

        // Update the condition for trainer battles
        canBattle = !bigGuyDefeated; //|| !bombasticaDefeated || !phoenicaDefeated;
    }

    cout << "You have defeated all the trainers! How impressive " << firstname << ". You're quite the Trainer.\nThank you for Training with us here at FNAF!\nUntil next time!\n\n";

    return 0;
} 