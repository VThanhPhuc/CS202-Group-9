#include "Background.h"
#include "People.h"
#include "CARLANE.h"
#include "Light.h"
#include "CGAME.h"

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
	//sf::RenderWindow window(sf::VideoMode(1500, 1000), "sfml works");
	//CPEOPLE a(&window, 0, 200);
	//CLight l(0, 200);
	//CCARLIST b1; 
	//CCARLIST b2;
	//
	//CROAD* c1;
	//c1 = new CARLANE(1);
	//CROAD* c2;
	//c2 = new CARLANE(2);
	//CROAD* c3;
	//c3 = new CARLANE(3);
	//CROAD* c4;
	//c4 = new CARLANE(4);
	//CROAD* c5;
	//c5 = new CARLANE(5);
	//CROAD* c6;
	//c6 = new CARLANE(6);
	//CROAD* c7;
	//c7 = new CARLANE(7);
	//CROAD* c8;
	//c8 = new CARLANE(8);
	//CROAD* c9;
	//c9 = new CARLANE(9);
	//CROAD* c10;
	//c10 = new CARLANE(10);
	//CROAD* c11;
	//c11 = new CARLANE(11);
	//window.clear();
	////c1->draw(window);
	///*c2->draw(window);
	//c3->draw(window);
	//c4->draw(window);
	//c5->draw(window);
	//c6->draw(window);
	//c7->draw(window);
	//c8->draw(window);
	//c9->draw(window);
	//c10->draw(window);
	//c11->draw(window);*/

	///*a.draw(window);*/
	//while (window.isOpen())
	//{
	//	/*sf::Event ev;
	//	c1->draw(window);
	//	c2->draw(window);
	//	c3->draw(window);
	//	c4->draw(window);
	//	c5->draw(window);
	//	c6->draw(window);
	//	c7->draw(window);
	//	c8->draw(window);
	//	c9->draw(window);
	//	c10->draw(window);
	//	c11->draw(window);
	//	a.draw(window);
	//	b1.draw(window);
	//	b1.update(0, 230, window, l);
	//	b2.draw(window);
	//	b2.update(0, 550, window, l);
	//	l.draw(window);
	//	l.update(window);
	//	deque<COBJECT*>* cur1 = b1.getCarList();
	//	deque<COBJECT*>* cur2 = b2.getCarList();
	//	while (window.pollEvent(ev))
	//	{
	//		switch (ev.type)
	//		{
	//		case sf::Event::Closed:
	//			window.close();
	//			break;
	//		case sf::Event::KeyPressed:
	//			if (ev.key.code == sf::Keyboard::Escape) window.close();
	//			else if (ev.key.code == sf::Keyboard::Up) a.moveUp();
	//			else if (ev.key.code == sf::Keyboard::Down) a.moveDown();
	//			else if (ev.key.code == sf::Keyboard::Left) a.moveLeft();
	//			else if (ev.key.code == sf::Keyboard::Right) a.moveRight();
	//			break;
	//		}
	//	}

	//	for (long i = 0; i < cur1->size(); ++i)
	//	{
	//		if (a.isImpact(cur1->at(i)))
	//		{
	//			std::cout << "die" << endl;
	//			break;
	//		}
	//	}

	//	for (long i = 0; i < cur2->size(); ++i)
	//	{
	//		if (a.isImpact(cur2->at(i)))
	//		{
	//			std::cout << "die" << endl;
	//			break;
	//		}
	//	}

	//	window.display();

	//}*/


	CGAME game;
	game.run();
	system("pause");
	cout << "OK to out!";
	return 0;


}
