/*
* BLG 252E: Assignment 3
* Elves.h
*
* Created on: April 22th, 2021
*     Author: Sakine Busra Gocmez
*             150190064
*/

#ifndef ELVES_H
#define ELVES_H

#include "Faction.h"
// Elves class
class Elves : public Faction
{
public:
    Elves(string n = "", int nou = 0, int ap = 0, int hp = 0, int urn = 0);
    void PerformAttack();
    void ReceiveAttack(int, int, string);
    int PurchaseWeapons(int);
    int PurchaseArmors(int);
    void Print();
};
#endif