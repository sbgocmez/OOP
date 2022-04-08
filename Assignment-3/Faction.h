/*
* BLG 252E: Assignment 3
* Faction.h
*
* Created on: April 22th, 2021
*     Author: Sakine Busra Gocmez
*             150190064
*/

#ifndef FACTION_H
#define FACTION_H

#include <iostream>
#include <cstring>
#include <stdbool.h>

using namespace std;

/* Faction class: attributes are defined as protected since I ll use them in derived class directly
*/
class Faction
{
protected:
    int num;
    string name;
    Faction *firstEn;
    Faction *secondEn;
    int numOfUnits;
    int attackPoint;
    int healthPoint;
    int urNum;
    int totalHealth;
    bool isAlive;

public:
    Faction(string = "", int nou = 0, int ap = 0, int hp = 0, int urn = 0);
    void AssignEnemies(Faction *, Faction *);
    // pure virtual functions
    virtual void PerformAttack() = 0;
    virtual void ReceiveAttack(int, int, string) = 0;
    virtual int PurchaseWeapons(int) = 0;
    virtual int PurchaseArmors(int) = 0;
    virtual void Print();
    void EndTurn();
    bool IsAlive();
    // i added
    string getName();
};

#endif