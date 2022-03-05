#include "Enemy.h"

void Enemy::Init(Point initialLocation, int initialHealth)
{
    location = initialLocation;
    health    = initialHealth;
}

void Enemy::Move(EnemyDirection direction, int step)
{
    if (direction == EnemyDirection::UpDirection)
        location.y = location.y - step;
    if (direction == EnemyDirection::DownDirection)
        location.y = location.y + step;
    if (direction == EnemyDirection::LeftDirection)
        location.x = location.x - step;
    if (direction == EnemyDirection::RightDirection)
        location.x = location.x + step;

}

bool Enemy::IsDead()
{
    if (health <= 0)
        return true;
    else
        return false;
}

void Enemy::Shoot(int damage)
{
    health = health - damage;
}