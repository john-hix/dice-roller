#include "DiceType.h"
#include <cstdlib>  // rand, srand funcs
#include <ctime>    // time func

bool DiceType::randSeeded = false;

// Default constructor
// Pre:
// Post: numSides and currVal is set to the value of DiceType::DEFAULT_NUM_SIDES constant
DiceType::DiceType()
{
    numSides = DiceType::DEFAULT_NUM_SIDES;
    currVal  = numSides;
}

// Constructor to set numSides during initialization
// Pre: yourNumSides contains number of sides to give DiceType object
// Post: new DiceType object is init'd with yourNumSides number of sides
//       currVal is set to yourNumSides if yourNumSides > 1
//       if yourNumSides is < 2, DiceType::DEFAULT_NUM_SIDES is set for numSides
DiceType::DiceType(/*IN*/ int yourNumSides)
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

// Getter for currVal, the current "face-up" value on the die.
// Pre:  object instantiated
// Post: returns value of currVal
int DiceType::getCurrVal() const { return currVal; }

// Sets current face value of die
// Pre: yourCurrVal contains roll value to give to DiceType object
// Post: currVal receives value of yourCurrVal
void DiceType::setCurrVal(/*IN*/ int yourCurrVal)
{
    currVal = yourCurrVal;
}

// Returns number of sides the DiceType object has
// Pre: object instantiated
// Post: returns numSides member variable
int DiceType::getNumSides() const { return numSides; }


// Sets the number of sides the die has
// Pre: yourNumSides contains a value to set as the number of sides the DiceType has
// Post: if yourNumSides is < DiceType::MIN_NUM_SIDES, this method has no effect and returns false
//       else, numSides is set to yourNumSides
//       and if currVal > yourNumSides, currVal is set to yourNumSides
//       and method returns true
bool DiceType::setNumSides(/*IN*/ int yourNumSides)
{
    if (yourNumSides >= DiceType::MIN_NUM_SIDES) {
        // Check if the value needs to be sized down
        if (yourNumSides < currVal) {
            currVal  = yourNumSides;
        }
        numSides = yourNumSides;
        return true;
    }
    return false;
}


