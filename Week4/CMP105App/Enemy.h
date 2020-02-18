#pragma once
#include "Framework/GameObject.h"

class Enemy : public GameObject
{
public:
	Enemy();
	~Enemy();

	void update(float dt);
	void setWindow(sf::RenderWindow* hwnd);

private:
	int direction;
	sf::RenderWindow* window;
};

