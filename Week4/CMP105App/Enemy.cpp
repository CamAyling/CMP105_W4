#include "Enemy.h"

Enemy::Enemy()
{
	direction = 0;
	velocity.y = 100;
}

Enemy::~Enemy()
{
}

void Enemy::update(float dt, sf::Vector2f position)
{
	switch (direction)
	{
	case 0:
		move(velocity * dt);
		break;
	case 1:
		move(-velocity * dt);
		break;
	}
	
	if (position.y <= 100 && direction == 1)
	{
		direction = 0;
	}
	else if (position.y >= 400 && direction == 0)
	{
		direction = 1;
	}
}