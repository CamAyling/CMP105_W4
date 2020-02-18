#include "Cursor.h"

Cursor::Cursor()
{
}

Cursor::~Cursor()
{
}

void Cursor::update()
{
	setPosition(input->getMouseX(), input->getMouseY());
}