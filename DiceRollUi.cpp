#include "DiceRollUi.h"
#include "DiceList.h"
#include "DiceType.h"
#include <iostream>
#include <limits>

using namespace std;

DiceRollUi::DiceRollUi()
{
    //ctor
}

void DiceRollUi::init()
{
    int initNumDice;  // Specify how many dice to start with
    int initNumSides; // Specify how many sides each die in the list should have

    AsciiArt(); // Something nice to look at and prompt user's imagination

    // Greet
    cout << "Hello, player! This game simulates rolling a (potentially very large)\n"
    << "handful of dice that have a number of sides you specify and can change. Try it out!\n\n";

    cout << "How many dice should be in the list initially?\n"
        << " (You can change this later.)\n";
    getInt(initNumDice, 0, INT_MAX);
    dice.setNumDice(initNumDice);

    // Prompt number of sides each die should have
    // Meet preconditions of setNumSides and SetDefaultNumSides
    // for having effect by getting only positive integers
    cout << "\nHow many sides should the dice have initially?"
        << " (You can change this later, too.)\n";
    getInt(initNumSides, DiceType::MIN_NUM_SIDES, INT_MAX);

    // Set number of sides with value obtained from user
    dice.setNumSides(initNumSides);
    dice.setDefaultNumSides(initNumSides);

    // Check for Easter egg
    EasterEggCoins(initNumSides);

    // Beginning with a rolled list, rather than a list all the same number,
    // the number of sides they have, is more intuitive for the user.
    dice.rollAll();

    cout << endl << "Your current role and the dice's current number of sides are shown\n"
        << "after every command. Try rolling the dice!\n\n";

}

void DiceRollUi::Menu()
{
    char choice = 'z';  // Initialized as something other than a menu option
    int integerInput;   // Used when the user is prompted for an integer

    // Collect and execute user commands until the user chooses the quit option from the menu
    while (choice != 'Q') {
        cout << endl;
        // Show how many sides are on the dice
        cout << "Number of sides: " << dice.getDefaultNumSides() << endl;

        // Display dice values
        cout << "Current roll: ";
        dice.printList();
        cout << endl;   // Formatting; printList does not use endline

        // prompt for choice
        cout << "Choose what to do next:\n"
            << "[r] Roll dice\n"
            << "[n] change number of dice\n"
            << "[s] change the number of sides on the dice\n"
            << "[q]uit\n";
        // GetOption
        cin >> choice;
        // Serialize choice
        choice = toupper(choice);

        // Execute action based on option chosen
        switch (choice) {

        // Roll dice
        case 'R':
            dice.rollAll(); // Roll all dice in the list
            break;

        // Change number of dice
        case 'N':
            cout << "Changing # of dice.\n";    // Feedback
            getInt(integerInput, 0, INT_MAX);   // Get a valid integer
            dice.setNumDice(integerInput);      // Change number of dice
            break;

        // Change number of sides on dice
        case 'S':
            cout << "Changing # of sides on the dice (some dice's rolls may change).\n";
            getInt(integerInput, DiceType::MIN_NUM_SIDES, INT_MAX);
            dice.setNumSides(integerInput);         // Set number of sides for current dice
            dice.setDefaultNumSides(integerInput);  // Set number of sides for any dice added later
            // Check easter egg
            EasterEggCoins(integerInput);

            break;

        // User quits
        case 'Q':
            break;  // Will fall out of loop

        // Invalid entry
        default:
            cout << "Invalid entry. Please enter an option from the menu.\n\n"; // prompt
            cin.ignore(999, '\n'); // Ignore any other characters in cin
        }
    }
}

void DiceRollUi::getInt(int& i, int lowerBound, int upperBound) {
    cout << "Enter an integer: ";
    cin >> i;
    while (!cin || i < lowerBound || i > upperBound) {
        if (!cin) {
            cin.clear();
            cin.ignore(999, '\n');
        }
        cout << "Invalid entry. Please enter an integer from (and including) "
            << lowerBound << " to (and including) " << upperBound << ": ";
        cin >> i;
    }
}

void DiceRollUi::EasterEggCoins(int i) {
    if (i == 2) {
        system("cls");
        cout << "Flipping coins?\n";
        system("pause");
    }
}

void DiceRollUi::farewell() {
    // Bid farewell
    cout << "**** Thank you for playing! ****\n\n";
}

void DiceRollUi::AsciiArt()
{
    cout
   << "                                  \n"
   << "        .-------.    ______       \n"
   << "       /   o   /|   /\\     \\    \n"
   << "      /_______/o|  /o \\  o  \\   \n"
   << "      | o     | | /   o\\___ _\\  \n"
   << "      |   o   |o/ \\o   /o    /   \n"
   << "      |     o |/   \\ o/  o  /        Art by Joan G. Stark              \n"
   << "      '-------'     \\/____o/  jgs    www.asciiart.eu/miscellaneous/dice\n"
   << endl;

}
