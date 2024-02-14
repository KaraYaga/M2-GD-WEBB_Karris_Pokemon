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

    for (int i = 0; i < allAbilities.size(); i++) {
        std::cout << "#" << (i + 1) << " : " << allAbilities[i].GetName() << " : " << allAbilities[i].GetDescription() << endl;
    }

    for (int i = 0; i < 4; i++) {
        std::cout << "Enter the number corresponding to the type : ";
        int choice;
        std::cin >> choice;

        // Validate user input
        while (choice < 1 || choice > allAbilities.size()) {
            std::cout << "Invalid choice. Please enter a number between 1 and " << allAbilities.size() << " : ";
            std::cin >> choice;
        }

        // Check if there's room to ADD ABILITY
        for (int i = 0; i < 4; ++i) {
            if (mAbility[i].GetName() == "Default") {
                mAbility[i] = allAbilities[choice - 1];
                break;
            }
        }
    }
}

//TAKE DAMAGE
void Pokemon::takeDamage(int dmg)
{
    mLife = mLife - dmg;
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
        cout << "\n" << mAbility[i].GetName() << "\n\n";
    }
}

//CHOOSE FROM FOUR ABILITIES FOR BATTLE
int Pokemon::BattleAbility()
{
    cout << "Enter the number of the Ability you wish to use : ";
    int battlechoice;
    cin >> battlechoice;
    return battlechoice - 1; // Adjusting index for array access
}

void Pokemon::UseAbilityAgainst(int ability, Pokemon& target)
{
    // Ensure the ability index is within bounds
    if (ability < 0 || ability >= 4) {
        cout << "Invalid ability choice!";
        return;
    }

    target.takeDamage(mAbility[ability].getDamage());
    cout << mName << " uses " << mAbility[ability].GetName() << "!";
    cout << mAbility[ability].GetName() << " deals " << mAbility[ability].getDamage() << " to " << target.getPokemonName() << endl;
    cout << target.getLife() << " is what remains of their health!";
}

// WILD POKEMON
Pokemon::Pokemon(string name, string description, int mLife, int mLevel)
{
    mName = name;
    mDescription = description;
    this->mLife = mLife;
    this->mLevel = mLevel;
}

// GENERATE A WILD POKEMON
void Pokemon::GenerateRandomWildPokemon()
{
    // Define a list of wild Pokémon species
    vector<Pokemon> wildPokemonList = {
        Pokemon("Frutiger", "What a sweet little bubble!", PokemonTypes::DEFAULT, 20),
        Pokemon("Orion", "It's said you can see constellations in its eyes.", PokemonTypes::DEFAULT, 20),
        Pokemon("Aero", "A plant that looks like it's made of glass! She sways back and forth.", PokemonTypes::DEFAULT, 20),
        Pokemon("Flutter", "It's tiny wings can barely hold up its huge body!", PokemonTypes::DEFAULT, 30),
        Pokemon("Twilight", "You can only fully see this Pokemon when the sun is setting! Otherwise, it's a mist...", PokemonTypes::DEFAULT, 30),
        Pokemon("Pinkamina", "One of the funniest Pokemon around! Be careful her laughter is contagious, and you can never stop!", PokemonTypes::DEFAULT, 35),
        Pokemon("Grim", "He may look sad but that's just because bones can't show emotions, he's actually quite happy!", PokemonTypes::DEFAULT, 35),
        Pokemon("Glorbo", "Glorbo can absolve you of your sins.", PokemonTypes::DEFAULT, 40),
        Pokemon("Etn", "Etn is the sweetest pokemon there is! Etn is our personal favorite, and is always registered as Number 1!", PokemonTypes::DEFAULT, 45),
    };

    // Random choice from the list
    int randomIndex = rand() % wildPokemonList.size();

    // Assign the values to the current instance's member variables
    mName = wildPokemonList[randomIndex].getPokemonName();
    mDescription = wildPokemonList[randomIndex].getPokemonDescription();
    mLife = wildPokemonList[randomIndex].getLife();
    mLevel = wildPokemonList[randomIndex].getLevel();
    mPokemonType = wildPokemonList[randomIndex].getPokemonType();

    // Print the result
    cout << mName << " appears!\n" << mDescription;
}