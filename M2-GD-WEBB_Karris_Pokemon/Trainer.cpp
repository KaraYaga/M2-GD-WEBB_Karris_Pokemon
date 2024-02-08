#include "Trainer.h"
#include <iostream>
using namespace std;

//START CUSTOM VALUES
Trainer::Trainer(string firstname, string lastname, string catchphrase)
{
    mTrainerName = firstname;
    mTrainerLastName = lastname;
    mCatchphrase= catchphrase;
    mTrainerLife = 30;
    mMoney = 50;
    mPokeballs = 5;
}
//DEFAULT CATCHPHRASE
Trainer::Trainer(string firstname, string lastname)
{
    mTrainerName = firstname;
    mTrainerLastName = lastname;
    mCatchphrase = "The three F's of Pokemon! Feeding! Fighting! . . . Friends!";
    mTrainerLife = 30;
    mMoney = 50;
    mPokeballs = 5;
}

//DEFAULT VALUES
Trainer::Trainer()
{
    mTrainerName = "";
    mTrainerLastName = "";
    mCatchphrase = "The three F's of Pokemon! Feeding! Fighting! . . . Friends!";
    mTrainerLife = 30;
    mMoney = 50;
    mPokeballs = 5;
}

Trainer::~Trainer() {}

string Trainer::getTrainerName() { return mTrainerName, mTrainerLastName; }

string Trainer::introduceSelf()
{
    return "I'm Trainer " + mTrainerName + " " + mTrainerLastName + " and I'm here to : " + getCatchphrase() + "!\n";
}

//CATCHPHRASE
string Trainer::getCatchphrase() { return mCatchphrase; }
void Trainer::setCatchphrase(string newCatchphrase) 
{
    mCatchphrase = newCatchphrase;
}

int Trainer::getMoney() { return mMoney; }
int Trainer::getPokeballs() { return mPokeballs; }
int Trainer::getLife() { return mTrainerLife; }


//CHOOSING TEAM
void Trainer::chooseTeam() {
    vector<Ability> allAbilities = {
        Ability("Charge", "cool", 10),
        Ability("Supercharge", "supercool", 10),
        Ability("zap", "electric", 10),
        Ability("grab", "ow", 5),
    };


    std::cout << "Please choose your Pokemon's four Abilities! Here are all available ones :\n";

    for (int i = 0; i < allAbilities.size(); i++)
    {
        std::cout << "#" << (i + 1) << " : " << allAbilities[i].GetName() << "  " << allAbilities[i].GetDescription() << endl;
    }

    for (int i = 0; i < 4; i++)
    {
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
    };


}

//DISPLAY TEAM
void Trainer::displayTeam()
{
    for (int i = 0; i < 6; i++)
    {
        cout << Pokemon[i].getPokemonName() << endl;
    }
}
