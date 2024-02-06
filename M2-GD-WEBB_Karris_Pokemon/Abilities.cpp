#include "Abilities.h"

//ABILITIES LIST

Abilities::Abilities() {
    mAbilities[0] = "Ability 1";
    mAbilities[1] = "Ability 2";
    mAbilities[2] = "Ability 3";
    mAbilities[3] = "Ability 4";
}

string* Abilities::addAbility() {
    return mAbilities;
}