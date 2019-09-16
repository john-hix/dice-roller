#ifndef DICELIST_H
#define DICELIST_H

#include "DiceType.h"

// Abstraction of a list of dice
class DiceList
{
    public:
        // Default constructor
        // Pre:
        // Post: numSides and currVal is set to the value of DiceType::DEFAULT_NUM_SIDES constant
        DiceList();
        // Build dice list and set number of sides each die
        // in the list will contain and the number of dice
        // numSides is not given a default here because
        // that is the responsibility of the DiceType class
        // Post: DiceList initialized with numDice number of diceType
        //   objects stored, each with numSides number of sides.
        //       defaultNumSides receives the value of numsides
        DiceList(/*IN*/ int numDice, /*IN*/ int numSides);
        // Set number of dice and allow them to receive default values
        // cf DiceType spec
        // Post: DiceList contains yourNumDice number of DiceType objects
        DiceList(/*IN*/ int yourNumDice);
        // Copy constructor
        // Pre:  otherDiceList is instantiated
        // Post: current object receives the number of DiceType objects,
        // with the same values and ordering, as otherDiceList
        DiceList (/*IN*/ const DiceList &otherDiceList);
        // Destructor
        // Post: dynamic memory is deallocated
        ~DiceList();
        // Gets number of dice in the list
        // Pre: object instantiated
        // Post: returns numDice property
        int GetNumDice() const;
        // Changes number of dice in the list, either removing or adding them
        //as necessary
        // Pre:  n must be positive or zero for this to have any effect
        // Post: diceArr is resized if n did not match numDice.
        //       new DiceType objects were instantiated with default values if needed
        void SetNumDice(/*IN*/ int n);
        // Rolls all dice in the list
        // Pre: object instantiated; no need to actually have dice
        // Post: all dice have had their .roll method called. Cf DiceType spec
        void RollAll();
        // Get a pointer to the nth die in the list, zero-based index
        // Pre: object instantiated
        // NOTE: will not throw exception if index is < 0
        // Post: returns a memory address for values of n that are in bounds,
        //       returns nullptr if n is out of bounds.
        DiceType* GetNthDie(/*IN*/ int n);

        // Sets number of sides each die in the list has
        // Pre:
        // Post: each die has n number of sides if n > 1
        //       the currVal of each die in the list matches its number of sides
        //       if n > 1, defaultNumSides is set, and dice added to list in the future will
        //      have n number of sides
        bool SetNumSides(int n);

        // Gets default number of sides any new dice added to the list will receive
        // Pre:  object instantiated
        // Post: returns value of defaultNumSides member variable
        int GetDefaultNumSides() const;

        // Sets default number of sides to give any new dice added to the list
        // Post: if yourDefaultNumSides is < DiceType::MIN_NUM_SIDES
        //          returns false
        //       else, defaultNumSides receives the value of yourDefaultNumSides
        //          defaultNumSides is set to yourDefaultNumSides
        //          returns true
        bool SetDefaultNumSides(/*IN*/ int yourDefaultNumSides);

        // Print roll values of the list's dice to cout, giving line break every 10 dice
        // Pre:  object instantiated
        // Post: diceArr's DiceType's values are all printed to cout
        // with a line break per 20 dice values printed,
        // or the string "No dice in list!" is printed. Both include a leading newline
        void PrintList() const;

  private:
      DiceType* diceArr;   // Dynamic array of dice
      int numDice;         // Number of dice in the list
      int defaultNumSides; // Number of sides to use with new dice by default
};

#endif // DICELIST_H
