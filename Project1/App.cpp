#include "App.h"

App::App(sf::RenderWindow& window)
{
	current_scene = 0;
	scene[0] = new MainMenu(window);
	scene[1] = new Ex1(window);
}

App::~App()
{

}

void App::start(sf::RenderWindow& window)
{
	sf::Clock clock;

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMilliseconds();
		clock.restart();

		render(window, scene[current_scene], &current_scene);

		sf::sleep(sf::milliseconds(30 - time));
	}
}

void App::render(sf::RenderWindow& window, Window* scene, int* current_scene)
{
	window.clear(sf::Color::Black);

	scene->checkEvents(window, current_scene);
	scene->draw(window);

	window.display();
}