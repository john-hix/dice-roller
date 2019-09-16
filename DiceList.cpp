#include "DiceList.h"
#include "DiceType.h"
#include <iostream>

using namespace std;

DiceList::DiceList()
{
    diceArr = nullptr;
    numDice = 0;
    defaultNumSides = DiceType::DEFAULT_NUM_SIDES;
}


// Build dice list and set number of sides each die
// in the list will contain and the number of dice
// numSides is not given a default here because
// that is the responsibility of the DiceType class
// Post: DiceList initialized with numDice number of diceType
// objects stored, each with numSides number of sides.
DiceList::DiceList(/*IN*/ int yourNumDice, /*IN*/ int yourNumSides)
{
    // Allocate memory for array
    diceArr = new DiceType[yourNumDice];
    // Update value of numDice
    numDice = yourNumDice;

    // Attempt to set defaultNumSides; if validation fails,
    // use the default from DiceType class
    if (setDefaultNumSides(yourNumSides) == false)
        defaultNumSides = DiceType::DEFAULT_NUM_SIDES;

    // Set sides of dice according to yourNumDice formal parameter
    for (int i=0; i < yourNumDice; i++)
    {
        diceArr[i].setNumSides(defaultNumSides);
    }
}


// Set number of dice and allow them to receive default values
// cf DiceType spec
// Post: DiceList contains yourNumDice number of DiceType objects
DiceList::DiceList(/*IN*/ int yourNumDice)
{
    // Allocate memory for array, allow default diceType currVal to be used
    diceArr = new DiceType[yourNumDice];
    // Update value of numDice
    numDice = yourNumDice;
    defaultNumSides = DiceType::DEFAULT_NUM_SIDES;
}

// Copy constructor
// Pre:  otherDiceList is instantiated
// Post: current object receives the number of DiceType objects,
// with the same values and ordering, as otherDiceList
DiceList::DiceList (/*IN*/ const DiceList &other)
{
    // Make sure current memory is deallocated
    delete[] diceArr;
    // Allocate array according to size of other's array
    numDice  = other.numDice;
    if (numDice > 0)
        diceArr = new DiceType[numDice];
    else
        diceArr = nullptr;
    // Copy values of all dice in other, if any, to dice in our array
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
// Pre: object instantiated
// Post: returns numDice property
int DiceList::getNumDice() const { return numDice; }

// Changes number of dice in the list, either removing or adding them
//as necessary
// Pre:  n must be positive or zero for this to have any effect
// Post: diceArr is resized if n did not match numDice.
//       new DiceType objects were instantiated with default values if needed
void DiceList::setNumDice(/*IN*/ int n)
{
    DiceType* newDiceArr;

    // Restrict domain of values that have an effect
    // Can't resize to negative; no need to do anything if size already matches
    if (n < 0 || n == numDice) {
        return;
    }

    // Create destination array or make null if no array needed
    // Subsequent checks on n should avoid trying to access array indices on
    // nullptr
    if (n > 0)
        newDiceArr = new DiceType [n];
    else
        newDiceArr = nullptr;

    // Preserve as many dice values and numSides as possible by copying up to as many
    // as were in the old array but nor more than what will fit in the new array
    for (int i= 0; i < n && i < numDice; i++) {
        newDiceArr[i].setNumSides( diceArr[i].getNumSides() );
        newDiceArr[i].setCurrVal( diceArr[i].getCurrVal() );
    }

    // Set any newly created diceList members with default numSides
    for (int i = numDice -1; i < n; i++) {
        newDiceArr[i].setNumSides(defaultNumSides);
    }

    // Manage memory (not always necessary, say n < diceArr length, but managing when to
    // resize seems out of scope for this assignment and its performance requirements)
    delete [] diceArr;
    diceArr = newDiceArr;

    // Update numDice
    numDice = n;

} // end DiceList::setNumDice

// Rolls all dice in the list
// Pre: object instantiated; no need to actually have dice
// Post: all dice have had their .roll method called. Cf DiceType spec
void DiceList::rollAll()
{
    // Roll all dice in list, if any
    for (int i = 0; i < numDice; i++)
    {
       diceArr[i].roll();
    }

}

// Get a pointer to the nth die in the list, zero-based index
// Pre: object instantiated
// NOTE: will not throw exception if index is < 0
// Post: returns a memory address for values of n that are in bounds,
//       returns nullptr if n is out of bounds.
DiceType* DiceList::getNthDie(/*IN*/ int n)
{
    // Check if caller's index is out of bounds
    if (n < 0 || n >= numDice)
        return nullptr;
    // If ok, return memory address
    return &diceArr[n];
}

// Sets number of sides each die in the list has
// Pre:
// Post: each die has n number of sides if n > 1
//       the currVal of each die in the list matches its number of sides
//       if n > 1, defaultNumSides is set, and dice added to list in the future will
//      have n number of sides
bool DiceList::setNumSides(int n) {
    if (setDefaultNumSides(n)) {    // Attempt to set as the default
        for (int i = 0; i < numDice; i++) {
            diceArr[i].setNumSides(n);  // Should succeed if n passed
                                        // setDefaultNumSides' validation.
        }
        return true;
    }
    return false;
}

// Gets default number of sides any new dice added to the list will receive
// Pre:  object instantiated
// Post: returns value of defaultNumSides member variable
int DiceList::getDefaultNumSides() const
{
    return defaultNumSides;
}

// Sets default number of sides to give any new dice added to the list
// Post: if yourDefaultNumSides is < DiceType::MIN_NUM_SIDES
//          returns false
//       else, defaultNumSides receives the value of yourDefaultNumSides
//          defaultNumSides is set to yourDefaultNumSides
//          returns true
bool DiceList::setDefaultNumSides(/*IN*/ int yourDefaultNumSides)
{
    if (yourDefaultNumSides >= DiceType::MIN_NUM_SIDES) {
        // Dice can only have more than 1 side; cf DiceType spec
        defaultNumSides = yourDefaultNumSides;
        return true;
    }
    return false;
}

// Print roll values of the list's dice to cout, giving line break every 10 dice
// Pre:  object instantiated
// Post: diceArr's DiceType's values are all printed to cout
// with a line break per 20 dice values printed,
// or the string "No dice in list!" is printed. Both include a leading newline
void DiceList::printList() const {
    // Check if list is empty and display message
    // Newline because the mod-determined line break
    // Below adds a new line i == 0. Do this for empty list to match formatting
    if (numDice < 1)
        cout << "\nNo dice in list!";

    // Print to cout, giving line break every 10 dice
    for (int i =0; i < numDice; i++) {
        if (i % 20 == 0) {
            cout << endl;
        }
        cout << diceArr[i].getCurrVal() << ' ';
    }
}

