#pragma once
#include <iostream>
#include <string>
using namespace std;

class Ability 
{
private:
    string mName;
    string mDescription;
    int mDamage;
    int mUses;

public:
  
    Ability();
    Ability(string name, string description, int dmg, int uses);

    string GetName();
    string GetDescription();
    int getDamage();
};