#ifndef DICETYPE_H
#define DICETYPE_H

// Class that models a dice with a variable number of sides.
class DiceType
{
    public:
        // Default number of sides a DiceType object will have
        static const int DEFAULT_NUM_SIDES = 6;
        static const int MIN_NUM_SIDES = 2;

        // Default constructor
        // Pre:
        // Post: numSides and currVal is set to the value of DEFAULT_NUM_SIDES constant
        DiceType();

        // Constructor to set numSides during initialization
        // Pre: yourNumSides contains number of sides to give DiceType object
        // Post: new DiceType object is init'd with yourNumSides number of sides
        //       currVal is set to yourNumSides if yourNumSides > 1
        //       if yourNumSides is < 2, DiceType::DEFAULT_NUM_SIDES is set for numSides
        DiceType(/*IN*/ int yourNumSides);

        // Simulates die roll; changes the currVal to pseudorandom number
        // Pre:  object instantiated
        // Post: srand is seeded if it wasn't already seeded by a DiceType
        //       currVal is changed
        //       returns rolled value
        int roll();

        // Getter for currVal, the current "face-up" value on the die.
        // Pre:  object instantiated
        // Post: returns value of currVal
        int getCurrVal() const;

        // Sets current face value of die
        // Pre: yourCurrVal contains roll value to give to DiceType object
        // Post: currVal receives value of yourCurrVal
        void setCurrVal(/*IN*/ int yourCurrVal);

        // Returns number of sides the DiceType object has
        // Pre: object instantiated
        // Post: returns numSides member variable
        int getNumSides() const;

        // Sets the number of sides the die has
        // Pre: yourNumSides contains a value to set as the number of sides the DiceType has
        // Post: if yourNumSides is < DiceType::MIN_NUM_SIDES, this method has no effect and returns false
        //       else, numSides is set to yourNumSides
        //       and if currVal > yourNumSides, currVal is set to yourNumSides
        //       and method returns true
        bool setNumSides(/*IN*/ int yourNumSides);

    private:
        // randSeeded indicates whether this class has seeded random number generator
        // If random number generator has not been seeded, it will be seeded
        // before any calls to the .roll method
        //
        // This comes at the expense of storing a boolean value and checking
        // it every time the .roll method is called, but it saves boilerplate
        // for clients.
        static bool randSeeded;
        int numSides;   // Number of sides each die will have
        int currVal;    // Value currently rolled
};



#endif // DICETYPE_H
