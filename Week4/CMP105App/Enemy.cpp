#include "Enemy.h"

Enemy::Enemy()
{
	window = 0;
	direction = 0;
	velocity.y = 100;
}

Enemy::~Enemy()
{
}

void Enemy::setWindow(sf::RenderWindow* hwnd)
{
	window = hwnd;
}

void Enemy::update(float dt)
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
	
	if (getPosition().y <= 0 && direction == 1)
	{
		direction = 0;
	}
	else if (getPosition().y >= window->getSize().y - getSize().y && direction == 0)
	{
		direction = 1;
	}
}