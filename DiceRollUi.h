#ifndef DICEROLLUI_H
#define DICEROLLUI_H
#include "DiceList.h"

class DiceRollUi
{
    public:
        DiceRollUi();
        void init();
        void Menu();
        void farewell();

    private:
        void getInt(int& i, int lowerBound, int upperBound);
        void AsciiArt();
        void EasterEggCoins(int i);
        DiceList dice;
};

#endif // DICEROLLUI_H
