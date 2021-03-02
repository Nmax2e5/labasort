#include "Ex2.h"
#include <time.h>

Ex2::Ex2(sf::RenderWindow& window)
{
	for (int i = 0; i < 2; i++)
	{
		sc[i].setFont(font);
		sc[i].setCharacterSize(25);
		sc[i].setFillColor(sf::Color::White);
		sc[i].setPosition(sf::Vector2f(30 * (wGetWidth() / 1366) + 400, 10 * (wGetHeight() / 768) + (i * (wGetHeight() / 2 + 10) * (wGetHeight() / 768))));
		sc[i].setString("echanger: ");
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
		boxe[i].setSize(sf::Vector2f(wGetWidth() - 20 * (wGetWidth() / 1366), wGetHeight() / 2 - 30 * (wGetHeight() / 768)));
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

	titles[0].setString("Merge Sort");
	titles[1].setString("Quick Sort");

	randomizare();
	j = 0;
	i = 1;
	pause = 1;
	st = 0;
	dr = 1325;
	comp1 = comp2 = 0;
	iter1 = iter2 = 0;
	s1 = s2 = 0;
}

void Ex2::checkEvents(sf::RenderWindow& window, int* current_scene)
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
			else if (event.key.code == sf::Keyboard::Escape)
			{
				*current_scene = 0;
			}
			break;
		}
	}
}

void Ex2::draw(sf::RenderWindow& window)
{
	if (!pause)
	{
		if (!s1)
			mergesort(window, 0, 1325), succes(window, 0, 1325, obj);
		s1 = 1;

		if (!s2)
			quicksort(window, 0, 1324), succes(window, 0, 1325, obj1);
		s2 = 1;
	}

	render(window);

}

void Ex2::render(sf::RenderWindow& window)
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
		window.draw(sit[i]);
		window.draw(iter[i]);
		window.draw(comp[i]);
	}

	comp[0].setString(std::to_string(comp1));
	comp[1].setString(std::to_string(comp2));
	iter[0].setString(std::to_string(iter1));
	iter[1].setString(std::to_string(iter2));
}

void Ex2::succes(sf::RenderWindow& window, int st, int dr, sf::RectangleShape obj[])
{
	for (int i = st; i < dr; i++)
	{
		window.clear(sf::Color::Black);

		obj[i].setFillColor(sf::Color::Green);

		render(window);
		window.display();

		sf::sleep(sf::milliseconds(1));
	}

	for (int i = st; i < dr; i++)
	{
		obj[i].setFillColor(sf::Color::White);
	}

	window.clear(sf::Color::Black);
	render(window);
	window.display();
}

void Ex2::mergesort(sf::RenderWindow& window, int st, int dr)
{
	if (st == dr - 1)
		return;

	int mid = (st + dr) / 2;

	mergesort(window, st, mid);
	mergesort(window, mid, dr);

	int pos1 = st, pos2 = mid;

	for (int i = st, pos = 0; i < dr; i++, pos++)
	{
		if (pos1 == mid)
			aux[pos] = arr[pos2++], aux_obj[pos] = obj[pos2-1].getSize();
		else if (pos2 == dr)
			aux[pos] = arr[pos1++], aux_obj[pos] = obj[pos1 - 1].getSize();
		else if (arr[pos1] < arr[pos2])
			aux[pos] = arr[pos1++], aux_obj[pos] = obj[pos1 - 1].getSize();
		else
			aux[pos] = arr[pos2++], aux_obj[pos] = obj[pos2 - 1].getSize();

		iter1++;
	}

	for (int i = st, pos = 0; i < dr; i++, pos++)
	{
		window.clear(sf::Color::Black);

		arr[i] = aux[pos];
		obj[i].setSize(aux_obj[pos]);
		obj[i].setPosition(obj[i].getPosition().x, 20 * (wGetHeight() / 768) + ((340 - obj[i].getSize().y) * (wGetHeight() / 768)));
		iter1++;
		comp1++;
		
		render(window);
		window.display();
	}

	/*window.clear(sf::Color::Black);
	render(window);
	window.display();*/
}

void Ex2::quicksort(sf::RenderWindow& window, int st, int dr)
{
	if (st < dr)
	{
		
		int pivot = arr1[dr];
		int i = st - 1;

		for (int j = st; j <= dr - 1; j++)
		{
			window.clear(sf::Color::Black);

			if (arr1[j] <= pivot)
			{
				i++;
				int auxx = arr1[j];
				arr1[j] = arr1[i];
				arr1[i] = auxx;

				sf::Vector2f aux = obj1[j].getSize();
				obj1[j].setSize(obj1[i].getSize());
				obj1[j].setPosition(obj1[j].getPosition().x, 20 * (wGetHeight() / 768) + ((340 - obj1[j].getSize().y) * (wGetHeight() / 768)) + ((wGetHeight() / 768) * (wGetHeight() / 2)) + ((wGetHeight() / 768) * 10));
				obj1[i].setSize(aux);
				obj1[i].setPosition(obj1[i].getPosition().x, 20 * (wGetHeight() / 768) + ((340 - obj1[i].getSize().y) * (wGetHeight() / 768)) + ((wGetHeight() / 768) * (wGetHeight() / 2)) + ((wGetHeight() / 768) * 10));
				comp2++;
			}
			iter2++;

			render(window);
			window.display();
		}

		window.clear(sf::Color::Black);

		i++;
		int auxx = arr1[i];
		arr1[i] = arr1[dr];
		arr1[dr] = auxx;

		sf::Vector2f aux = obj1[i].getSize();
		obj1[i].setSize(obj1[dr].getSize());
		obj1[i].setPosition(obj1[i].getPosition().x, 20 * (wGetHeight() / 768) + ((340 - obj1[i].getSize().y) * (wGetHeight() / 768)) + ((wGetHeight() / 768) * (wGetHeight() / 2)) + ((wGetHeight() / 768) * 10));
		obj1[dr].setSize(aux);
		obj1[dr].setPosition(obj1[dr].getPosition().x, 20 * (wGetHeight() / 768) + ((340 - obj1[dr].getSize().y) * (wGetHeight() / 768)) + ((wGetHeight() / 768) * (wGetHeight() / 2)) + ((wGetHeight() / 768) * 10));
		comp2++;

		render(window);
		window.display();

		/*window.clear(sf::Color::Black);
		render(window);
		window.display();*/

		quicksort(window, st, i - 1);
		quicksort(window, i + 1, dr);
	}
}

void Ex2::checkHover(sf::RenderWindow& window)
{

}

void Ex2::checkClick(sf::RenderWindow& window, int* current_scene)
{

}

void Ex2::randomizare()
{
	srand(time(NULL));

	for (int i = 0; i < 1325; i++)
	{
		arr[i] = rand() % 300 + 1;
		//arr[i] = 100;
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