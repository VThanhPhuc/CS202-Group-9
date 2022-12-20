#pragma once
#include "Vehicle.h"

class Menu
{
private:
	sf::Sprite MenuBackground;
	sf::RectangleShape button_start; // begin the game
	sf::RectangleShape button_exit; // quit the game
	sf::RectangleShape button_back; //get back to the main
	sf::RectangleShape menu_in_game; // menu
	sf::RectangleShape button_resume;

	sf::Texture t;
	sf::Texture exit_button;
	sf::Texture s_button;
	sf::Texture b_button;
	sf::Texture menu_;
	sf::Texture resume;
public:
	void InnitMenuBackground();
	void draw_menu(sf::RenderWindow& window);
	int Start_Play(sf::RenderWindow& window);
	int CheckMouseGamePlay(sf::RenderWindow& window);
	void Draw_Menu_In_game(sf::RenderWindow& window);
	void Menu_control(sf::RenderWindow& window, sf::Event event, Background d);
	void Begin()
	{
		sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");
		CCAR b("car.png", 100, 100, 10, 10);
		Background d;
		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
				if (event.type == sf::Event::MouseButtonPressed)
				{
					this->Menu_control(window, event, d);
				}

			}
			window.clear();
			this->draw_menu(window);
			window.display();
		}
	}
	void PlayGame(sf::RenderWindow& window, Background d, int& return1)
	{
		if (return1 == 1) return;
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
			int i = 0;
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
								while (window.pollEvent(ev))
								{
									if (ev.type == sf::Event::Closed)
									{
										window.close();
									}
									if (ev.type == sf::Event::MouseButtonPressed)
									{
										if (this->CheckMouseGamePlay(window) == 1)
										{
											d.reload();
											i1 = 1;
											i = 1;
											return1 = 1;
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
					int f1 = 0;
					if (a.isImpact(cur->at(i)))
					{
						f1 = 1;
						std::cout << "die" << endl;
						int k = 0;
						while (window.isOpen())
						{
							if (return1 == 1) return;
							window.clear();
							this->LoseGame(window);
							window.display();
							while (window.pollEvent(ev))
							{
								if (ev.type == sf::Event::Closed)
								{
									window.close();
								}
								if (ev.type == sf::Event::MouseButtonPressed)
								{
									if (this->ChoiceLoseGame(window) == 1)
									{
										cout << "Yes" << endl;
										this->PlayGame(window, d, return1);
										if (return1 == 1) return;
										k = 1;
										i = 0;
										break;
									}
									else if (this->ChoiceLoseGame(window) == 2)
									{
										cout << "Yes1" << endl;
										k = 1;
										i = 1;
										return1 = 1;
										break;
									}
								}
							}
							if (k == 1 && i == 1)
							{
								return;
							}
							else if (k == 1 && i == 0)
							{
								break;
							}
						}
						if (k == 1 && i == 0)
						{
							window.clear();
							break;
						}
						break;
					}
				}
				window.display();
				if (i == 1) break;
			}
			if (i == 1) break;
		}
	}
};