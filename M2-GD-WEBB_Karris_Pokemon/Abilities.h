#pragma once
#include <string>
using namespace std;

class Ability 
{
private:
    string mName;
    string mDescription;
    int mDamage;

public:
  
    Ability();
    Ability(string name, string description, int dmg);

    string GetName();
    string GetDescription();
};