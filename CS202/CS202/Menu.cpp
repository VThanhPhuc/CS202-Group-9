#include "Menu.h"
#include "CGAME.h"
#include "time.h"
#include <chrono>

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
	if (!this->continue_p.loadFromFile("continue_notification.png"))
	{
		cout << "Can not load" << endl;
	};
	this->continue_button.setTexture(&this->continue_p);
	this->continue_button.setSize(sf::Vector2f(150, 150));
	this->continue_button.setPosition(600, 450);

	if (!this->b1_button.loadFromFile("Menu_notification.png"))
	{
		cout << "Can not load" << endl;
	};
	this->button_back1.setTexture(&this->b1_button);
	this->button_back1.setSize(sf::Vector2f(150, 150));
	this->button_back1.setPosition(1000, 450);


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

	if (!this->you_lose.loadFromFile("Lose_Notification.png"))
	{
		cout << "Can not load" << endl;
	}
	this->you_lose1.setTexture(&this->you_lose);
	this->you_lose1.setSize(sf::Vector2f(400, 400));
	this->you_lose1.setPosition(675, 30);


	if (!this->instruct.loadFromFile("Instruction.png"))
	{
		cout << "Can not load" << endl;
	}
	this->instruction.setTexture(&this->instruct);
	this->instruction.setSize(sf::Vector2f(350, 350));
	this->instruction.setPosition(1550, 200);
}
void Menu::draw_menu(sf::RenderWindow& window)
{
	InnitMenuBackground();
	window.draw(this->MenuBackground);
	//window.draw(this->button_start);
	//window.draw(this->button_exit);
}
int Menu::Start_Play(sf::RenderWindow& window)
{
	float mouseX = sf::Mouse::getPosition(window).x;
	float mouseY = sf::Mouse::getPosition(window).y;

	if (mouseX >= button_start.getPosition().x && mouseX <= (button_start.getPosition().x + 200) && mouseY <= (button_start.getPosition().y + 200) && mouseY >= button_start.getPosition().y)
	{
		return 1;
	}
	if (mouseX >= button_exit.getPosition().x && mouseX <= (button_exit.getPosition().x + 200) && mouseY <= (button_exit.getPosition().y + 200) && mouseY >= button_exit.getPosition().y)
	{
		return 2;
	}
	return 0;
}
void Menu::LoseGame(sf::RenderWindow& window)
{
	//window.draw(this->continue_button);
	//window.draw(this->button_back1);
	window.draw(this->you_lose1);
}
int Menu::CheckMouseGamePlay(sf::RenderWindow& window)
{
	float mouseX = sf::Mouse::getPosition(window).x;
	float mouseY = sf::Mouse::getPosition(window).y;

	if (mouseX >= button_back.getPosition().x && mouseX <= (button_back.getPosition().x + 100) && mouseY <= (button_back.getPosition().y + 100) && mouseY >= button_back.getPosition().y)
	{
		return 1;
	}
	else if (mouseX >= button_resume.getPosition().x && mouseX <= (button_resume.getPosition().x + 100) && mouseY <= (button_resume.getPosition().y + 100) && mouseY >= button_resume.getPosition().y)
	{
		return 2;
	}
	return 0;
}
int Menu::ChoiceLoseGame(sf::RenderWindow& window)
{
	float mouseX = sf::Mouse::getPosition(window).x;
	float mouseY = sf::Mouse::getPosition(window).y;

	if (mouseX >= this->continue_button.getPosition().x && mouseX <= (this->continue_button.getPosition().x + 150) && mouseY <= (this->continue_button.getPosition().y + 150) && mouseY >= this->continue_button.getPosition().y)
	{
		return 1;
	}
	else if (mouseX >= this->button_back1.getPosition().x && mouseX <= (this->button_back1.getPosition().x + 150) && mouseY <= (this->button_back1.getPosition().y + 150) && mouseY >= button_resume.getPosition().y)
	{
		return 2;
	}
	return 0;
}
void Menu::Draw_Menu_In_game(sf::RenderWindow& window)
{

	this->button_start.setPosition(-1000, -1000);
	this->button_exit.setPosition(-1000, -1000);
	window.draw(this->menu_in_game);
	//window.draw(this->button_back);
	//window.draw(this->button_resume);
}
void Menu::Begin()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");
	CCAR b("car.png", 100, 100, 10, 10);
	Background d;
	sf::Font font;
	if (!font.loadFromFile("ayar.ttf"))
	{
		cout << " Fail to load";
	}

	Button play("PLAY GAME", { 200,50 }, 20, sf::Color::Green, sf::Color::Black);
	play.setPosition({ 100,400 });
	play.setFont(font);


	Button exit1("EXIT", { 200,50 }, 20, sf::Color::Green, sf::Color::Black);
	exit1.setPosition({ 100,600 });
	exit1.setFont(font);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::MouseMoved)
			{
				if (play.isMouseOver(window))
				{
					play.setBackColor(sf::Color::White);
				}
				else if (!play.isMouseOver(window))
				{
					play.setBackColor(sf::Color::Green);
				}

				if (exit1.isMouseOver(window))
				{
					exit1.setBackColor(sf::Color::White);
				}
				else if (!exit1.isMouseOver(window))
				{
					exit1.setBackColor(sf::Color::Green);
				}
			}
			if (event.type == sf::Event::MouseButtonPressed)
			{
				this->Menu_control(window, event, d, play, exit1);
			}

		}
		window.clear();
		this->draw_menu(window);
		play.drawTo(window);
		exit1.drawTo(window);
		window.display();
	}
}
void Menu::PlayGame(sf::RenderWindow& window, Background d, int& return1)
{
	if (return1 == 1) return;
	cout << "Start" << endl;
	CPEOPLE a(&window, 790, 900);
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
	sf::Font font;
	if (!font.loadFromFile("ayar.ttf"))
	{
		cout << " Fail to load";
	}
	int point = 0;
	Button Point("Point : " + to_string(point), { 200,50 }, 20, sf::Color::Green, sf::Color::Red);
	Point.setPosition({ 1600,100 });
	Point.setFont(font);
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
			window.draw(this->instruction);
			Point.drawTo(window);
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
					if (ev.key.code == sf::Keyboard::Up)
					{
						a.moveUp();
						point++;
						Point.SetText("Point : " + to_string(point));
					}
					/*else if (ev.key.code == sf::Keyboard::Down) a.moveDown();*/
					else if (ev.key.code == sf::Keyboard::Left) a.moveLeft();
					else if (ev.key.code == sf::Keyboard::Right) a.moveRight();
					else if (ev.key.code == sf::Keyboard::Escape)
					{
						while (window.isOpen())
						{
							Button resume("RESUME", { 200,50 }, 20, sf::Color::Green, sf::Color::Black);
							resume.setPosition({ 760,370 });
							resume.setFont(font);

							Button reset("RESET", { 200,50 }, 20, sf::Color::Green, sf::Color::Black);
							reset.setPosition({ 760,460 });
							reset.setFont(font);

							Button EXIT("EXIT", { 200,50 }, 20, sf::Color::Green, sf::Color::Black);
							EXIT.setPosition({ 760,550 });
							EXIT.setFont(font);

							int i1 = 0;
							while (window.pollEvent(ev))
							{
								if (ev.type == sf::Event::Closed)
								{
									window.close();
								}
								if (ev.type == sf::Event::MouseMoved)
								{
									if (resume.isMouseOver(window))
									{
										resume.setBackColor(sf::Color::White);
									}
									else if (!resume.isMouseOver(window))
									{
										resume.setBackColor(sf::Color::Green);
									}

									if (EXIT.isMouseOver(window))
									{
										EXIT.setBackColor(sf::Color::White);
									}
									else if (!EXIT.isMouseOver(window))
									{
										EXIT.setBackColor(sf::Color::Green);
									}

									if (reset.isMouseOver(window))
									{
										reset.setBackColor(sf::Color::White);
									}
									else if (!reset.isMouseOver(window))
									{
										reset.setBackColor(sf::Color::Green);
									}

								}
								if (ev.type == sf::Event::MouseButtonPressed)
								{
									if (/*this->CheckMouseGamePlay(window) == 1*/ EXIT.isMouseOver(window))
									{
										d.reload();
										i1 = 1;
										i = 1;
										return1 = 1;
										break;
									}
									else if (/*this->CheckMouseGamePlay(window) == 2*/ resume.isMouseOver(window))
									{
										d.reload();
										i1 = 1;
										break;
									}
									else if (reset.isMouseOver(window))
									{
										this->PlayGame(window, d, return1);
										if (return1 == 1) return;
									}
								}
								window.clear();
								d.blur_draw(window);
								this->Draw_Menu_In_game(window);
								reset.drawTo(window);
								resume.drawTo(window);
								EXIT.drawTo(window);
								window.display();
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

						Button resume("PLAY AGAIN", { 200,50 }, 20, sf::Color::Green, sf::Color::Black);
						resume.setPosition({ 500,450 });
						resume.setFont(font);

						Button EXIT("EXIT", { 200,50 }, 20, sf::Color::Green, sf::Color::Black);
						EXIT.setPosition({ 1000,450 });
						EXIT.setFont(font);

						while (window.pollEvent(ev))
						{
							if (ev.type == sf::Event::Closed)
							{
								window.close();
							}
							if (ev.type == sf::Event::MouseMoved)
							{
								if (resume.isMouseOver(window))
								{
									resume.setBackColor(sf::Color::White);
								}
								else if (!resume.isMouseOver(window))
								{
									resume.setBackColor(sf::Color::Green);
								}

								if (EXIT.isMouseOver(window))
								{
									EXIT.setBackColor(sf::Color::White);
								}
								else if (!EXIT.isMouseOver(window))
								{
									EXIT.setBackColor(sf::Color::Green);
								}

							}
							if (ev.type == sf::Event::MouseButtonPressed)
							{
								if (/*this->ChoiceLoseGame(window) == 1*/ resume.isMouseOver(window))
								{
									cout << "Yes" << endl;
									this->PlayGame(window, d, return1);
									if (return1 == 1) return;
									k = 1;
									i = 0;
									break;
								}
								else if (/*this->ChoiceLoseGame(window) == 2*/ EXIT.isMouseOver(window))
								{
									cout << "Yes1" << endl;
									k = 1;
									i = 1;
									return1 = 1;
									break;
								}
							}
						}
						window.clear();
						this->LoseGame(window);
						resume.drawTo(window);
						EXIT.drawTo(window);
						window.display();
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
void Menu::Menu_control(sf::RenderWindow& window, sf::Event event, Background d, Button b1, Button exit1)
{

	if (event.type == sf::Event::Closed)
		window.close();
	if (event.type == sf::Event::MouseButtonPressed)
	{
		int return1 = 0;
		if (/*this->Start_Play(window) == 1*/ b1.isMouseOver(window))
		{
			cout << "Start" << endl;
			this->PlayGame(window, d, return1);
		}
		else if (/*this->Start_Play(window) == 2*/ exit1.isMouseOver(window))
		{
			cout << "Exit" << endl;
			window.close();
		}
		else cout << "No" << endl;
	}
}