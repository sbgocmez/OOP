//////////////////////////////////
/*       Sakine Busra Gocmez    */
/*          150190064           */
//////////////////////////////////
#include <stdio.h>
#include <iostream>

#include "GreatWarrior.h"

// LAND CLASS FUNCTIONS //
// constructor, optionally takes strings, starts linkedlist.
Land::Land(string land_name, string holding_name)
{
    name = land_name;
    holding = holding_name;
    next = NULL;
}
// copy constructor
Land::Land(const Land &objectIn)
{
    name = objectIn.name;
    holding = objectIn.holding;
    next = NULL;
}
// deconstructor: basic linked list deletion
Land::~Land()
{
    Land *willbedeleted = next;
    Land *temp;
    if (willbedeleted == NULL)
        return;

    while (willbedeleted->next != NULL)
    {
        temp = willbedeleted;
        willbedeleted = willbedeleted->next;
        delete[] temp;
    }
}

// CHARACTER CLASS FUNCTIONS //
// constructor
Character::Character(string char_name, int char_mpw, int char_gold, int char_numof_lands, Land *l)
{
    name = char_name;
    manpower = char_mpw;
    gold = char_gold;
    numOfLands = char_numof_lands;
    lands = NULL;
}
// copy constructor
Character::Character(const Character &objectIn)
{
    name = objectIn.name;
    manpower = objectIn.manpower;
    gold = objectIn.gold;
    numOfLands = objectIn.numOfLands;
    lands = objectIn.lands;
}
//deconstructor
Character::~Character()
{
}
/*
takes land, adds it to the linked list.
when the function end, memory allocated for temp will be gone.
*/
void Character::addLand(const Land &toadd)
{
    //cout << "here " << endl;
    Land *temp = new Land(toadd); // copy of toadd
    Land *prev;
    if (lands == NULL)
        lands = temp;
    else
    {
        prev = lands;
        while (prev->next != NULL)
            prev = prev->next;
        prev->next = temp;
    }
}

/*
removes the land from the loser.
returns the holding name of the corresponding land. will use holding name when adding land to winner.
*/
string Character::removeLand(string land_name)
{
    string holding_name = "";
    Land *willbedeleted = getLands();
    Land *tmp = new Land;
    if (willbedeleted->nameGetter() == land_name)
    {
        holding_name = lands->holdingGetter();
        lands = willbedeleted->next;
        delete willbedeleted;
        return holding_name;
    }
    while (willbedeleted->next->nameGetter() != land_name)
        willbedeleted = willbedeleted->next;
    tmp = willbedeleted->next;
    willbedeleted->next = tmp->next;
    holding_name = tmp->holdingGetter();
    delete tmp;
    return holding_name;
}

// get taxes wrt rules, returns total gold of the turn, uses it in main function
int Character::getTaxes()
{
    Land *tmp = lands;
    int total = gold;
    while (tmp != NULL)
    {
        if (tmp->holdingGetter() == "village")
            total += 5;

        else if (tmp->holdingGetter() == "castle")
            total += 7;
        else
            total += 10;
        tmp = tmp->next;
    }
    return total;
}

// CHARACTER LIST CLASS FUNCTIONS //
// default constructor
CharacterList::CharacterList()
{
    size = 0;
    characters = NULL;
}
// deconstructor
// i tried :(((((((( but couldnt do.... :(
// i also tried to delete linked list here but didnt work...
CharacterList::~CharacterList()
{
    /*for (int i = 0; i < size; i++)
    {
        delete[] & characters[i];
    }*/
}
// i didnt use it. gets the player wrt to given name.
// i was about to use it, but i didnt need i think so.
Character &CharacterList::getPlayer(string name)
{
    for (int i = 0; i < size; i++)
    {
        if (characters[i].nameGetter() == name)
        {
            return characters[i];
        }
    }
    return characters[0];
}

// returns the index of owner (in characters array) of the land.
int CharacterList::getLandOwner(string land_name)
{
    for (int i = 0; i < size; i++)
    {
        string name = getCharacter()[i].nameGetter();
        int num = getCharacter()[i].numOfLandsGetter();
        for (int j = 0; j < num;)
        {
            // incrementing j is important point since we have 2nd loop: while
            Land *tmp = getCharacter()[i].getLands();
            while (tmp->next != NULL)
            {
                if (tmp->nameGetter() == land_name)
                    return i;
                tmp = tmp->next;
                j++;
            }
            if (tmp->nameGetter() == land_name)
                return i;
            j++;
        }
    }
    // returns -1 if there is no land named user input. checks in main
    return -1;
}

/* adds character to the characterList:
1- increment size by one
2- create new characters array & assign values
3- set new character array
*/
void CharacterList::addCharacter(Character &toadd)
{
    size++;
    //Character *deleteit = characters;
    Character *temp_characters = new Character[size];
    for (int i = 0; i < size - 1; i++)
        temp_characters[i] = characters[i];

    temp_characters[size - 1].nameSetter(toadd.nameGetter());
    temp_characters[size - 1].goldSetter(toadd.goldGetter());
    temp_characters[size - 1].mpwSetter(toadd.mpwGetter());
    temp_characters[size - 1].numOfLandSetter(toadd.numOfLandsGetter());
    temp_characters[size - 1].landsHeadSetter(toadd.getLands());

    delete[] characters;
    characters = temp_characters;
}
// delete character
void CharacterList::delCharacter(int index)
{
    for (int j = index; j < size - 1; j++)
        characters[j] = characters[j + 1];
    //delete &characters[size - 1];
    size--;
}
