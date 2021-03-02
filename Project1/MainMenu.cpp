#include "MainMenu.h"

MainMenu::MainMenu(sf::RenderWindow& window)
{
	for (int i = 0; i < 2; i++)
	{
		buttons[i].setSize(sf::Vector2f(300, 100));
		buttons[i].setFillColor(sf::Color::White);
		buttons[i].setScale(wGetWidth() / 1366, wGetHeight() / 768);
		buttons[i].setPosition(sf::Vector2f(wGetWidth() / 2 - 150 * (wGetWidth() / 1366), wGetHeight() / 2 + - 170 * (wGetHeight() / 768) + i * 150 * (wGetHeight() / 768)));
	}

	tittle.setFont(font);
	tittle.setCharacterSize(100);
	tittle.setFillColor(sf::Color::White);
	tittle.setPosition(sf::Vector2f(wGetWidth() / 2 - 400 * (wGetWidth() / 1366), wGetHeight() / 2 - 350 * (wGetHeight() / 768)));
	tittle.setString("Algorithmes de tri");

	eu.setFont(font);
	eu.setCharacterSize(25);
	eu.setFillColor(sf::Color::White);
	eu.setPosition(sf::Vector2f(wGetWidth() / 2 - 400 * (wGetWidth() / 1366), wGetHeight() / 2 - 200 * (wGetHeight() / 768)));
	eu.setString("         FI-201 \n Chim Vladimir");

	font.loadFromFile("fonts/times-new-roman.ttf");
	for (int i = 0; i < 2; i++)
	{
		titles[i].setFont(font);
		titles[i].setCharacterSize(50);
		titles[i].setFillColor(sf::Color::Black);
		titles[i].setPosition(sf::Vector2f(wGetWidth() / 2 - 120 * (wGetWidth() / 1366), wGetHeight() / 2 + - 150 * (wGetHeight() / 768) + i * 150 * (wGetHeight() / 768)));
	}

	titles[0].setString("Varianta 7");
	titles[1].setString("Varianta 15");

	selected = 0;
	buttons[0].setFillColor(sf::Color::Green);
}

MainMenu::~MainMenu()
{
	delete this;
}

void MainMenu::checkEvents(sf::RenderWindow& window, int* current_scene)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window.close();
			break;
		case sf::Event::MouseMoved:
			checkHover(window);
			break;
		case sf::Event::MouseButtonReleased:
			checkClick(window, current_scene);
			break;
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Up)
			{
				if (selected > 0)
				{
					buttons[selected].setFillColor(sf::Color::White);
					selected--;
					buttons[selected].setFillColor(sf::Color::Green);
				}
			}
			else if (event.key.code == sf::Keyboard::Down)
			{
				if (selected < 1)
				{
					buttons[selected].setFillColor(sf::Color::White);
					selected++;
					buttons[selected].setFillColor(sf::Color::Green);
				}
			}
			else if (event.key.code == sf::Keyboard::Enter)
			{
				if (selected == 0)
				{
					*current_scene = 1;
				} 
				else if(selected == 1)
				{
					*current_scene = 2;
				}
			}
			break;
		}
	}
}

void MainMenu::draw(sf::RenderWindow& window)
{
	window.draw(tittle);
	window.draw(eu);

	for (int i = 0; i < 2; i++)
	{
		window.draw(buttons[i]);
	}
	
	for (int i = 0; i < 2; i++)
	{
		window.draw(titles[i]);
	}
}

void MainMenu::checkHover(sf::RenderWindow& window)
{
	
}

void MainMenu::checkClick(sf::RenderWindow& window, int* current_scene)
{
	
}