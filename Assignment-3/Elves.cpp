/*
* BLG 252E: Assignment 3
* Elves.cpp
*
* Created on: April 22th, 2021
*     Author: Sakine Busra Gocmez
*             150190064
*/

#include "Elves.h"
// constructor
Elves::Elves(string n, int nou, int ap, int hp, int urn) : Faction(n, nou, ap, hp, urn)
{
    ;
}
// Elves perform attack
void Elves::PerformAttack()
{
    // for elves, orcs are the first enemy, dwarves are the second enemy
    int units1 = 0, units2 = 0; // units1 for orcs 2 for dwarves
    string attackedBy = this->name;
    int apoint = this->attackPoint;

    // if both alive
    if (this->firstEn->IsAlive() && this->secondEn->IsAlive())
    {
        units1 = (this->numOfUnits * 60) / 100; // attack orcs with 60% of units
        units2 = this->numOfUnits - units1;     // attack dwarves with rest of units
        this->firstEn->ReceiveAttack(units1, apoint, attackedBy);
        this->secondEn->ReceiveAttack(units2, apoint * 1.5, attackedBy);
    }
    // if only orcs alive
    else if (this->firstEn->IsAlive() && !this->secondEn->IsAlive())
        this->firstEn->ReceiveAttack(this->numOfUnits, apoint, attackedBy);
    // if only dwarves alive
    else if (!this->firstEn->IsAlive() && this->secondEn->IsAlive())
        this->secondEn->ReceiveAttack(this->numOfUnits, apoint * 1.5, attackedBy);
    // no one alive
    else
        ;
}
/* Receive attack for elves has special conditions in attack point.
   string attacedBy comes with attacker name and elves damage calculated
   with the changed attackpoint, which is changed wrt to attacker name
*/
void Elves::ReceiveAttack(int unit, int apoint, string attackedBy)
{
    // elves' first enemy is orcs
    if (attackedBy == this->firstEn->getName())
        apoint *= 1.25;
    // elves' second enemy is dwarves
    else if (attackedBy == this->secondEn->getName())
        apoint *= 0.75;
    int total_damage_received = unit * apoint;
    total_damage_received /= this->healthPoint;
    this->numOfUnits -= total_damage_received;
}
// purchase weapons takes # weaponBought, updates attack point &
// turns golds which ll be used for updating revenue of merchant at sellWeapons function
int Elves::PurchaseWeapons(int weaponBought)
{
    this->attackPoint += weaponBought * 2;
    return weaponBought * 15;
}
// purchase weapons takes # armorBought, updates health point &
// turns golds which ll be used for updating revenue of merchant at sellWeapons function
int Elves::PurchaseArmors(int armorBought)
{
    this->healthPoint += armorBought * 4;
    return armorBought * 5;
}
// Elves print
void Elves::Print()
{
    cout << "\"You cannot reach our elegance.\"" << endl;
    Faction::Print();
}