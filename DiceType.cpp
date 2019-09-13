#include "DiceType.h"
#include <cstdlib>  // rand, srand funcs
#include <ctime>    // time func

bool DiceType::randSeeded = false;

// Default constructor
// Post: numSides and currVal is set to 6
DiceType::DiceType()
{
    numSides = 6;
    currVal  = 6;
}

// Constructor to set numSides during initialization
// Post: new DiceType object is init'd with yourNumSides number of sides
//       currVal is set to yourNumSides if yourNumSides > 1
//       if yourNumSides is < 1, a default value of 6 is set for numSides
DiceType::DiceType(int yourNumSides)
{
    setNumSides(yourNumSides);
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
// Post: numSides is set to the value passed
//       if yourNumSides is < 1, a default value of 6 is set for numSides
//       currVal is set to numSides
void DiceType::setNumSides(int yourNumSides)
{
    if (yourNumSides < 1) {
        yourNumSides = 6;
    }
    numSides = yourNumSides;
    currVal  = yourNumSides;
}


