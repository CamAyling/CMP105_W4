#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	playerObject.setInput(input);

	playerTexture.loadFromFile("gfx/Mushroom.png");

	playerObject.setTexture(&playerTexture);
	playerObject.setSize(sf::Vector2f(100, 100));
	playerObject.setPosition(100, 300);

	enemyTexture.loadFromFile("gfx/Goomba.png");

	enemy.setTexture(&enemyTexture);
	enemy.setSize(sf::Vector2f(100, 100));
	enemy.setPosition(300, 100);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	// Close window on Escape pressed.
	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		window->close();
	}

	playerObject.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	enemy.update(dt, enemy.getPosition());
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(playerObject);
	window->draw(enemy);

	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}