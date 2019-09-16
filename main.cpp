// Dice Roller
// John Hicks
// 9/15/2019
// CSC 210
//
// This program is a game that simulates the user's rolling a (potentially very large)
// handful of dice that have a number of sides that he/she specifies and can change.

#include <iostream>
#include "DiceType.h"
#include "DiceList.h"
#include "DiceRollUi.h"

using namespace std;

int main()
{

    DiceRollUi game;
    game.init();
    game.Menu();
    cout << endl;
    game.farewell();

    return 0;
}
