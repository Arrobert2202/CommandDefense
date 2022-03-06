#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

class wave
{
  private:
    char name[20];
    int nrEnemy;
    int health;
    float moneyPerEnemy;

  public:
    void setName(char newName[20])
    {
        strcpy(name, newName);
    }
    char* get_name()
    {
        return name;
    }
    void setNumber(int nrOfEnemies)
    {
        if (nrOfEnemies > 0)
            nrEnemy = nrOfEnemies;
        else
            nrEnemy = 0;
    }
    int get_number()
    {
        return nrEnemy;
    }
    void setHealth(int startingHealth)
    {
        if (startingHealth > 0)
            health = startingHealth;
        else
            health = 0;
    }
    int get_health()
    {
        return health;
    }
    void setMoney(float money)
    {
        moneyPerEnemy = money;
    }

    float get_money()
    {
        return moneyPerEnemy;
    }
};