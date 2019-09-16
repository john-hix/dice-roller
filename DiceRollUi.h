#ifndef DICEROLLUI_H
#define DICEROLLUI_H
#include "DiceList.h"

// The user interface to the DiceList and DiceType classes in the game
class DiceRollUi
{
    public:
        // Default constructor
        // Pre: none
        // Post: DiceList's default constructor is called
        DiceRollUi();
        // Starts game by greeting user, describing game,
        //and gathering initial dice count and the number of sides the dice should have
        // Pre:  object instantiated
        // Post: A fair amount of console output
        //       user has been prompted for and dice has received values for numDice and defaultNumSides
        void StartUp();
        // Prompts user for in-game options: rolling dice, resizing array, changing numSides on all dice, quitting
        // Pre:  StartUp has been called
        // Post: Possibly many state changes may have occurred to dice member;
        //       User has quit the game
        void Menu();
        // Prints a thank-you to user for playing the game
        // Pre: none, although calling before end of game would be confusing to the user
        // Post: "Thank you for playing!" is printed to cout
        void Farewell();

    private:
        // Prompts for and validates an integer from lowerbound (inclusive) to upperBound (inclusive)
        // Pre: i is an int variable; lowerBound and upperBound are integers
        // Post: user has been prompted for unit an i in the set [lowerBound, upperBound] is entered
        void GetInt(/*OUT*/ int& i, /*IN*/ int lowerBound, /*IN*/ int upperBound);
        // Prints ASCII-art depicting dice to cout
        // Pre: none
        // Post: nine lines are printed to cout
        void AsciiArt();
        // Clears the screen and asks the user if they mean to flip coins rather than
        //roll dice if they attempt to change the number of dice sides to 2
        // Pre: numDiceSides is integer
        // Post: if numDiceSides is 2, cls and pause have been called
        void EasterEggCoins(/*IN*/ int numDiceSides);
        DiceList dice;  // List of dice used in the game; subject to resizing but not deallocation during gameplay
};

#endif // DICEROLLUI_H
