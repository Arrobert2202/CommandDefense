#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "global.h"

/*
    Design a C++ class that reflects the properties of an wave of  enemies. The class should include the following:
 - methods to set and get the name of the wave
 - methods to set and get the number of enemies  (must be bigger than 0)
 - methods to set and get the starting health (bigger than 0)
 - methods to set and get the money per enemy (must be a float value)
    Create 2 global functions that compare two wave in terms of: number of enemies and money per enemy.
If two waves are equal the return value of such a function will be 0. If the first wave is bigger than the second one,
the return value will be 1, otherwise -1. Make sure that you have the following: a cpp file for the methods specific to
the class a header file for the global functions a cpp file for the global functions implementation a main.cpp file that
shows how the methods and global functions can be used.
*/

int main()
{
    wave wave1, wave2;

    wave1.setName((char*)"W1");
    wave1.setHealth(100);
    wave1.setNumber(10);
    wave1.setMoney(7.8f);
    wave2.setName((char*)"W2");
    wave2.setHealth(75);
    wave2.setNumber(10);
    wave2.setMoney(9.1f);
    int numberComparison = compareNumberOfEnemies(wave1, wave2);
    if (numberComparison == 0)
        printf("%d The 2 waves have the same number of enemies.\n", numberComparison);
    else if (numberComparison == 1)
        printf("%d The first wave has more enemies.\n", numberComparison);
    else
        printf("%d The second wave has more enemies.\n", numberComparison);
    int moneyComparison=compareMoneyPerEnemy(wave1, wave2);
    if (moneyComparison == 0)
        printf("%d The 2 waves have the same amount of money per enemy.\n", moneyComparison);
    else if (moneyComparison == 1)
        printf("%d The first wave has more money per enemy.\n", moneyComparison);
    else
        printf("%d The second wave has more money per enemy.\n", moneyComparison);
    return 0;
}