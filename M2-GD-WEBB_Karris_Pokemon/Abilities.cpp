#include "Abilities.h"

//ABILITIES LIST

Abilities::Abilities() {
    mAbility[0] = "Ability 1";
    mAbility[1] = "Ability 2";
    mAbility[2] = "Ability 3";
    mAbility[3] = "Ability 4";
}

void addAbility(Abilities ability)
{
    // Check if there's room to ADD ABILITY
    for (int i = 0; i < 4; ++i) {
        if (mAbility[i].empty()) {
            mAbility[i] = ability;
            return;
        }
    }
};