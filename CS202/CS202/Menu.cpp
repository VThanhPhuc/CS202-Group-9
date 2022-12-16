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

			while (window.isOpen())
			{
				window.clear();
				d.draw(window);
				this->draw_gameplay(window);
				b.draw(window);
				//c.draw(window);
				//p.draw(window);
				window.display();
				int i = 0;
				//b.move(l);
				//c.move(l);
				//p.Control(10,window);
				/*if (p.isImpact(b) == true)
				{
					cout << "Dung" << endl;
					break;
				}*/
				while (window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
						window.close();
					if (event.key.code == sf::Keyboard::Escape)
					{
						cout << "A" << endl;
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
										cout << "1" << endl;
										d.reload();
										i1 = 1;
										i = 1;
										break;
									}
									else if (this->CheckMouseGamePlay(window) == 2)
									{
										cout << "2" << endl;
										d.reload();
										i1 = 1;
										break;
									}
								}
							}
							if (i1 == 1) break;
						}
						//i = 1;
						break;
					}
				}
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