#include "Background.h"
#include "People.h"
#include "Vehicle.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");
	CCar b(10, 10, 2);
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		b.draw(window);
		window.display();
	}

	return 0;
}