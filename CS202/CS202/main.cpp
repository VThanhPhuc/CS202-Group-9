#include "Background.h"
#include "People.h"
#include "Vehicle.h"
#include "Light.h"
#include "CLane.h"
//
//int main()
//{
//	sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");
//	CCar b(100, 10, 10);
//	CCar c(900, 10, -5);
//	CLight l;
//	Menu c1;
//	while (window.isOpen())
//	{
//		sf::Event event;
//		while (window.pollEvent(event))
//		{
//			if (event.type == sf::Event::Closed)
//				window.close();
//			if (event.type == sf::Event::MouseButtonPressed)
//			{
//
//				if (c1.IsMouseOver(window) == 1)
//				{
//					cout << "Start" << endl;
//				}
//				else if (c1.IsMouseOver(window) == 2)
//				{
//					cout << "Exit" << endl;
//				}
//				else cout << "No" << endl;
//			}
//		}
//		window.clear();
//		c1.draw(window);
//		b.draw(window);
//		c.draw(window);
//		window.display();
//		b.move(l);
//		c.move(l);
//		l.update();
//		Sleep(100);
//		if (crash(b, c) == true) {
//			window.close();
//		}
//	}
//
//	return 0;
//}

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");
	CarLane lane(1, 5, 10, -10);
	CLight l(true);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

		}
		window.clear();
		lane.draw(window);
		
		window.display();

		Sleep(100);
		lane.move(l);
		/*if (crash(b, c) == true) {
			window.close();
		}*/
	}
	return 0;
}
