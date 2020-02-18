#pragma once
#include "Framework/GameObject.h"

class Enemy : public GameObject
{
public:
	Enemy();
	~Enemy();

	void update(float dt, sf::Vector2f position);

private:
	int direction;
};

