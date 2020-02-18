#pragma once
#include "Framework/GameObject.h"

class Cursor : public GameObject
{
public:
	Cursor();
	~Cursor();

	void update();
	void setWindow(sf::RenderWindow* window);

private:
	sf::RenderWindow* window;
};

