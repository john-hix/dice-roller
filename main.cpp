#include <iostream>
#include <iomanip>
#include "DiceType.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    // While user does not quit

    // Prompt for number of dice or to quit

        // Build list

        // roll all die

        // print results



    // Test DiceType


    DiceType foo;
    cout << "Instantiated DiceType\n";
    cout << foo.getNumSides() << " sides\n";
    cout << foo.getCurrVal() << " currVal" << endl;
    cout << foo.roll() << " rolled val\n";
    cout << foo.getCurrVal() << " currVal";
    foo.setNumSides(18);
    cout << foo.getNumSides() << " sides\n";
    cout << foo.getCurrVal() << "currVal" << endl;

    cout << "Rolls:\n\n";
    for (int i = 0; i < 40; i++) {
        for (int j = 0; j < 10; j++)
            cout << setw(5) << foo.roll() << ' ';
        cout << endl;
    }

    return 0;
}
