#include <iostream>
#include <iomanip>
#include <cassert>
#include "DiceType.h"
#include "DiceList.h"

// #include "assertions.h"

using namespace std;

void testDiceType();
void testDiceList();

int main()
{
    srand(time(nullptr));
    cout << "Hello world!" << endl;

    // While user does not quit

    // Prompt for number of dice or to quit

        // Build list

        // roll all die

        // print results

    testDiceType();
    testDiceList();

    return 0;
}

// Development testing
void testDiceType()
{
    // Test DiceType

    DiceType foo;

    // Foo
    assert( foo.getNumSides() == 6  );
    assert( foo.getCurrVal() == 6);

    // Rolls should assign currVal
    assert(foo.roll() == foo.getCurrVal());

    // Rolls should be between 1 and numSides
    int roll = foo.roll();
    assert( roll > 0 && roll <= foo.getNumSides() );


    // numSides and value should be set when die numSides is changed
    foo.setNumSides(18);
    assert (foo.getNumSides() == 18);
    assert (foo.getCurrVal() == 18);

    // Rolls should be between 1 and numSides
    for (int i = 0; i < 40; i++)
    {
        foo.roll();
        assert( foo.getCurrVal() > 0 && foo.getCurrVal() <= foo.getNumSides() );
    }

}

// Development testing
void testDiceList()
{
    DiceList* li = new DiceList(4, 3);
    delete li;
    li = new DiceList(4,18);

    li->rollAll();
    cout << li->getNumDice() << " dice in list" << endl;
    for (int i = 0; i < li->getNumDice(); i++)
    {
        cout << li->getNthDie(i)->getCurrVal() << endl;
    }

    // Copy constructor
    DiceList* second = new DiceList(16); // 16 != 18, so this will check resizing

    second = li;
    // Same number of dice
    assert(second->getNumDice() == li->getNumDice());
    // Dice share values
    for(int i =0; i<second->getNumDice(); i++)
    {
        assert(second->getNthDie(i)->getCurrVal() == li->getNthDie(i)->getCurrVal());
    }


    // getNthDie tests
    delete li;
    li = new DiceList(4);
    // returns nullptr for out of bounds
     assert(li->getNthDie(44) == nullptr);
    // A few indirect ways to check that it functions properly
    // and returns an actual object
    // In JS, I would do a typeof check
    assert(li->getNthDie(1) != nullptr);
    assert(li->getNthDie(1)->getNumSides() == 6);


}
