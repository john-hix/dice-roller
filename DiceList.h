#ifndef DICELIST_H
#define DICELIST_H

#include "DiceType.h"

// Abstraction of a list of dice
class DiceList
{
    public:
        DiceList();
        // Build dice list and set number of sides each die
        // in the list will contain and the number of dice
        // numSides is not given a default here because
        // that is the responsibility of the DiceType class
        // Post: DiceList initialized with numDice number of diceType
        //   objects stored, each with numSides number of sides.
        //       defaultNumSides receives the value of numsides
        DiceList(int numDice, int numSides);
        // Set number of dice and allow them to receive default values
        // cf DiceType spec
        // Post: DiceList contains yourNumDice number of DiceType objects
        DiceList(int yourNumDice);
        // Copy constructor
        // Post: current object receives the number of DiceType objects,
        // with the same values and ordering, as otherDiceList
        DiceList (const DiceList &otherDiceList);
        // Destructor
        // Post: dynamic memory is deallocated
        ~DiceList();
        // Gets number of dice in the list
        // Post: returns numDice property
        int getNumDice();
        void setNumDice(int n);
        // Rolls all dice in the list
        // Post: all dice have had their .roll method called. Cf DiceType spec
        void rollAll();
        // Get a pointer to the nth die in the list
        // NOTE: will not throw exception if index is < 0
        // Post: returns a memory address for values of n that are in bounds,
        //       returns nullptr if n is out of bounds.
        DiceType* getNthDie(int n);
        // Gets default number of sides any new dice added to the list will receive
        // Post: returns value of defaultNumSides member variable
        int getDefaultNumSides();
        // Sets default number of sides to give any new dice added to the list
        // Post: if yourDefaultNumSides is < 2
        //          no effect because dice can only have > 1 side (cf DiceType spec)
        //          returns false
        //       else, defaultNumSides receives the value of yourDefaultNumSides
        //          defaultNumSides is set to yourDefaultNumSides
        //          returns true
        bool setDefaultNumSides(int yourDefaultNumSides);

  private:
      DiceType* diceArr;   // Dynamic array of dice
      int numDice;         // Number of dice in the list
      int defaultNumSides; // Number of sides to use with new dice by default
};

#endif // DICELIST_H
