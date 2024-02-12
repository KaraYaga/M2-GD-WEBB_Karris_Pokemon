#pragma once
#include "WildEncounter.h";
#include <iostream>
using namespace std;

enum class PokemonTypes {
		NORMAL,
		FAIRY,
		WATER,
		PLANT,
		ELECTRIC,
		ICE,
		FIRE,
		FIGHTING,
		POISON,
		SUN,
		FLYING,
		PSYCHIC,
		INSECT,
		ROCK,
		GHOST,
		DRAGON,
		DEFAULT

};

inline PokemonTypes choosePokemonType() {
   cout << "Please choose a Type for your Pokemon! Here are all available types:\n"
        << "1. NORMAL\n"
        << "2. FAIRY\n"
        << "3. WATER\n"
        << "4. PLANT\n"
        << "5. ELECTRIC\n"
        << "6. ICE\n"
        << "7. FIRE\n"
        << "8. FIGHTING\n"
        << "9. POISON\n"
        << "10. SUN\n"
        << "11. FLYING\n"
        << "12. PSYCHIC\n"
        << "13. INSECT\n"
        << "14. ROCK\n"
        << "15. GHOST\n"
        << "16. DRAGON\n"
        << "Enter the number corresponding to the type: ";

    int choice;
    cin >> choice;

    // Validate user input
    while (choice < 1 || choice > 16) {
        cout << "Invalid choice. Please enter a number between 1 and 16: ";
        cin >> choice;
    }

    // Convert user input to enum type
    return static_cast<PokemonTypes>(choice - 1);
}
