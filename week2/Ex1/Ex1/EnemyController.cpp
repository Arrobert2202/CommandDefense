#include "EnemyController.h"
#include "Enemy.h" // to actualy use the field Enemy declared in the header by forward declaration, we use the field here

void EnemyController::Init(int maximumEnemies, int step, Point initialLocation)
{
    enemies = new Enemy[maximumEnemies];
    stepSize = step;
    startingLocation = initialLocation;
    maxEnemies       = maximumEnemies;
    nrEnemies        = 0;

}

void EnemyController::Uninit()
{
    delete[] enemies;
}

void EnemyController::Move()
{
    for (int i = 0; i < nrEnemies; i++)
        enemies[i].Move(EnemyDirection::DownDirection, stepSize);
}

void EnemyController::DamageAll()
{
    for (int i = 0; i < nrEnemies; i++)
        enemies[i].Shoot(i + 1);
}

int EnemyController::CountKilledEnemies()
{
    int nrkilledEnemies=0;
    for (int i = 0; i < nrEnemies; i++)
        if (enemies[i].IsDead() == true)
            nrkilledEnemies++;
    return nrkilledEnemies;
}
bool EnemyController::SpawnEnemy()
{
    if (nrEnemies < maxEnemies - 1)
    {
        enemies[nrEnemies].Init(startingLocation, ENEMY_HEALTH);
        nrEnemies++;
        return true;
    }
    return false;
}