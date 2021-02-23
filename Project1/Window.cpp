#include "Window.h"

Window::Window()
{
	width = 1366;
	height = 768;
	cursorHand.loadFromSystem(sf::Cursor::Hand);
	cursorArr.loadFromSystem(sf::Cursor::Arrow);
	cursorMove.loadFromSystem(sf::Cursor::Type::SizeAll);
}

int Window::wGetWidth()
{
	return width;
}

int Window::wGetHeight()
{
	return height;
}

void Window::setCursorArrow(sf::RenderWindow& window)
{
	window.setMouseCursor(cursorArr);
}

void Window::setCursorHand(sf::RenderWindow& window)
{
	window.setMouseCursor(cursorHand);
}

void Window::setCursorMove(sf::RenderWindow& window)
{
	window.setMouseCursor(cursorMove);
}