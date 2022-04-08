/*
* BLG 252E: Assignment 3
* Orcs.cpp
*
* Created on: April 22th, 2021
*     Author: Sakine Busra Gocmez
*             150190064
*/

#include "Orcs.h"

Orcs::Orcs(string n, int nou, int ap, int hp, int urn) : Faction(n, nou, ap, hp, urn)
{
    ;
}
// orc perform attack
void Orcs::PerformAttack()
{
    // for orcs, elves are the first enemy, dwarves are the second enemy
    int units1 = 0, units2 = 0; // units1 for elves units2 for dwarves
    string attackedBy = this->name;
    int apoint = this->attackPoint;

    // if both alive
    if (this->firstEn->IsAlive() && this->secondEn->IsAlive())
    {
        units1 = (this->numOfUnits * 70) / 100; // attack elves with 70% of units
        units2 = this->numOfUnits - units1;     // attack dwarves with rest of units
        this->firstEn->ReceiveAttack(units1, apoint, attackedBy);
        this->secondEn->ReceiveAttack(units2, apoint, attackedBy);
    }
    // if only elves alive
    else if (this->firstEn->IsAlive() && !this->secondEn->IsAlive())
        this->firstEn->ReceiveAttack(this->numOfUnits, apoint, attackedBy);
    // if only dwarves alive
    else if (!this->firstEn->IsAlive() && this->secondEn->IsAlive())
        this->secondEn->ReceiveAttack(this->numOfUnits, apoint, attackedBy);
    // no one alive
    else
        ;
}
/* Receive attack for orcs has special conditions in attack point.
   string attacedBy comes with attacker name and elves damage calculated
   with the changed attackpoint, which is changed wrt to attacker name
*/
void Orcs::ReceiveAttack(int unit, int apoint, string attackedBy)
{
    // orcs' first enemy is elves
    if (attackedBy == this->firstEn->getName())
        apoint *= 0.75;
    // orcs' second enemy is dwarves
    else if (attackedBy == this->secondEn->getName())
        apoint *= 0.80;
    int total_damage_received = unit * apoint;
    total_damage_received /= this->healthPoint;
    this->numOfUnits -= total_damage_received;
}
// purchase weapons takes # weaponBought, updates attack point &
// turns golds which ll be used for updating revenue of merchant at sellWeapons function
int Orcs::PurchaseWeapons(int weaponBought)
{
    this->attackPoint += weaponBought * 2;
    return weaponBought * 20;
}
// purchase weapons takes # armorBought, updates health point &
// turns golds which ll be used for updating revenue of merchant at sellWeapons function
int Orcs::PurchaseArmors(int armorBought)
{
    this->healthPoint += armorBought * 3;
    return armorBought;
}
// Orcs print
void ::Orcs::Print()
{
    cout << "\"Stop running, you'll only die tired!\"" << endl;
    Faction::Print();
}