#include "DiceList.h"

// Build dice list and set number of sides each die
// in the list will contain and the number of dice
// numSides is not given a default here because
// that is the responsibility of the DiceType class
// Post: DiceList initialized with numDice number of diceType
// objects stored, each with numSides number of sides.
DiceList::DiceList(int yourNumDice, int yourNumSides)
{
    // Allocate memory for array
    diceArr = new DiceType[yourNumDice];
    // Update value of numDice
    numDice = yourNumDice;

    // Set sides of dice according to yourNumDice formal parameter
    for (int i=0; i < yourNumDice; i++)
    {
        diceArr[i].setNumSides(yourNumSides);
    }
}


// Set number of dice and allow them to receive default values
// cf DiceType spec
// Post: DiceList contains yourNumDice number of DiceType objects
DiceList::DiceList(int yourNumDice)
{
    // Allocate memory for array, allow default diceType currVal to be used
    diceArr = new DiceType[yourNumDice];
    // Update value of numDice
    numDice = yourNumDice;
}


// Copy constructor
// Post: current object receives the number of DiceType objects,
// with the same values and ordering, as otherDiceList
DiceList::DiceList (const DiceList &other)
{
    // Make sure current memory is deallocated
    delete[] diceArr;
    // Allocate array according to size of other's array
    numDice  = other.numDice;
    diceArr = new DiceType[numDice];
    // Copy values of all dice in other to dice in our array
    // note: our numDice and other's numDice are equal at this point
    for (int i = 0; i < numDice; i++)
    {
        diceArr[i].setCurrVal( other.diceArr[i].getCurrVal() );
    }
}

// Destructor
// Post: dynamic memory is deallocated
DiceList::~DiceList()
{
    // Deallocate dynamic array of dice
    delete[] diceArr;
}

// Gets number of dice in the list
// Post: returns numDice property
int DiceList::getNumDice() { return numDice; }

// Rolls all dice in the list
// Post: all dice have had their .roll method called. Cf DiceType spec
void DiceList::rollAll()
{
    for (int i = 0; i < numDice; i++)
    {
       diceArr[i].roll();
    }
}

// Get a pointer to the nth die in the list
// NOTE: will not throw exception if index is < 0
// Post: returns a memory address for values of n that are in bounds,
//       returns nullptr if n is out of bounds.
DiceType* DiceList::getNthDie(int n)
{
    // Check if caller's index is out of bounds
    if (n < 0 || n >= numDice)
        return nullptr;
    // If ok, return memory address
    return &diceArr[n];
}
