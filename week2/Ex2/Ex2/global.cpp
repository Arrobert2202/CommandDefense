#include "global.h"

int compareNumberOfEnemies(wave Wave1, wave Wave2)
{
    if (Wave1.get_number() < Wave2.get_number())
        return -1;
    else if (Wave1.get_number() > Wave2.get_number())
        return 1;
    else
        return 0;
}
int compareMoneyPerEnemy(wave Wave1, wave Wave2)
{
    if (Wave1.get_money() < Wave2.get_money())
        return -1;
    else if (Wave1.get_money() > Wave2.get_money())
        return 1;
    else
        return 0;
}