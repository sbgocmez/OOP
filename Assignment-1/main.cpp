//////////////////////////////////
/*       Sakine Busra Gocmez    */
/*          150190064           */
//////////////////////////////////

#include <iostream>
#include <fstream>
#include "GreatWarrior.h"
// #include "GreatWarrior.cpp"

/*	Define necessary classes and attributes in GreatWarrior.h and GreatWarrior.cpp */

/*	= Fill in the blanks in this main.cpp file. The parts that you need to implemented are specified below.
    = Please write your code between ///// FILL HERE ///// lines.
    = The expressions you need to print out with cout operation are given in necessary format.
    = You can use them directly by filling the variable parts.
*/

void listCharacters(CharacterList &);
void listLands(CharacterList &);
void readData(string, CharacterList &);
void printGameMenu();
bool endOfTurn(Character &, int);

int main()
{
    cout << "Welcome to the Great Warriors. Create your character and attack other lands to be a great warrior.\n"
         << endl;

    CharacterList charList; // list object to store the characters

    string fileName = "characters.txt"; // read characters.txt file
    readData(fileName, charList);

    /* creating player's character */
    string name, land, general;
    cout << "Enter your name: ";
    cin >> name;

    cout << "Enter name of your capital: ";
    cin >> land;

    cout << "Enter name of your general: ";
    cin >> general;

    ///// FILL HERE /////
    /*  Create your constant general object and your own character object,
        then add your character into characters list */

    Land myLand(land, "village");
    myLand.nextSetter();
    Character myMan(name, 3, 20, 1);
    myMan.addLand(myLand);
    myMan.numOfLandSetter(1);
    charList.addCharacter(myMan);

    const Character myGeneral(general);

    ///// FILL HERE /////

    // In-game loop
    int choice = 0,
        round = 0;
    while (choice != 6)
    {
        printGameMenu();

        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "You have rested in your palace." << endl;
            cout << "You've talked with your general " << myGeneral.NameOfconstGetter() << "." << endl;

            round++;
            break;
        }
        case 2:
        {
            listLands(charList);
            cout << "Enter name of the land to attack." << endl;

            string land;
            cin >> land;

            ///// FILL HERE /////
            // lande sahip olan characterin indexine doner
            int char_index = charList.getLandOwner(land);
            // index != -1 : boyle bir land var
            if (char_index != -1)
            {
                // soldier sayisi karsilastirmasi yapar, karsi taraftan kucukse savasi & askerlerini kaybeder.
                if (myMan.mpwGetter() < charList.getCharacter()[char_index].mpwGetter())
                {
                    cout << "You've lost the battle and " << myMan.mpwGetter() << " manpower." << endl;
                    myMan.mpwSetter(0);
                }
                // karsi taraftan buyukse karsi tarafin asker sayisi kadar askerini kaybeder.
                // kendisine: kendi - karsi, set eder. karsiya 0 set eder.
                else
                {
                    int mpw = myMan.mpwGetter() - charList.getCharacter()[char_index].mpwGetter();
                    myMan.mpwSetter(mpw);
                    // charList.getCharacter()[char_index].mpwSetter(0); i decided to dont assign 0 to asside, on message board:"it is not needed"

                    string holding_name = charList.getCharacter()[char_index].removeLand(land);

                    charList.getCharacter()[char_index].numOfLandSetter(charList.getCharacter()[char_index].numOfLandsGetter() - 1);

                    if (charList.getCharacter()[char_index].numOfLandsGetter() == 0)
                    {
                        //charList.delCharacter(charList.getCharacter()[char_index].nameGetter());
                        charList.delCharacter(char_index);
                    }

                    // add land
                    Land toadd(land, holding_name);
                    myMan.addLand(toadd);
                    // update numOfLands
                    int num_of_land = myMan.numOfLandsGetter() + 1;
                    myMan.numOfLandSetter(num_of_land);
                    cout
                        << "You've won the battle and conquered " << land << "." << endl;
                }
            }
            else
            {
                cout << "There's no land named " << land << "." << endl;
            }
            ///// FILL HERE /////

            round++;
            break;
        }
        case 3:
            cout << "How much manpower do you need? (1 manpower=5 gold)" << endl;

            int order;
            cin >> order;

            ///// FILL HERE /////

            /* Check if you have enough money to get the requested manpower:*/
            if (myMan.goldGetter() >= order * 5)
            {
                int setto_mpw = order + myMan.mpwGetter();
                myMan.mpwSetter(setto_mpw);
                int setto_gld = myMan.goldGetter() - (order * 5);
                myMan.goldSetter(setto_gld);
                cout << "Order successful. You have " << myMan.mpwGetter() << " manpower." << endl;
            }
            else
                cout << "You do not have enough money." << endl;

            ///// FILL HERE /////

            // round++;
            break;
        case 4:
            listCharacters(charList);
            break;
        case 5:
            listLands(charList);
            break;
        case 6:
            return 0;
        default:
            cout << "You entered an invalid value. Try again." << endl;
        }

        ///// FILL HERE /////
        if (choice == 1 || choice == 2)
        {
            if (!endOfTurn(myMan, round))
                break;
        }
        else
            ;
        ///// FILL HERE /////
    }
}

void readData(string fileName, CharacterList &charList)
{

    fstream dataFile(fileName.c_str());

    if (dataFile.is_open())
    {

        string word;
        while (dataFile >> word)
        {

            string name, title;
            int money, manpower, numOfLands;

            name = word;
            dataFile >> manpower;
            dataFile >> money;
            dataFile >> numOfLands;

            ///// FILL HERE /////

            /* Create a new character with read data */
            Character player(name, manpower, money, numOfLands);

            ///// FILL HERE /////

            string landName, holding;

            for (int i = 0; i < numOfLands; i++)
            {
                dataFile >> landName;
                dataFile >> holding;

                ///// FILL HERE /////

                /* Create a new land object with read data and assign the land to the character you have created */
                Land land1(landName, holding);
                player.addLand(land1);

                ///// FILL HERE /////
            }

            ///// FILL HERE /////

            /* Add the character into character list */
            charList.addCharacter(player);

            ///// FILL HERE /////
        }

        dataFile.close();
    }
    else
        cout << "Unable to open the file" << endl;

    return;
}

void printGameMenu()
{
    cout << endl;
    cout << "1. Stay in your palace" << endl;
    cout << "2. Attack to a land" << endl;
    cout << "3. Buy manpower" << endl;
    cout << "4. List characters" << endl;
    cout << "5. List lands" << endl;
    cout << "6. Exit" << endl;
    cout << endl;
}

void listCharacters(CharacterList &charList)
{
    cout << endl;
    ///// FILL HERE /////

    // Print out the names of each character in character list in a loop
    for (int i = 0; i < charList.sizeGetter(); i++)
        cout << charList.getCharacter()[i].nameGetter() << endl;

    ///// FILL HERE /////
}

void listLands(CharacterList &charList)
{
    cout << endl;
    ///// FILL HERE /////

    for (int i = 0; i < charList.sizeGetter(); i++)
    {
        string name = charList.getCharacter()[i].nameGetter();
        int num = charList.getCharacter()[i].numOfLandsGetter();
        if (num == 0)
            i++;
        else
        {
            for (int j = 0; j < num;)
            {
                Land *tmp = charList.getCharacter()[i].getLands();
                while (tmp->next != NULL)
                {
                    cout << tmp->nameGetter() << " " << tmp->holdingGetter() << " owned by " << name << endl;
                    tmp = tmp->next;
                    j++;
                }
                cout << tmp->nameGetter() << " " << tmp->holdingGetter() << " owned by " << name << endl;
                j++;
            }
        }
    }

    ///// FILL HERE /////
    cout << endl;
}

//return a bool value that indicates if the game is over or not.
bool endOfTurn(Character &player, int round)
{
    ///// FILL HERE /////

    //////////// GET TAXES AND FEED SOLDIERS /////////////////////
    int golds_total = player.getTaxes(); // returns golds + taxes
    int feed = player.mpwGetter();
    player.goldSetter(golds_total - feed);
    ////////////////////////////////////////////////////////////

    ////////////// CHECK # LANDS ////////////////////////////////
    if (player.numOfLandsGetter() == 0)
    {
        cout << "You are no longer a great warrior. You survived " << round << " turns." << endl;
        cout << endl;
        cout << "GAME OVER." << endl;
        return 0;
    }
    ////////////////////////////////////////////////////////////

    ////////////// CHECK # MPW ///////////////////////////////////
    if (player.mpwGetter() == 0)
    {
        cout << "You lost one of your lands to rebellions since you don't have enough army." << endl;
        string todelete = "";

        // delete randomly, i delete 2nd element of linked list. it is up to my choice.
        if (player.numOfLandsGetter() > 1)
            todelete = player.getLands()->next->nameGetter();
        else
            todelete = player.getLands()->nameGetter();

        player.removeLand(todelete);
        player.numOfLandSetter(player.numOfLandsGetter() - 1);
    }
    ////////////////////////////////////////////////////////////

    ////////////// CHECK # GOLDS /////////////////////////////////
    if (player.mpwGetter() > player.goldGetter())
    {
        cout << player.mpwGetter() - player.goldGetter() << " soldiers run away from your army because you don't have enough gold to feed them." << endl;
        player.mpwSetter(player.goldGetter());
    }

    ////////////// PRINT STATUS /////////////////////////////////
    cout
        << "Turn " << round << ": "
        << " " << player.nameGetter() << " has " << player.numOfLandsGetter()
        << " land(s), " << player.mpwGetter() << " manpower and " << player.goldGetter() << " golds." << endl;

    return 1;

    ///// FILL HERE /////
}
