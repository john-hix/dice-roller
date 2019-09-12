#ifndef DICELIST_H
#define DICELIST_H

#include "DiceType.h"

// List of dice
class DiceList
{
    public:
        DiceList(int numDice, int numSides = 6 );
        ~DiceList();


  private:
      DiceType* diceList;  // Dynamic array of dice
      int numDice;         // Number of dice in the list

};

#endif // DICELIST_H
