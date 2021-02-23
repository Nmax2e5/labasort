#pragma once
#include "MainMenu.h"
#include "Ex1.h"
//#include "Ex2.h"

class App
{
public:
	App(sf::RenderWindow& window);
	void start(sf::RenderWindow& window);
	void render(sf::RenderWindow& window, Window* scene, int* current_scene);

	~App();

private:
	int current_scene;
	Window* scene[5];
};