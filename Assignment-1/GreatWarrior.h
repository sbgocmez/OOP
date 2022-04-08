//////////////////////////////////
/*       Sakine Busra Gocmez    */
/*          150190064           */
//////////////////////////////////
#ifndef GreatWarrior_H
#define GreatWarrior_H
#include <stdio.h>
#include <iostream>

using namespace std;

// i put getter/setters as inline

class Land
{
private:
    string name;
    string holding;

public:
    // to hold next element of land linkedlist.
    // there wasnt any criteria about setting *next as private or public attribute, so i set it as public to ease my work.
    Land *next;
    Land(string = " ", string = " "); // constructor, takes values optinioally
    Land(const Land &);               // copy constructor
    ~Land();
    string nameGetter() const
    {
        return name;
    }
    string holdingGetter()
    {
        return holding;
    }
    void nextSetter()
    {
        next = NULL;
    }
};

class Character
{
private:
    string name;
    int manpower;
    int gold;
    int numOfLands;
    Land *lands;

public:
    Character(string = " ", int = 0, int = 0, int = 0, Land * = NULL);
    Character(const Character &);
    ~Character();
    int getTaxes();
    void addLand(const Land &);
    string removeLand(string);

    string nameGetter()
    {
        return name;
    }
    string NameOfconstGetter() const
    {
        return name;
    }
    int mpwGetter()
    {
        return manpower;
    }
    int numOfLandsGetter()
    {
        return numOfLands;
    }
    int goldGetter()
    {
        return gold;
    }
    Land *getLands()
    {
        return lands;
    }
    // setters will be used when adding a character
    void nameSetter(string land_name)
    {
        name = land_name;
    }
    void goldSetter(int numgold)
    {
        gold = numgold;
    }
    void mpwSetter(int mpw)
    {
        manpower = mpw;
    }
    void numOfLandSetter(int numofland)
    {
        numOfLands = numofland;
    }
    void landsHeadSetter(Land *head)
    {
        lands = head;
    }
};

class CharacterList
{
private:
    int size = 0;
    Character *characters;

public:
    CharacterList();
    ~CharacterList();
    friend void listCharacters();
    friend void listLands();
    void addCharacter(Character &);
    void delCharacter(int);
    int getLandOwner(string);
    Character &getPlayer(string);
    // this function gets the character array, i used a lot when accessing characters
    Character *getCharacter()
    {
        return characters;
    }
    int sizeGetter()
    {
        return size;
    }

    void sizeSetter(int a)
    {
        size = a;
    }
};

#endif
