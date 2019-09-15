#include "DiceType.h"
#include <cstdlib>  // rand, srand funcs
#include <ctime>    // time func

bool DiceType::randSeeded = false;

// Default constructor
// Post: numSides and currVal is set to value of DiceType::DEFAULT_NUM_SIDES
DiceType::DiceType()
{
    numSides = DiceType::DEFAULT_NUM_SIDES;
    currVal  = numSides;
}

// Constructor to set numSides during initialization
// Post: new DiceType object is init'd with yourNumSides number of sides
//       currVal is set to yourNumSides if yourNumSides > 1
//       if yourNumSides is < 2, DiceType::DEFAULT_NUM_SIDES is set for numSides
DiceType::DiceType(int yourNumSides)
{
    if ( !setNumSides(yourNumSides) )
        numSides = DiceType::DEFAULT_NUM_SIDES;

}

// Simulates die roll; changes the currVal to pseudorandom number
// Pre:  object instantiated
// Post: srand is seeded if it wasn't already seeded by a DiceType
//       currVal is changed
//       returns rolled value
int DiceType::roll()
{
    // Check if rand is seeded; if not, do it
    if ( ! DiceType::randSeeded ) {
        srand(time(nullptr));
        DiceType::randSeeded = true;
    }
    // Assign currVal a random number between 1 and numSides
    currVal = rand() % numSides + 1;

    return currVal;
}

// Gets the current "face-up" value on the die. See constructor
// for default value directly after instantiation.
int DiceType::getCurrVal() { return currVal; }

// Sets current face value of die
// Pre:
// Post: currVal receives value of yourCurrVal
void DiceType::setCurrVal(int yourCurrVal)
{
    currVal = yourCurrVal;
}

// Returns number of sides the die has
// Post: returns numSides member variable
int DiceType::getNumSides() { return numSides; }


// Sets the number of sides the die has
// Post: if yourNumSides is < 2, this method has no effect and returns false
//       else, numSides is set to yourNumSides
//       and currVal is set to numSides
//       and method returns true
bool DiceType::setNumSides(int yourNumSides)
{
    if (yourNumSides > 1) {
        numSides = yourNumSides;
        currVal  = yourNumSides;
        return true;
    }
    return false;
}


