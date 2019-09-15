#ifndef DICETYPE_H
#define DICETYPE_H

// Class that models a dice with a variable number of sides.
// If random number generator has not been seeded, it will be seeded
// before any calls to the .roll method
//
// This comes at the expense of storing a boolean value and checking
// it every time the .roll method is called, but it saves boilerplate
// for clients.

class DiceType
{
    public:
        // Default number of sides a DiceType object will have
        static const int DEFAULT_NUM_SIDES = 6;

        // Default constructor
        // Post: numSides and currVal is set to the value of DEFAULT_NUM_SIDES constant
        DiceType();

        // Constructor to set numSides during initialization
        // Post: new DiceType object is init'd with yourNumSides number of sides
        //       currVal is set to yourNumSides if yourNumSides > 1
        //       if yourNumSides is < 2, DiceType::DEFAULT_NUM_SIDES is set for numSides
        DiceType(int yourNumSides);

        // Simulates die roll; changes the currVal to pseudorandom number
        // Pre:  object instantiated
        // Post: srand is seeded if it wasn't already seeded by a DiceType
        //       currVal is changed
        //       returns rolled value
        int roll();

        // Gets the current "face-up" value on the die. See constructor
        // for default value directly after instantiation.
        int getCurrVal();

        // Sets current face value of die
        // Pre:
        // Post: currVal receives value of yourCurrVal
        void setCurrVal(int yourCurrVal);

        // Returns number of sides the die has
        // Post: returns numSides member variable
        int getNumSides();

        // Sets the number of sides the die has
        // Post: if yourNumSides is < 2, this method has no effect and returns false
        //       else, numSides is set to yourNumSides
        //       and currVal is set to numSides
        //       and method returns true
        bool setNumSides(int yourNumSides);

    private:
        static bool randSeeded;
        int numSides;   // Number of sides each die will have
        int currVal;    // Value currently rolled
};



#endif // DICETYPE_H
