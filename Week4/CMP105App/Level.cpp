#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	window->setMouseCursorVisible(false);

	// initialise game objects
	playerObject.setInput(input);

	playerTexture.loadFromFile("gfx/Mushroom.png");
	enemyTexture.loadFromFile("gfx/Goomba.png");
	ballTexture.loadFromFile("gfx/Beach_Ball.png");
	cursorTexture.loadFromFile("gfx/icon.png");

	playerObject.setTexture(&playerTexture);
	playerObject.setSize(sf::Vector2f(100, 100));
	playerObject.setPosition(100, 300);

	enemy.setTexture(&enemyTexture);
	enemy.setSize(sf::Vector2f(100, 100));
	enemy.setPosition(300, 100);
	enemy.setWindow(window);

	ball.setTexture(&ballTexture);
	ball.setSize(sf::Vector2f(100, 100));
	ball.setPosition(500, 100);
	ball.setWindow(window);

	cursor.setTexture(&cursorTexture);
	cursor.setSize(sf::Vector2f(25, 25));
	cursor.setInput(input);
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
	enemy.update(dt);
	ball.update(dt);
	cursor.update();
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(playerObject);
	window->draw(enemy);
	window->draw(ball);
	window->draw(cursor);

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