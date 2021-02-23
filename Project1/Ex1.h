#pragma once
#include "Window.h"

class Ex1 : public Window
{
public:
	Ex1(sf::RenderWindow& window);
	void checkEvents(sf::RenderWindow& window, int* current_scene);
	void draw(sf::RenderWindow& window);
	void checkHover(sf::RenderWindow& window);
	void checkClick(sf::RenderWindow& window, int* current_scene);
	void randomizare();
private:
	sf::RectangleShape boxe[2], obj[2000], obj1[2000];
	int arr[2000], arr1[2000];
	sf::Text titles[2], comp[2], sc[2], sit[2], iter[2];
	sf::Font font;
	int j, i, st,dr, comp1, comp2, iter1, iter2;
	bool pause;
};