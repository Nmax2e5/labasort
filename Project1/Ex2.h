#pragma once
#include "Window.h"

class Ex2 : public Window
{
public:
	Ex2(sf::RenderWindow& window);
	void checkEvents(sf::RenderWindow& window, int* current_scene);
	void draw(sf::RenderWindow& window);
	void checkHover(sf::RenderWindow& window);
	void checkClick(sf::RenderWindow& window, int* current_scene);
	void randomizare();
	void render(sf::RenderWindow& window);
	void succes(sf::RenderWindow& window, int st, int dr, sf::RectangleShape obj[]);
	void mergesort(sf::RenderWindow& window, int st, int dr);
	void quicksort(sf::RenderWindow& window, int st, int dr);

private:
	sf::RectangleShape boxe[2], obj[2000], obj1[2000];
	int arr[2000], arr1[2000], aux[2000];
	sf::Vector2f aux_obj[2000];
	sf::Text titles[2], comp[2], sc[2], sit[2], iter[2];
	sf::Font font;
	int j, i, st, dr, comp1, comp2, iter1, iter2;
	bool pause, s1, s2;
};