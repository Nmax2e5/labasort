#include "App.h"

sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "laborator 2");

int main()
{
	App app(window);

	app.start(window);
}