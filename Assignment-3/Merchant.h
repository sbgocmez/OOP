/*
* BLG 252E: Assignment 3
* Merchant.h
*
* Created on: April 22th, 2021
*     Author: Sakine Busra Gocmez
*             150190064
*/

#ifndef MERCHANT_H
#define MERCHANT_H

#include "Faction.h"
#include "Dwarves.h"
#include "Orcs.h"
#include "Elves.h"

class Merchant
{
private:
    Faction *firstFaction;
    Faction *secondFaction;
    Faction *thirdFaction;
    int startingWeaponPoint;
    int startingArmorPoint;
    int revenue;
    int weaponPoint;
    int armorPoint;
    /* I made an array of *Faction s of merchant, I set *factions to this array
    at assign factions method. and in sell functions I only loop over this
    array then if the name is ok, I only need 1 if-else block. It ease my work but then
    i notice in pdf we are expected to dynamically allocate memory for arrays. then i made it dynamic.
    then i think it may cause a problem in destructor if i never assigned factions ? (not sure).
    then i decided to initialize dynamic faction array in sell functions. then i notice
    since i have returns in error messages, they will pas the delete at the end of the function.
    then i think i dont need to delete since i am in a function and whenever i exit from the scope
    it wont cause any memory leak etc. but anyway i decided to write multiple if-else blocks.
    sad story :(
    */
    //Faction *factions[3];

public:
    Merchant(int swp = 0, int sap = 0);
    void AssignFactions(Faction *, Faction *, Faction *);
    int GetRevenue();
    int GetWeaponPoints();
    int GetArmorPoints();
    void EndTurn();
    bool SellWeapons(string, int);
    bool SellArmors(string, int);
    void print();
};

#endif /*MERCHANT_H*/