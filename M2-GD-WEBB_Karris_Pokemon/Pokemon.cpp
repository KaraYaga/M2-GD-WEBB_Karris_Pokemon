#include "Pokemon.h"
#include <iostream>
#include <vector>
//LEVEL 1 CUSTOM VALUES
Pokemon::Pokemon(string name, string description, PokemonTypes pokeType)
{
    mName = name;
    mDescription = description;
    mPokemonType = pokeType;
    mLevel = 1;
    mLife = 10;
}

//LEVEL 1 DEFAULT VALUES
Pokemon::Pokemon()
{
    mName = "Fluffalump";
    mDescription = "A small pink fluff, scientists are unsure what Fluffalumps are made of.\nSome believe it's fur, other's believe it's a mist. What is known is getting your head stuck in a Fluffalump's body is lethal!\nThe Fluffalump has two wings that hover beside it's strange body, and they are well known for their melodious humming sounds.\nWhen several Fluffalumps are together it sounds like a chorus of notes humming together!\nScientists belive Fluffalumps use this to attract mates, and identify one another, so cute!\n\n";
    mPokemonType = PokemonTypes::FAIRY;
    mPokemonType = PokemonTypes::POISON;
    mLevel = 1;
    mLife = 10;
}

//POKEMON STATS
Pokemon::~Pokemon() {}
string Pokemon::getPokemonName() { return mName; }
string Pokemon::getPokemonDescription() { return mDescription; }
PokemonTypes Pokemon::getPokemonType() { return mPokemonType; }
int Pokemon::getLevel() { return mLevel; }
int Pokemon::getLife() { return mLife; }

//CHOOSE ABILITIES FOR POKEMON
void Pokemon::chooseAbilities() {
    vector<Ability> allAbilities = {
        Ability("Charge", "cool", 10),
        Ability("Supercharge", "supercool", 10),
        Ability("zap", "electric", 10),
        Ability("grab", "ow", 5),
    };
    

    std::cout << "Please choose your Pokemon's four Abilities! Here are all available ones :\n";

    for (int i = 0; i < allAbilities.size(); i++)
    {
        std::cout << "#" << (i + 1) << " : " << allAbilities[i].GetName()<<"  "<<allAbilities[i].GetDescription() << endl;
    }

    for (int i = 0; i < 4; i++) 
    {
        std::cout << "Enter the number corresponding to the type : ";

        int choice;
        std::cin >> choice;

        // Validate user input
        while (choice < 1 || choice > allAbilities.size()) {
            std::cout << "Invalid choice. Please enter a number between 1 and "<<allAbilities.size() <<" : ";
            std::cin >> choice;
        }

        // Check if there's room to ADD ABILITY
        for (int i = 0; i < 4; ++i) {
            if (mAbility[i].GetName() == "Default") {
                mAbility[i] = allAbilities[choice-1];
                break;
            }
        }
    };


}

//DISPLAY CHOSEN ABILITIES
void Pokemon::DisplayAbilities()
{
    for (int i = 0; i < 4; i++) 
    {
        cout << mAbility[i].GetName() << endl;
    }
}
