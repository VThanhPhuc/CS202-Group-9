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

	if (!this->sound_on.loadFromFile("On_sound.png"))
	{
		cout << "Can not load" << endl;
	}
	this->Sound_on.setTexture(&this->sound_on);
	this->Sound_on.setSize(sf::Vector2f(60, 50));
	this->Sound_on.setPosition(120, 400);

	if (!this->music_on.loadFromFile("On_music.png"))
	{
		cout << "Can not load" << endl;
	}
	this->Music_on.setTexture(&this->music_on);
	this->Music_on.setSize(sf::Vector2f(90, 50));
	this->Music_on.setPosition(100, 600);

	if (!this->sound_off.loadFromFile("Off_sound.png"))
	{
		cout << "Can not load" << endl;
	}
	this->Sound_off.setTexture(&this->sound_off);
	this->Sound_off.setSize(sf::Vector2f(60,50));
	this->Sound_off.setPosition(120, 400);

	if (!this->music_off.loadFromFile("Off_music.png"))
	{
		cout << "Can not load" << endl;
	}
	this->Music_off.setTexture(&this->music_off);
	this->Music_off.setSize(sf::Vector2f(90, 50));
	this->Music_off.setPosition(100, 600);
}
void Menu::draw_menu(sf::RenderWindow& window)
{
	InnitMenuBackground();
	window.draw(this->MenuBackground);
}
void Menu::LoseGame(sf::RenderWindow& window)
{
	window.draw(this->you_lose1);
}
void Menu::Draw_Menu_In_game(sf::RenderWindow& window)
{
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

	loadpoint();

	Button play("PLAY GAME", { 200,50 }, 20, sf::Color::Green, sf::Color::Black);
	play.setPosition({ 100,350 });
	play.setFont(font);

	Button load("LOAD", { 200,50 }, 20, sf::Color::Green, sf::Color::Black);
	load.setPosition({ 600,350 });
	load.setFont(font);

	Button setting("SETTING", { 200,50 }, 20, sf::Color::Green, sf::Color::Black);
	setting.setPosition({ 1100,350 });
	setting.setFont(font);

	Button exit1("EXIT", { 200,50 }, 20, sf::Color::Green, sf::Color::Black);
	exit1.setPosition({ 1600,350 });
	exit1.setFont(font);

	string s = "           ON";
	Button sound(s, { 200,50 }, 20, sf::Color::Green, sf::Color::Black);
	sound.setPosition({ 100,400 });
	sound.setFont(font);

	string s1 = "           ON";
	Button music(s1, { 200,50 }, 20, sf::Color::Green, sf::Color::Black);
	music.setPosition({ 100,600 });
	music.setFont(font);
	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
			if(event.type == sf::Event::MouseMoved)
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

				if (setting.isMouseOver(*this->window))
				{
					setting.setBackColor(sf::Color::White);
				}
				else if (!setting.isMouseOver(*this->window))
				{
					setting.setBackColor(sf::Color::Green);
				}
			}
			if (event.type == sf::Event::MouseButtonPressed)
			{
				this->Menu_control(*this->window, event, d, play, exit1, load, setting, sound, music, s, s1);
			}
		}
		window->clear();
		this->draw_menu(*this->window);
		play.drawTo(*this->window);
		exit1.drawTo(*this->window);
		load.drawTo(*this->window);
		setting.drawTo(*this->window);
		window->display();
	}
}
void Menu::PlayGame(sf::RenderWindow& window, Background d, int& return1, bool playLoad, Button& sound, Button& music, string& s, string& s1)
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

	Button Point("Point : " + to_string(point), { 200,50 }, 20, sf::Color::Green, sf::Color::Red);
	Point.setPosition({ 1600,100 });
	Point.setFont(font);

	Button highPoint("High point : " + to_string(highpoint), { 200,50 }, 20, sf::Color::Green, sf::Color::Red);
	highPoint.setPosition({ 1600,600 });
	highPoint.setFont(font);

	Button back("", { 400,Constants::Height_screen }, 20, sf::Color::Black, sf::Color::Black);
	back.setPosition({ Constants::WidthRoad + 10,0 });

	sound.setPosition({ 1600,700 });
	music.setPosition({ 1600,800 });

	this->Sound_on.setPosition(1620, 700);
	this->Sound_off.setPosition(1620, 700);
	this->Music_on.setPosition(1600, 800);
	this->Music_off.setPosition(1600, 800);

	while (window.isOpen())
	{
		int i = 0;
		window.clear();
		while (window.isOpen())
		{
			window.clear();
			roadli->draw(*this->window);
			roadli->shiftObj('U',float(point));
			player->shiftObj(float(point));
			back.drawTo(window);
			window.draw(this->instruction);
			Point.drawTo(window);
			highPoint.drawTo(window);
			sound.drawTo(window);
			music.drawTo(window);
			if (s == "           ON")
			{
				window.draw(this->Sound_on);
			}
			else if (s == "           OFF")
			{
				window.draw(this->Sound_off);
			}
			if (s1 == "           ON")
			{
				window.draw(this->Music_on);
			}
			else if (s1 == "           OFF")
			{
				window.draw(this->Music_off);
			}
			window.setKeyRepeatEnabled(false);
			while (window.pollEvent(ev))
			{
				switch (ev.type)
				{
				case sf::Event::Closed:
					window.close();
				case sf::Event::KeyPressed:
					if (ev.key.code == sf::Keyboard::Up )
					{
						player->moveUp();
						point++;
						Point.SetText("Point : " + to_string(point));
						if (point > highpoint)
						{
							highpoint = point;
							highPoint.SetText("High point : " + to_string(highpoint));
						}
					}
					else if (ev.key.code == sf::Keyboard::W)
					{
						player->moveUp();
						point++;
						Point.SetText("Point : " + to_string(point));
						if (point > highpoint)
						{
							highpoint = point;
							highPoint.SetText("High point : " + to_string(highpoint));
						}
					}
					else if (ev.key.code == sf::Keyboard::Left ) player->moveLeft();
					else if (ev.key.code == sf::Keyboard::A) player->moveLeft();
					else if (ev.key.code == sf::Keyboard::Right ) player->moveRight();
					else if (ev.key.code == sf::Keyboard::D) player->moveRight();
					else if (ev.key.code == sf::Keyboard::Down ) {
						player->moveDown();
						point--;
						Point.SetText("Point : " + to_string(point));
					}
					else if (ev.key.code == sf::Keyboard::S) {
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

							Button save("SAVE", { 200,50 }, 20, sf::Color::Green, sf::Color::Black);
							save.setPosition({ 760,460 });
							save.setFont(font);

							Button reset("RESET", { 200,50 }, 20, sf::Color::Green, sf::Color::Black);
							reset.setPosition({ 760,550 });
							reset.setFont(font);

							Button EXIT("EXIT", { 200,50 }, 20, sf::Color::Green, sf::Color::Black);
							EXIT.setPosition({ 760,640 });
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

										sound.setPosition({ 100,400 });
										music.setPosition({ 100,600 });
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
										this->PlayGame(window, d, return1, false,sound,music,s,s1);
										if (return1 == 1) return;
									}
									else if (save.isMouseOver(window))
									{
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
				case sf::Event::MouseMoved:
					if (sound.isMouseOver(*this->window))
					{
						sound.setBackColor(sf::Color::White);
					}
					else if (!sound.isMouseOver(*this->window))
					{
						sound.setBackColor(sf::Color::Green);
					}

					if (music.isMouseOver(*this->window))
					{
						music.setBackColor(sf::Color::White);
					}
					else if (!music.isMouseOver(*this->window))
					{
						music.setBackColor(sf::Color::Green);
					}
					break;
				case sf::Event::MouseButtonPressed:
					if (sound.isMouseOver(window))
					{
						//switching sound
						if (s == "           ON")
						{
							turnSound();
							roadli->turnSound();
							player->turnSound();
							s = "           OFF";
						}
						else if (s == "           OFF")
						{
							turnSound();
							roadli->turnSound();
							player->turnSound();
							s = "           ON";
						}
						sound.SetText(s);
					}
					else if (music.isMouseOver(window))
					{
						//switching music
						if (s1 == "           ON")							
						{
							ingameSound.setVolume(0);
							s1 = "           OFF";
						}
						else if (s1 == "           OFF")
						{
							ingameSound.setVolume(60);
							s1 = "           ON";
						}
						music.SetText(s1);
					}
				}
			}
			for (auto road : roadli->roadList)
			{
				if (road->getObjLi() != NULL)
				{
					deque<COBJECT*>* cur = road->getObjLi();
					for (long i = 0; i < cur->size(); ++i)
					{
						if (player->isImpact(cur->at(i)))
						{
							if (soundOn)
								deathSound.play();

							Sleep(300);
							std::cout << "die" << endl;
							savepoint();

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

								Point.setPosition({ 740,600 });
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
											this->PlayGame(window, d, return1, false, sound, music, s, s1);
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

											sound.setPosition({ 100,400 });
											music.setPosition({ 100,600 });
											break;
										}
									}
								}
								window.clear();
								this->LoseGame(window);
								Point.drawTo(window);
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
			}
			roadli->update(*this->window);
			window.display();
			if (i == 1) break;
		}
		if (i == 1) break;
	}
}
void Menu::Menu_control(sf::RenderWindow& window, sf::Event event, Background d, Button b1, Button exit1, Button load, Button setting, Button& sound, Button& music, string& s, string& s1)
{
	if (event.type == sf::Event::Closed)
		window.close();
	if (event.type == sf::Event::MouseButtonPressed)
	{
		int return1 = 0;
		if (b1.isMouseOver(window))
		{
			this->PlayGame(window, d, return1, false, sound, music, s, s1);
		}
		else if (exit1.isMouseOver(window))
		{
			window.close();
		}
		else if (load.isMouseOver(window))
		{
			this->PlayGame(window, d, return1, true, sound, music, s, s1);
		}
		else if (setting.isMouseOver(window))
		{
			this->Setting(window, sound, music, s, s1);
		}
	}
}
void Menu::Setting(sf::RenderWindow& window, Button& sound, Button& music, string& s, string& s1)
{
	sf::Font font;
	if (!font.loadFromFile("ayar.ttf"))
	{
		cout << " Fail to load";
	}
	Button Return("RETURN", { 200,50 }, 20, sf::Color::Green, sf::Color::Black);
	Return.setPosition({ 100,800 });
	Return.setFont(font);

	while (window.isOpen())
	{
		window.clear();
		window.draw(this->MenuBackground);
		sound.drawTo(window);
		music.drawTo(window);
		Return.drawTo(window);
		if (s == "           ON")
		{
			window.draw(this->Sound_on);
		}
		else if (s == "           OFF")
		{
			window.draw(this->Sound_off);
		}
		if (s1 == "           ON")
		{
			window.draw(this->Music_on);
		}
		else if (s1 == "           OFF")
		{
			window.draw(this->Music_off);
		}

		while (window.pollEvent(ev))
		{
			if (ev.type == sf::Event::Closed)
				window.close();
			if (ev.type == sf::Event::MouseMoved)
			{
				if (sound.isMouseOver(*this->window))
				{
					sound.setBackColor(sf::Color::White);
				}
				else if (!sound.isMouseOver(*this->window))
				{
					sound.setBackColor(sf::Color::Green);
				}

				if (music.isMouseOver(*this->window))
				{
					music.setBackColor(sf::Color::White);
				}
				else if (!music.isMouseOver(*this->window))
				{
					music.setBackColor(sf::Color::Green);
				}

				if (Return.isMouseOver(*this->window))
				{
					Return.setBackColor(sf::Color::White);
				}
				else if (!Return.isMouseOver(*this->window))
				{
					Return.setBackColor(sf::Color::Green);
				}
			}
			if (ev.type == sf::Event::MouseButtonPressed)
			{
				if (Return.isMouseOver(window))
				{
					return;
				}
				if (sound.isMouseOver(window))
				{
					if (s == "           ON")
					{
						soundOn = false;
						s = "           OFF";
					}
					else if (s == "           OFF")
					{
						soundOn = true;
						s = "           ON";
					}
					sound.SetText(s);
				}
				else if (music.isMouseOver(window))
				{
					if (s1 == "           ON")
					{
						ingameSound.setVolume(0);
						s1 = "           OFF";
					}
					else if (s1 == "           OFF")
					{
						ingameSound.setVolume(60);
						s1 = "           ON";
					}
					music.SetText(s1);
				}
			}
		}
		window.display();

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
	/*initGame();*/
	//de cai nay thi bi dinh cai roadli->initRoad(); trong ham initGame();

	delete roadli;
	delete player;

	player = new CPEOPLE(this->window, 750, 700, soundOn);
	roadli = new CROADLIST(player, soundOn);
	point = 0;

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

void Menu::savepoint()
{
	ofstream fout;
	fout.open(Constants::pointFile, ios::binary);
	if (fout)
	{
		fout.write((char*)&highpoint, sizeof(highpoint));
		fout.close();
		cout << "Saving highest point successfully\n";
	}
	else
		cout << "Cannot save highest point to file!\n";
}

void Menu::loadpoint()
{
	ifstream fin;
	fin.open(Constants::pointFile, ios::binary);
	if (fin)
	{
		fin.read((char*)&highpoint, sizeof(highpoint));
		fin.close();
		cout << "Loading highest point successfully\n";
	}
	else
		highpoint = 0;
}

void Menu::turnSound()
{
	soundOn = !soundOn;
}
