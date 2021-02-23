#pragma once
#include "SFML/Graphics.hpp"

class Window
{
public:
	Window();
	int wGetWidth();
	int wGetHeight();
	void setCursorArrow(sf::RenderWindow& window);
	void setCursorHand(sf::RenderWindow& window);
	void setCursorMove(sf::RenderWindow& window);
	virtual void checkEvents(sf::RenderWindow& window, int *current_scene) = 0;
	virtual void draw(sf::RenderWindow& window) = 0;
	virtual void checkHover(sf::RenderWindow& window) = 0;
	virtual void checkClick(sf::RenderWindow& window, int *current_scene) = 0;

private:
	int width, height;
	sf::Cursor cursorArr, cursorHand, cursorMove;
};