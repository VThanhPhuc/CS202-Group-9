#include "Background.h"
#include "People.h"
#include "Vehicle.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");
	CCar b(100, 10, 15);
	CCar c(900, 10, -10);
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
		c.draw(window);
		window.display();
		b.move();
		c.move();
		
		Sleep(100);
		if (crash(b, c) == true) {
			window.close();
		}
	}

	return 0;
}