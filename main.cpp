#include <iostream>
#include <cassert>
#include "DiceType.h"
#include "DiceList.h"
#include "DiceRollUi.h"

using namespace std;

void testDiceType();
void testDiceList();

int main()
{

//    testDiceType();
//    testDiceList();

    DiceRollUi game;
    game.init();
    game.Menu();
    cout << endl;
    game.farewell();

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
    // Do a duck type check for DiceType with the getNumSides method
    assert(li->getNthDie(1) != nullptr);
    assert(li->getNthDie(1)->getNumSides() == 6);


    // Test setLength
    delete li;
    // Resize down from positive
    li = new DiceList(7, 6);
    li->getNthDie(0)->setCurrVal(3);
    li->getNthDie(1)->setCurrVal(2);

    li->setNumDice(3);
    assert(li->getNumDice() == 3);
    assert(li->getNthDie(0)->getCurrVal() == 3 );
    assert(li->getNthDie(1)->getCurrVal() == 2 );
    assert(li->getNthDie(2)->getCurrVal() == 6 );

    // Resize up from positive
    delete li;
    // Preserves an default numsides for new dice
    li = new DiceList(2);
    li->setNumDice(4);
    assert(li->getNumDice() == 4);
    assert(li->getNthDie(3)->getNumSides() == DiceType::DEFAULT_NUM_SIDES);

    // Preserves a set defaultNumSides for new dice
    li->setDefaultNumSides(8);
    li->setNumDice(6);
    assert(li->getNthDie(5)->getNumSides() == 8 );

    // Resize up from zero
    delete li;
    li = new DiceList;
    li->setNumDice(5);
    assert(li->getNthDie(4)->getNumSides() == DiceType::DEFAULT_NUM_SIDES);

    // Resize down to zero
    delete li;
    li = new DiceList(5);
    li->setNumDice(0);
    assert(li->getNumDice() == 0);
    assert(li->getNthDie(0) == nullptr);

}
