/*
* BLG 252E: Assignment 3
* Dwarves.cpp
*
* Created on: April 22th, 2021
*     Author: Sakine Busra Gocmez
*             150190064
*/

#include "Dwarves.h"

// Dwarves constructor, behaves just like Faction and has no additional attributes
Dwarves::Dwarves(string n, int nou, int ap, int hp, int urn) : Faction(n, nou, ap, hp, urn)
{
    ;
}
// Dwarves Perform Attack
void Dwarves::PerformAttack()
{
    // for dwarves, orcs are the first enemy, elves are the second enemy (we set in the assign enemy function)
    int units1 = 0, units2 = 0; // units1 for elves units2 for dwarves
    string attackedBy = this->name;
    int apoint = this->attackPoint;

    // if both alive, unit number will be distributed equivalently. attack point has no special condition.
    if (this->firstEn->IsAlive() && this->secondEn->IsAlive())
    {
        units1 = (this->numOfUnits * 50) / 100; // attack orcs with 50% of units
        units2 = this->numOfUnits - units1;     // attack elves with 50% of units
        // both enemies receive attack from dwarves (string attackedBy = "Dwarves" here.)
        this->firstEn->ReceiveAttack(units1, apoint, attackedBy);
        this->secondEn->ReceiveAttack(units2, apoint, attackedBy);
    }
    // for dwarves, there is no special condition so we dont need to check name of the enemies
    // if only orcs alive
    else if (this->firstEn->IsAlive() && !this->secondEn->IsAlive())
        this->firstEn->ReceiveAttack(this->numOfUnits, apoint, attackedBy);
    // if only elves alive
    else if (!this->firstEn->IsAlive() && this->secondEn->IsAlive())
        this->secondEn->ReceiveAttack(this->numOfUnits, apoint, attackedBy);
    // no one alive
    else
        ;
}
// Receive attack takes unit, attack point and a string which indicates the name of the attacker
void Dwarves::ReceiveAttack(int unit, int apoint, string attackedBy)
{
    // for dwarves, there is no special condition wrt to name of the attacker
    int total_damage_received = unit * apoint;
    total_damage_received /= this->healthPoint;
    this->numOfUnits -= total_damage_received;
    // this update is optional
    this->totalHealth = this->numOfUnits * this->healthPoint;
}
// purchase weapons takes # weaponBought, updates attack point &
// turns golds which ll be used for updating revenue of merchant at sellWeapons function
int Dwarves::PurchaseWeapons(int weaponBought)
{
    this->attackPoint += weaponBought;
    return weaponBought * 10;
}
// purchase weapons takes # armorBought, updates health point &
// turns golds which ll be used for updating revenue of merchant at sellWeapons function
int Dwarves::PurchaseArmors(int armorBought)
{
    this->healthPoint += armorBought * 2;
    // this line is optional
    this->totalHealth = this->numOfUnits * this->healthPoint;
    return armorBought * 3;
}
// print method
void Dwarves::Print()
{
    cout << "\"Taste the power of our axes!\"" << endl;
    Faction::Print();
}