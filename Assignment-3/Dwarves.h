/*
* BLG 252E: Assignment 3
* Dwarves.h
*
* Created on: April 22th, 2021
*     Author: Sakine Busra Gocmez
*             150190064
*/

#ifndef DWARVES_H
#define DWARVES_H

#include "Faction.h"

// Dwarves class
class Dwarves : public Faction
{
public:
    Dwarves(string n = "", int nou = 0, int ap = 0, int hp = 0, int urn = 0);
    void PerformAttack();
    void ReceiveAttack(int, int, string);
    int PurchaseWeapons(int);
    int PurchaseArmors(int);
    void Print();
};
#endif