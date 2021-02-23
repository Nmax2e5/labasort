#pragma once
#include "Window.h"

class MainMenu : public Window
{
public:
	MainMenu(sf::RenderWindow& window);
	~MainMenu();
	void checkEvents(sf::RenderWindow& window, int* current_scene);
	void draw(sf::RenderWindow& window);
	void checkHover(sf::RenderWindow& window);
	void checkClick(sf::RenderWindow& window, int* current_scene);

private:
	int selected;
	sf::RectangleShape buttons[3];
	sf::Text titles[3], tittle, eu;
	sf::Font font;
};