#include "Menu.h"
#include "CROADLIST.h"
#include "time.h"
#include <chrono>
using namespace std::chrono;
int CROAD::NumRoad = 0;
void Menu::InnitMenuBackground()
{
	if (!this->t.loadFromFile("universe.png"))
	{
		cout << "Can not load" << endl;
	};

	this->MenuBackground.setTexture(t);

	if (!this->menu_.loadFromFile("Menu_game.png"))
	{
		cout << "Can not load" << endl;
	};
	this->menu_in_game.setTexture(&this->menu_);
	this->menu_in_game.setSize(sf::Vector2f(700, 600));
	this->menu_in_game.setPosition(500, 200);

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
}
//int Menu::Start_Play(sf::RenderWindow& window)
//{
//	float mouseX = sf::Mouse::getPosition(window).x;
//	float mouseY = sf::Mouse::getPosition(window).y;
//
//	if (mouseX >= button_start.getPosition().x && mouseX <= (button_start.getPosition().x + 200) && mouseY <= (button_start.getPosition().y + 200) && mouseY >= button_start.getPosition().y)
//	{
//		return 1;
//	}
//	if (mouseX >= button_exit.getPosition().x && mouseX <= (button_exit.getPosition().x + 200) && mouseY <= (button_exit.getPosition().y + 200) && mouseY >= button_exit.getPosition().y)
//	{
//		return 2;
//	}
//	return 0;
//}
void Menu::LoseGame(sf::RenderWindow& window)
{
	window.draw(this->you_lose1);
}
//int Menu::CheckMouseGamePlay(sf::RenderWindow& window)
//{
//	float mouseX = sf::Mouse::getPosition(window).x;
//	float mouseY = sf::Mouse::getPosition(window).y;
//
//	if (mouseX >= button_back.getPosition().x && mouseX <= (button_back.getPosition().x + 100) && mouseY <= (button_back.getPosition().y + 100) && mouseY >= button_back.getPosition().y)
//	{
//		return 1;
//	}
//	else if (mouseX >= button_resume.getPosition().x && mouseX <= (button_resume.getPosition().x + 100) && mouseY <= (button_resume.getPosition().y + 100) && mouseY >= button_resume.getPosition().y)
//	{
//		return 2;
//	}
//	return 0;
//}
//int Menu::ChoiceLoseGame(sf::RenderWindow& window)
//{
//	float mouseX = sf::Mouse::getPosition(window).x;
//	float mouseY = sf::Mouse::getPosition(window).y;
//
//	if (mouseX >= this->continue_button.getPosition().x && mouseX <= (this->continue_button.getPosition().x + 150) && mouseY <= (this->continue_button.getPosition().y + 150) && mouseY >= this->continue_button.getPosition().y)
//	{
//		return 1;
//	}
//	else if (mouseX >= this->button_back1.getPosition().x && mouseX <= (this->button_back1.getPosition().x + 150) && mouseY <= (this->button_back1.getPosition().y + 150) && mouseY >= button_resume.getPosition().y)
//	{
//		return 2;
//	}
//	return 0;
//}
void Menu::Draw_Menu_In_game(sf::RenderWindow& window)
{

	//this->button_start.setPosition(-1000, -1000);
	//this->button_exit.setPosition(-1000, -1000);
	window.draw(this->menu_in_game);
}
void Menu::Begin()
{
	this->videoMode.height = 1000;
	this->videoMode.width = 1920;

	this->window = new sf::RenderWindow(this->videoMode, "Crossy Road!", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);
	this->window->setVerticalSyncEnabled(true);

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

	Button load("LOAD", { 200,50 }, 20, sf::Color::Green, sf::Color::Black);
	load.setPosition({ 100,800 });
	load.setFont(font);

	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
			if (event.type == sf::Event::MouseMoved)
			{
				if (play.isMouseOver(*this->window))
				{
					play.setBackColor(sf::Color::White);
				}
				else if (!play.isMouseOver(*this->window))
				{
					play.setBackColor(sf::Color::Green);
				}

				if (exit1.isMouseOver(*this->window))
				{
					exit1.setBackColor(sf::Color::White);
				}
				else if (!exit1.isMouseOver(*this->window))
				{
					exit1.setBackColor(sf::Color::Green);
				}

				if (load.isMouseOver(*this->window))
				{
					load.setBackColor(sf::Color::White);
				}
				else if (!load.isMouseOver(*this->window))
				{
					load.setBackColor(sf::Color::Green);
				}
			}
			if (event.type == sf::Event::MouseButtonPressed)
			{
				this->Menu_control(*this->window, event, d, play, exit1, load);
			}

		}
		window->clear();
		this->draw_menu(*this->window);
		play.drawTo(*this->window);
		exit1.drawTo(*this->window);
		load.drawTo(*this->window);
		window->display();
	}
}
void Menu::PlayGame(sf::RenderWindow& window, Background d, int& return1, bool playLoad)
{
	if (playLoad)
		this->load();
	else
		initGame();

	if (return1 == 1) return;

	cout << "Start" << endl;
	sf::Font font;
	if (!font.loadFromFile("ayar.ttf"))
	{
		cout << " Fail to load";
	}
	int point = getpoint();
	Button Point("Point : " + to_string(point), { 200,50 }, 20, sf::Color::Green, sf::Color::Red);
	Point.setPosition({ 1600,100 });
	Point.setFont(font);
	while (window.isOpen())
	{
		int i = 0;
		window.clear();
		while (window.isOpen())
		{
			window.clear();
			roadli->draw(*this->window);
			roadli->shiftObj('U');
			player->shiftObj();
			window.draw(this->instruction);
			Point.drawTo(window);
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
						player->moveUp();
						point++;
						Point.SetText("Point : " + to_string(point));
					}
					else if (ev.key.code == sf::Keyboard::Left) player->moveLeft();
					else if (ev.key.code == sf::Keyboard::Right) player->moveRight();
					else if (ev.key.code == sf::Keyboard::Down) { 
						player->moveDown();
						point--;
						Point.SetText("Point : " + to_string(point));
					}
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

							Button save("SAVE", { 200,50 }, 20, sf::Color::Green, sf::Color::Black);
							save.setPosition({ 760,640 });
							save.setFont(font);

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

									if (save.isMouseOver(window))
									{
										save.setBackColor(sf::Color::White);
									}
									else if (!save.isMouseOver(window))
									{
										save.setBackColor(sf::Color::Green);
									}
								}
								if (ev.type == sf::Event::MouseButtonPressed)
								{
									if (EXIT.isMouseOver(window))
									{
										d.reload();
										i1 = 1;
										i = 1;
										return1 = 1;
										break;
									}
									else if (resume.isMouseOver(window))
									{
										d.reload();
										i1 = 1;
										break;
									}
									else if (reset.isMouseOver(window))
									{
										this->PlayGame(window, d, return1, false);
										if (return1 == 1) return;
									}
									else if (save.isMouseOver(window))
									{
										setpoint(point);
										this->save();
										d.reload();
										i1 = 1;
										break;
									}
								}
								window.clear();
								d.blur_draw(window);
								this->Draw_Menu_In_game(window);
								reset.drawTo(window);
								resume.drawTo(window);
								EXIT.drawTo(window);
								save.drawTo(window);
								window.display();
							}
							if (i1 == 1) break;
						}
					}
					break;
				}
			}
			for (auto road : roadli->roadList)
			{
				deque<COBJECT*>* cur = road->getObjLi();
				for (long i = 0; i < cur->size(); ++i)
				{
					int f1 = 0;
					if (player->isImpact(cur->at(i)))
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
									if (resume.isMouseOver(window))
									{
										this->PlayGame(window, d, return1, false);
										if (return1 == 1) return;
										k = 1;
										i = 0;
										break;
									}
									else if (EXIT.isMouseOver(window))
									{
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
			}
			roadli->update(*this->window);
			window.display();
			if (i == 1) break;
		}
		if (i == 1) break;
	}
}
void Menu::Menu_control(sf::RenderWindow& window, sf::Event event, Background d, Button b1, Button exit1, Button load)
{

	if (event.type == sf::Event::Closed)
		window.close();
	if (event.type == sf::Event::MouseButtonPressed)
	{
		int return1 = 0;
		if (b1.isMouseOver(window))
		{
			this->PlayGame(window, d, return1, false);
		}
		else if (exit1.isMouseOver(window))
		{
			window.close();
		}
		else if (load.isMouseOver(window))
		{
			this->PlayGame(window, d, return1, true);
		}
	}
}

void Menu::save()
{
	ofstream fout;
	fout.open(Constants::dataFile, ios::binary);
	if (fout)
	{
		player->save(fout);
		fout.write((char*)&point, sizeof(point));
		roadli->save(fout);
		fout.close();
		cout << "Saving data successfully\n";
	}
	else
		cout << "Cannot save to file!\n";
}

void Menu::load()
{
	initGame();
	ifstream fin;
	fin.open(Constants::dataFile, ios::binary);
	if (fin)
	{
		player->load(fin);
		fin.read((char*)&point, sizeof(point));
		roadli->load(fin);
		fin.close();
		cout << "Loading data successfully\n";
		return;
	}
	else
		cout << "Cannot read file!\n";
}

int Menu::getpoint()
{
	return point;
}

void Menu::setpoint(int point)
{
	this->point = point;
}
