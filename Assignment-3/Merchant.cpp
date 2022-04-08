/*
* BLG 252E: Assignment 3
* Merchant.cpp
*
* Created on: April 22th, 2021
*     Author: Sakine Busra Gocmez
*             150190064
*/

#include "Merchant.h"

Merchant::Merchant(int wp, int ap)
{
    this->firstFaction = NULL;
    this->secondFaction = NULL;
    this->thirdFaction = NULL;

    this->startingArmorPoint = ap;
    this->startingWeaponPoint = wp;
    this->revenue = 0;
    this->weaponPoint = wp;
    this->armorPoint = ap;
}
// assign factions
void Merchant::AssignFactions(Faction *f1, Faction *f2, Faction *f3)
{
    this->firstFaction = f1;
    this->secondFaction = f2;
    this->thirdFaction = f3;
}
// get revenue
int Merchant::GetRevenue()
{
    return this->revenue;
}
// get weapon point
int Merchant::GetWeaponPoints()
{
    return this->weaponPoint;
}
// get armor point
int Merchant::GetArmorPoints()
{
    return this->armorPoint;
}
// end of turn, set weaponpoint and armorpoints to the starting values
void Merchant::EndTurn()
{
    this->weaponPoint = this->startingWeaponPoint;
    this->armorPoint = this->startingArmorPoint;
}
/* Sell weapons. 
   check which faction has given name, call purchase weapons method of that faction
*/
bool Merchant::SellWeapons(string sellTo, int numberOfWeapons)
{
    if (numberOfWeapons > this->weaponPoint)
    {
        cout << "You try to sell more weapons than you have in possession." << endl;
        return false;
    }
    if (this->firstFaction->getName() == sellTo || this->secondFaction->getName() == sellTo || this->thirdFaction->getName() == sellTo)
    {
        if (this->firstFaction->getName() == sellTo)
        {
            if (this->firstFaction->IsAlive())
            {
                cout << "Weapons sold!" << endl;
                this->revenue += this->firstFaction->PurchaseWeapons(numberOfWeapons);
            }
            else
            {
                cout << "The faction you want to sell weapons is dead!" << endl;
                return false;
            }
        }
        if (this->secondFaction->getName() == sellTo)
        {
            if (this->secondFaction->IsAlive())
            {
                cout << "Weapons sold!" << endl;
                this->revenue += this->secondFaction->PurchaseWeapons(numberOfWeapons);
            }
            else
            {
                cout << "The faction you want to sell weapons is dead!" << endl;
                return false;
            }
        }
        if (this->thirdFaction->getName() == sellTo)
        {
            if (this->thirdFaction->IsAlive())
            {
                cout << "Weapons sold!" << endl;
                this->revenue += this->thirdFaction->PurchaseWeapons(numberOfWeapons);
            }
            else
            {
                cout << "The faction you want to sell weapons is dead!" << endl;
                return false;
            }
        }
    }
    this->weaponPoint -= numberOfWeapons;
    return true;
}
/* Sell armors. 
   check which faction has given name, call purchase armors method of that faction
*/
bool Merchant::SellArmors(string sellTo, int numberOfArmors)
{
    if (numberOfArmors > this->armorPoint)
    {
        cout << "You try to sell more armors than you have in possession." << endl;
        return false;
    }
    if (this->firstFaction->getName() == sellTo || this->secondFaction->getName() == sellTo || this->thirdFaction->getName() == sellTo)
    {
        if (this->firstFaction->getName() == sellTo)
        {
            if (this->firstFaction->IsAlive())
            {
                cout << "Armors sold!" << endl;
                this->revenue += this->firstFaction->PurchaseArmors(numberOfArmors);
            }
            else
            {
                cout << "The faction you want to sell armors is dead!" << endl;
                return false;
            }
        }
        if (this->secondFaction->getName() == sellTo)
        {
            if (this->secondFaction->IsAlive())
            {
                cout << "Armors sold!" << endl;
                this->revenue += this->secondFaction->PurchaseArmors(numberOfArmors);
            }
            else
            {
                cout << "The faction you want to sell armors is dead!" << endl;
                return false;
            }
        }
        if (this->thirdFaction->getName() == sellTo)
        {
            if (this->thirdFaction->IsAlive())
            {
                cout << "Armors sold!" << endl;
                this->revenue += this->thirdFaction->PurchaseArmors(numberOfArmors);
            }
            else
            {
                cout << "The faction you want to sell armors is dead!" << endl;
                return false;
            }
        }
    }

    this->armorPoint -= numberOfArmors;
    return true;
}