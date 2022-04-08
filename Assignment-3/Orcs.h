/*
* BLG 252E: Assignment 3
* Orcs.h
*
* Created on: April 22th, 2021
*     Author: Sakine Busra Gocmez
*             150190064
*/

#ifndef ORCS_H
#define ORCS_H

#include "Faction.h"
// orcs class
class Orcs : public Faction
{
public:
    Orcs(string n = "", int nou = 0, int ap = 0, int hp = 0, int urn = 0);
    void PerformAttack();
    void ReceiveAttack(int, int, string);
    int PurchaseWeapons(int);
    int PurchaseArmors(int);
    void Print();
};

#endif /* ORCS_H */