#ifndef DICETYPE_H
#define DICETYPE_H

// Class that models a dice with a variable number of sides.
// If random number generator has not been seeded, it will be seeded
// before any calls to the .roll method
//
// Example:


class DiceType
{
    public:

        // Default constructor
        // Post: numSides and currVal is set to 6
        DiceType();

        // Constructor to set numSides during initialization
        // Post: new DiceType object is init'd with yourNumSides number of sides
        //       currVal is set to yourNumSides if yourNumSides > 1
        //       if yourNumSides is < 1, a default value of 6 is set for numSides
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

        // Returns number of sides the die has
        // Post: returns numSides member variable
        int getNumSides();

        // Sets the number of sides the die has
        // Post: numSides is set to the value passed
        //       if yourNumSides is < 1, a default value of 6 is set for numSides
        //       currVal is set to numSides
        void setNumSides(int yourNumSides);

    private:
        static bool randSeeded;
        int numSides;   // Number of sides each die will have
        int currVal;    // Value currently rolled
};



#endif // DICETYPE_H
