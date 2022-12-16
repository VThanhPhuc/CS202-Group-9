#include "Menu.h"
void Menu::InnitMenuBackground()
{
	if (!this->t.loadFromFile("universe.png"))
	{
		cout << "Can not load" << endl;
	};
	if (!this->s_button.loadFromFile("s_button.png"))
	{
		cout << "Can not load" << endl;
	};
	if (!this->exit_button.loadFromFile("exit_button.png"/*,sf::IntRect(100,100,200,200))*/))
	{
		cout << "Can not load" << endl;
	};
	this->MenuBackground.setTexture(t);

	this->button_start.setTexture(&this->s_button);
	this->button_start.setSize(sf::Vector2f(200, 200));
	this->button_start.setPosition(200, 200);

	this->button_exit.setTexture(&this->exit_button);
	this->button_exit.setSize(sf::Vector2f(200, 200));
	this->button_exit.setPosition(200, 600);
}
void Menu::draw_menu(sf::RenderWindow& window)
{
	InnitMenuBackground();
	window.draw(this->MenuBackground);
	window.draw(this->button_start);
	window.draw(this->button_exit);
}
int Menu::Start_Play(sf::RenderWindow& window)
{
	float mouseX = sf::Mouse::getPosition(window).x;
	float mouseY = sf::Mouse::getPosition(window).y;

	if (mouseX >= button_start.getPosition().x && mouseX <= (button_start.getPosition().x + 200) && mouseY <= (button_start.getPosition().y + 200) && mouseY >= button_start.getPosition().y)
	{
		cout << mouseX << endl;
		cout << mouseY << endl;
		cout << button_start.getPosition().x << endl;
		cout << button_start.getPosition().y << endl;
		return 1;
	}
	if (mouseX >= button_exit.getPosition().x && mouseX <= (button_exit.getPosition().x + 200) && mouseY <= (button_exit.getPosition().y + 200) && mouseY >= button_exit.getPosition().y)
	{
		return 2;
	}
	return 0;
}
int Menu::CheckMouseGamePlay(sf::RenderWindow& window)
{
	float mouseX = sf::Mouse::getPosition(window).x;
	float mouseY = sf::Mouse::getPosition(window).y;

	if (mouseX >= button_back.getPosition().x && mouseX <= (button_back.getPosition().x + 100) && mouseY <= (button_back.getPosition().y + 100) && mouseY >= button_back.getPosition().y)
	{
		cout << mouseX << endl;
		cout << mouseY << endl;
		cout << button_back.getPosition().x << endl;
		cout << button_back.getPosition().y << endl;
		return 1;
	}
	else if (mouseX >= button_resume.getPosition().x && mouseX <= (button_resume.getPosition().x + 100) && mouseY <= (button_resume.getPosition().y + 100) && mouseY >= button_resume.getPosition().y)
	{
		cout << button_resume.getPosition().x << endl;
		cout << button_resume.getPosition().y << endl;
		return 2;
	}
	return 0;
}
void Menu::Draw_Menu_In_game(sf::RenderWindow& window)
{

	this->button_start.setPosition(-1000, -1000);
	this->button_exit.setPosition(-1000, -1000);


	if (!this->menu_.loadFromFile("Menu_game.png"))
	{
		cout << "Can not load" << endl;
	};
	this->menu_in_game.setTexture(&this->menu_);
	this->menu_in_game.setSize(sf::Vector2f(700, 600));
	this->menu_in_game.setPosition(500, 200);

	if (!this->b_button.loadFromFile("b_button.png"))
	{
		cout << "Can not load" << endl;
	};
	this->button_back.setTexture(&this->b_button);
	this->button_back.setSize(sf::Vector2f(100, 100));
	this->button_back.setPosition(800, 500);

	if (!this->resume.loadFromFile("s_button.png"))
	{
		cout << "Can not load" << endl;
	};
	this->button_resume.setTexture(&this->resume);
	this->button_resume.setSize(sf::Vector2f(100, 100));
	this->button_resume.setPosition(800, 400);

	window.draw(this->menu_in_game);
	window.draw(this->button_back);
	window.draw(this->button_resume);
}
void Menu::Menu_control(sf::RenderWindow& window, sf::Event event, Background d, CCar b)
{
	if (event.type == sf::Event::Closed)
		window.close();
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (this->Start_Play(window) == 1)
		{
			cout << "Start" << endl;
			CPEOPLE a(&window, 0, 500);
			CLight l;
			CCARLIST b; CROAD* c1;
			c1 = new CARLANE(1);
			CROAD* c2;
			c2 = new CARLANE(2);
			CROAD* c3;
			c3 = new CARLANE(3);
			CROAD* c4;
			c4 = new CARLANE(4);
			CROAD* c5;
			c5 = new CARLANE(5);
			CROAD* c6;
			c6 = new CARLANE(6);
			CROAD* c7;
			c7 = new CARLANE(7);
			CROAD* c8;
			c8 = new CARLANE(8);
			CROAD* c9;
			c9 = new CARLANE(9);
			CROAD* c10;
			c10 = new CARLANE(10);
			CROAD* c11;
			c11 = new CARLANE(11);
			while (window.isOpen())
			{
				//window.clear();
				//d.draw(window);
				//this->draw_gameplay(window);
				//b.draw(window);
				//c.draw(window);
				//p.draw(window);
				//window.display();
				int i = 0;
				//b.move(l);
				//c.move(l);
				//p.Control(10,window);
				/*if (p.isImpact(b) == true)
				{
					cout << "Dung" << endl;
					break;
				}*/

				window.clear();
				a.draw(window);
				while (window.isOpen())
				{
					sf::Event ev;
					window.clear();
					c1->draw(window);
					c2->draw(window);
					c3->draw(window);
					c4->draw(window);
					c5->draw(window);
					c6->draw(window);
					c7->draw(window);
					c8->draw(window);
					c9->draw(window);
					c10->draw(window);
					c11->draw(window);
					b.draw(window);
					a.draw(window);
					b.update(0, 0, window, l);
					deque<COBJECT*>* cur = b.getCarList();
					while (window.pollEvent(ev))
					{
						switch (ev.type)
						{
						case sf::Event::Closed:
							window.close();
							break;
						case sf::Event::KeyPressed:
							if (ev.key.code == sf::Keyboard::Up) a.moveUp();
							else if (ev.key.code == sf::Keyboard::Down) a.moveDown();
							else if (ev.key.code == sf::Keyboard::Left) a.moveLeft();
							else if (ev.key.code == sf::Keyboard::Right) a.moveRight();
							else if (ev.key.code == sf::Keyboard::Escape)
							{
								while (window.isOpen())
								{
									window.clear();
									d.blur_draw(window);
									this->Draw_Menu_In_game(window);
									window.display();
									int i1 = 0;
									while (window.pollEvent(event))
									{
										if (event.type == sf::Event::Closed)
										{
											window.close();
										}
										if (event.type == sf::Event::MouseButtonPressed)
										{
											if (this->CheckMouseGamePlay(window) == 1)
											{
												d.reload();
												i1 = 1;
												i = 1;
												break;
											}
											else if (this->CheckMouseGamePlay(window) == 2)
											{
												d.reload();
												i1 = 1;
												break;
											}
										}
									}
									if (i1 == 1) break;
								}
							}
							break;
						}
					}

					for (long i = 0; i < cur->size(); ++i)
					{
						if (a.isImpact(cur->at(i)))
						{
							std::cout << "die" << endl;
							break;
						}
					}
					window.display();
					if (i == 1) break;
				}
				//while (window.pollEvent(event))
				//{
				//	if (event.type == sf::Event::Closed)
				//		window.close();
				//	if (event.key.code == sf::Keyboard::Escape)
				//	{
				//		cout << "A" << endl;
				//		while (window.isOpen())
				//		{
				//			window.clear();
				//			d.blur_draw(window);
				//			this->Draw_Menu_In_game(window);
				//			window.display();
				//			int i1 = 0;
				//			while (window.pollEvent(event))
				//			{
				//				if (event.type == sf::Event::Closed)
				//				{
				//					window.close();
				//				}
				//				if (event.type == sf::Event::MouseButtonPressed)
				//				{
				//					if (this->CheckMouseGamePlay(window) == 1)
				//					{
				//						cout << "1" << endl;
				//						d.reload();
				//						i1 = 1;
				//						i = 1;
				//						break;
				//					}
				//					else if (this->CheckMouseGamePlay(window) == 2)
				//					{
				//						cout << "2" << endl;
				//						d.reload();
				//						i1 = 1;
				//						break;
				//					}
				//				}
				//			}
				//			if (i1 == 1) break;
				//		}
				//		//i = 1;
				//		break;
				//	}
				//}
				if (i == 1) break;
			}
		}
		else if (this->Start_Play(window) == 2)
		{
		cout << "Exit" << endl;
		window.close();
		}
		else cout << "No" << endl;
	}
}