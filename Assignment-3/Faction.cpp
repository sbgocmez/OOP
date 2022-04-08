/*
* BLG 252E: Assignment 3
* Faction.cpp
*
* Created on: April 22th, 2021
*     Author: Sakine Busra Gocmez
*             150190064
*/

#include "Faction.h"

// Faction class constructor
Faction::Faction(string n, int nou, int ap, int hp, int urn)
{
    this->firstEn = NULL;
    this->secondEn = NULL;
    this->name = n;
    this->numOfUnits = nou;
    this->attackPoint = ap;
    this->healthPoint = hp;
    this->urNum = urn;
    this->totalHealth = nou * hp;
    this->isAlive = true;
}
// Assign enemies to the pointers
void Faction::AssignEnemies(Faction *e1, Faction *e2)
{
    /* our objects->names & their lengths are: Orcs = 4, Elves = 5, Dwarves = 7
    Enemy assignment in main.cpp is as follows:
    orcs.AssignEnemies(&elves, &dwarves)
    dwarves.AssignEnemies(&orcs, &elves)
    elves.AssignEnemies(&orcs, &dwarves)
    It can be seen from here, left parameter name is shorter than right parameter.
    Since at the beginning, I designed my code like order will never change, after the message of TA,
    I come with this solution. I always set enemies as I expect (like in the given main.cpp)
    So I dont need many if else blocks in further functions. I know which is first which is second.
    Hope its ok.
    */
    if (e1->name.length() < e2->name.length())
    {
        this->firstEn = e1;
        this->secondEn = e2;
        return;
    }
    this->firstEn = e2;
    this->secondEn = e1;
}
// Print function
void Faction::Print()
{
    string status;
    this->isAlive ? status = "Alive" : status = "Defeated";
    cout << "Faction Name:         " << this->name << endl;
    cout << "Status:               " << status << endl;
    cout << "Number of Units:      " << this->numOfUnits << endl;
    cout << "Attack Point:         " << this->attackPoint << endl;
    cout << "Health Point:         " << this->healthPoint << endl;
    cout << "Unit Regen Number:    " << this->urNum << endl;
    cout << "Total Faction Health: " << this->totalHealth << endl;
}
// End Turn function
void Faction::EndTurn()
{
    // check if negative and make 0
    if (this->numOfUnits < 0)
        this->numOfUnits = 0;
    // check if 0 and make isAlive = false
    if (this->numOfUnits == 0)
        this->isAlive = false;
    // check if not alive and make numOfUnits 0 (i think no need for this assignment line but anyway :D)
    // and ofc make total health 0
    if (!this->isAlive)
    {
        this->totalHealth = 0;
        this->numOfUnits = 0;
    }
    // check if alive & update numofunits with adding unit regeneration number & update total health
    else
    {
        this->numOfUnits += this->urNum;
        this->totalHealth = this->numOfUnits * this->healthPoint;
    }
}
// IsAlive function
bool Faction::IsAlive()
{
    return this->isAlive;
}
// name getter
string Faction::getName()
{
    return this->name;
}