#include "App.h"

sf::RenderWindow window(sf::VideoMode(1366,768),  "laborator 2");

int main()
{
	App app(window);

	app.start(window);
}