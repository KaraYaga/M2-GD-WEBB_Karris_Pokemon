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

//TRAINER POKEMON
Pokemon::Pokemon(string name, string description, PokemonTypes pokeType, int mLife)
{
    mName = name;
    mDescription = description;
    mPokemonType = pokeType;
    mLevel = 1;
    this->mLife = mLife;
}

//POKEMON STATS
Pokemon::~Pokemon() {}
string Pokemon::getPokemonName() { return mName; }
string Pokemon::getPokemonDescription() { return mDescription; }
PokemonTypes Pokemon::getPokemonType() { return mPokemonType; }
int Pokemon::getLevel() { return mLevel; }
int Pokemon::getLife() { return mLife; }

//TAKE DAMAGE
int takeDamage(int damage) 
{
    mLife -= damage;
    return mLife;
}

//CHOOSE ABILITIES FOR POKEMON
void Pokemon::chooseAbilities() {
    vector<Ability> allAbilities = 
    {
        Ability("Smash", "Bludgeon your enemy with brute force!", 5, 3),
        Ability("Slash", "Lash out at your enemy with sharpened skill!", 5, 3),
        Ability("Spit", "Spit on your enemy, blinding them and burning their skin!", 5, 3),
        Ability("Poisionus Smoke", "Cough out black smoke that chokes your enemy!", 5, 3),
        Ability("Noxious Gas", "Gas leeks from your Pokemon's body rendering the enemy nauseous and sick!", 5, 3),
        Ability("Stampede", "Split your Pokemon into three and stampede towards the enemy!", 5, 3),
        Ability("Hanged Man", "Your Pokemon begins to do a strange dance that hurts to look at!", 5, 3),
        Ability("Armored Bullet", "Your Pokemon's flesh becomes as hard as steel as they barrel towards the enemy!", 5, 3),
        Ability("Rip", "Rip apart the flesh of your enemies!", 10, 2),
        Ability("Tear", "Tear apart your enemies, limb from limb!", 10, 2),
        Ability("Crushing Hit", "Break bones and burst organs!", 10, 2),
        Ability("Fanged Bite", "Bite into the enemy and exsanguinate them!", 10, 2),
        Ability("Death from Above", "Fly above your enemy and torpedo towards them, hitting their body with a massive shock wave!", 10, 2),
        Ability("Death Shriek", "Violently scream, rendering the breains of your enemies mush!", 15, 1),
        Ability("Bloody Transmutation", "Transform the very body of your enemy, breaking bones, and splitting tendons!", 15, 1),
        Ability("???", "It... does something???", 20, 1),
    };
    

    std::cout << "Please choose your Pokemon's four Abilities! Keep in mind, the Lower in the list, the Higher the power and the fewer uses it has before it must rest...maybe!\nHere are all available ones :\n";

    for (int i = 0; i < allAbilities.size(); i++)
    {
        std::cout << "#" << (i + 1) << " : " << allAbilities[i].GetName()<<" : "<<allAbilities[i].GetDescription() << endl;
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

int Pokemon::takeDamage()
{
    return 0;
}

void Pokemon::setInBall(bool value)
{
    inBall = value;
}

//DISPLAY CHOSEN ABILITIES
void Pokemon::DisplayAbilities()
{
    for (int i = 0; i < 4; i++) 
    {
        cout << mAbility[i].GetName() << endl;
    }
}

//CHOOSE FROM FOUR ABILITIES FOR BATTLE
void Pokemon::BattleAbility()
{
    for (int i = 0; i < 4; i++)
    {
        cout << mAbility[i].GetName() << endl;
        std::cout << "Enter the number of the Ability you wish to use : ";

        int battlechoice;
        std::cin >> battlechoice;

        cout << mName << " uses " << battlechoice << "!";
    }
}
