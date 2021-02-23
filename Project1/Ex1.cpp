#include "Ex1.h"
#include <time.h>

Ex1::Ex1(sf::RenderWindow& window)
{
	for (int i = 0; i < 2; i++)
	{
		sc[i].setFont(font);
		sc[i].setCharacterSize(25);
		sc[i].setFillColor(sf::Color::White);
		sc[i].setPosition(sf::Vector2f(30 * (wGetWidth() / 1366) + 400, 10 * (wGetHeight() / 768) + (i * (wGetHeight() / 2 + 10) * (wGetHeight() / 768))));
		sc[i].setString("comparaisons: ");
	}

	for (int i = 0; i < 2; i++)
	{
		sit[i].setFont(font);
		sit[i].setCharacterSize(25);
		sit[i].setFillColor(sf::Color::White);
		sit[i].setPosition(sf::Vector2f(30 * (wGetWidth() / 1366) + 800, 10 * (wGetHeight() / 768) + (i * (wGetHeight() / 2 + 10) * (wGetHeight() / 768))));
		sit[i].setString("iterations: ");
	}

	for (int i = 0; i < 2; i++)
	{
		comp[i].setFont(font);
		comp[i].setCharacterSize(25);
		comp[i].setFillColor(sf::Color::White);
		comp[i].setPosition(sf::Vector2f(30 * (wGetWidth() / 1366) + 550, 10 * (wGetHeight() / 768) + (i * (wGetHeight() / 2 + 10) * (wGetHeight() / 768))));
		comp[i].setString("0");
	}

	for (int i = 0; i < 2; i++)
	{
		iter[i].setFont(font);
		iter[i].setCharacterSize(25);
		iter[i].setFillColor(sf::Color::White);
		iter[i].setPosition(sf::Vector2f(30 * (wGetWidth() / 1366) + 900, 10 * (wGetHeight() / 768) + (i * (wGetHeight() / 2 + 10) * (wGetHeight() / 768))));
		iter[i].setString("0");
	}

	for (int i = 0; i < 2; i++)
	{
		boxe[i].setSize(sf::Vector2f(wGetWidth() - 20 * (wGetWidth() / 1366), wGetHeight()/2 - 30 * (wGetHeight() / 768)));
		boxe[i].setFillColor(sf::Color::Black);
		boxe[i].setOutlineColor(sf::Color::White);
		boxe[i].setOutlineThickness(5);
		boxe[i].setScale(wGetWidth() / 1366, wGetHeight() / 768);
		boxe[i].setPosition(sf::Vector2f(10 * (wGetWidth() / 1366), 10 + i * (wGetHeight() / 2 + 10 * (wGetHeight() / 768))));
	}

	font.loadFromFile("fonts/times-new-roman.ttf");
	for (int i = 0; i < 2; i++)
	{
		titles[i].setFont(font);
		titles[i].setCharacterSize(50);
		titles[i].setFillColor(sf::Color::White);
		titles[i].setPosition(sf::Vector2f(30 * (wGetWidth() / 1366), 10 * (wGetHeight() / 768) + (i * (wGetHeight() / 2 + 10) * (wGetHeight() / 768))));
	}

	titles[0].setString("Shaker Sort");
	titles[1].setString("Insertion Sort");

	randomizare();
	j = 0;
	i = 1;
	pause = 1;
	st = 0;
	dr = 1325;
	comp1 = comp2 = 0;
	iter1 = iter2 = 0;
}

void Ex1::checkEvents(sf::RenderWindow& window, int* current_scene)
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
			if (event.key.code == sf::Keyboard::Space)
			{
				pause = !pause;
			}
			break;
		}
	}
}

void Ex1::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < 2; i++)
	{
		window.draw(boxe[i]);
	}

	for (int i = 0; i < 1325; i++)
	{
		window.draw(obj[i]);
	}

	for (int i = 0; i < 1325; i++)
	{
		window.draw(obj1[i]);
	}

	for (int i = 0; i < 2; i++)
	{
		window.draw(titles[i]);
		window.draw(sc[i]);
		window.draw(comp[i]);
		window.draw(sit[i]);
		window.draw(iter[i]);
	}

	if (!pause)
	{
		if (st < dr)
		{
			for (int j = st + 1; j < dr; j++)
			{
				if (arr[j] < arr[j - 1])
				{
					sf::Vector2f aux = obj[j].getSize();
					obj[j].setSize(obj[j - 1].getSize());
					obj[j].setPosition(obj[j].getPosition().x, 20 * (wGetHeight() / 768) + ((340 - obj[j].getSize().y) * (wGetHeight() / 768)));
					obj[j - 1].setSize(aux);
					obj[j - 1].setPosition(obj[j - 1].getPosition().x, 20 * (wGetHeight() / 768) + ((340 - obj[j - 1].getSize().y) * (wGetHeight() / 768)));
					int aux_nr = arr[j];
					arr[j] = arr[j - 1];
					arr[j - 1] = aux_nr;
					iter1++;
				}
				comp1++;
			}
			dr--;

			for (int j = dr - 1; j >= st; j--)
			{
				if (arr[j] < arr[j - 1])
				{
					sf::Vector2f aux = obj[j].getSize();
					obj[j].setSize(obj[j - 1].getSize());
					obj[j].setPosition(obj[j].getPosition().x, 20 * (wGetHeight() / 768) + ((340 - obj[j].getSize().y) * (wGetHeight() / 768)));
					obj[j - 1].setSize(aux);
					obj[j - 1].setPosition(obj[j - 1].getPosition().x, 20 * (wGetHeight() / 768) + ((340 - obj[j - 1].getSize().y) * (wGetHeight() / 768)));
					int aux_nr = arr[j];
					arr[j] = arr[j - 1];
					arr[j - 1] = aux_nr;
					iter1++;
				}
				comp1++;
			}
			st++;
		}

		if (i < 1325)
		{
			int cur = arr1[i];
			sf::Vector2f aux = obj1[i].getSize();
			int j = i - 1;

			while (j >= 0 && arr1[j] > cur)
			{
				obj1[j + 1].setSize(obj1[j].getSize());
				obj1[j + 1].setPosition(obj1[j + 1].getPosition().x, 20 * (wGetHeight() / 768) + ((340 - obj1[j+1].getSize().y) * (wGetHeight() / 768)) + ((wGetHeight() / 768) * (wGetHeight() / 2)) + ((wGetHeight() / 768) * 10));
				arr1[j + 1] = arr1[j];
				j--;
				comp2++;
				iter2++;
			}
			comp2++;

			obj1[j + 1].setSize(aux);
			obj1[j + 1].setPosition(obj1[j + 1].getPosition().x, 20 * (wGetHeight() / 768) + ((340 - obj1[j + 1].getSize().y) * (wGetHeight() / 768)) + ((wGetHeight() / 768) * (wGetHeight() / 2)) + ((wGetHeight() / 768) * 10));
			arr1[j + 1] = cur;
			iter2++;
			i++;

			if (i < 1325)
			{
				int cur = arr1[i];
				sf::Vector2f aux = obj1[i].getSize();
				int j = i - 1;

				while (j >= 0 && arr1[j] > cur)
				{
					obj1[j + 1].setSize(obj1[j].getSize());
					obj1[j + 1].setPosition(obj1[j + 1].getPosition().x, 20 * (wGetHeight() / 768) + ((340 - obj1[j + 1].getSize().y) * (wGetHeight() / 768)) + ((wGetHeight() / 768) * (wGetHeight() / 2)) + ((wGetHeight() / 768) * 10));
					arr1[j + 1] = arr1[j];
					j--;
					comp2++;
					iter2++;
				}
				comp2++;

				obj1[j + 1].setSize(aux);
				obj1[j + 1].setPosition(obj1[j + 1].getPosition().x, 20 * (wGetHeight() / 768) + ((340 - obj1[j + 1].getSize().y) * (wGetHeight() / 768)) + ((wGetHeight() / 768) * (wGetHeight() / 2)) + ((wGetHeight() / 768) * 10));
				arr1[j + 1] = cur;
				i++;
				iter2++;
			}
		}
		comp[0].setString(std::to_string(comp1));
		comp[1].setString(std::to_string(comp2));
		iter[0].setString(std::to_string(iter1));
		iter[1].setString(std::to_string(iter2));
	}
}

void Ex1::checkHover(sf::RenderWindow& window)
{

}

void Ex1::checkClick(sf::RenderWindow& window, int* current_scene)
{

}

void Ex1::randomizare()
{
	srand(time(NULL));

	for (int i = 0; i < 1325; i++)
	{
		arr[i] = rand() % 300 +1;
		obj[i].setSize(sf::Vector2f(1, arr[i] * (wGetHeight() / 768)));
		obj[i].setFillColor(sf::Color::White);
		obj[i].setScale(wGetWidth() / 1366, wGetHeight() / 768);
		obj[i].setPosition(sf::Vector2f(20 * (wGetWidth() / 1366) + i * 1 * (wGetWidth() / 1366), 20 * (wGetHeight() / 768) + ((340 - arr[i]) * (wGetHeight() / 768))));
	}

	for (int i = 0; i < 1325; i++)
	{
		arr1[i] = arr[i];
		obj1[i].setSize(sf::Vector2f(1, arr1[i] * (wGetHeight() / 768)));
		obj1[i].setFillColor(sf::Color::White);
		obj1[i].setScale(wGetWidth() / 1366, wGetHeight() / 768);
		obj1[i].setPosition(sf::Vector2f(20 * (wGetWidth() / 1366) + i * 1 * (wGetWidth() / 1366), 20 * (wGetHeight() / 768) + ((340 - arr1[i]) * (wGetHeight() / 768)) + ((wGetHeight() / 768) * (wGetHeight() / 2)) + ((wGetHeight() / 768) * 10)));
	}
}