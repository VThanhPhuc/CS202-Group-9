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
	this->button_start.setPosition(100, 600);

	this->button_exit.setTexture(&this->exit_button);
	this->button_exit.setSize(sf::Vector2f(200, 200));
	this->button_exit.setPosition(400, 600);
}
void Menu::draw_menu(sf::RenderWindow& window)
{
	InnitMenuBackground();
	window.draw(this->MenuBackground);
	window.draw(this->button_start);
	window.draw(this->button_exit);
}
void Menu::draw_gameplay(sf::RenderWindow& window)
{
	if (!this->b_button.loadFromFile("b_button.png"))
	{
		cout << "Can not load" << endl;
	};
	this->button_back.setTexture(&this->b_button);
	this->button_back.setSize(sf::Vector2f(200, 200));
	this->button_back.setPosition(1600, 100);

	this->button_start.setPosition(-1000, -1000);
	this->button_exit.setPosition(-1000, -1000);
	window.draw(this->button_back);
}
int Menu::IsMouseOver(sf::RenderWindow& window)
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
int Menu::CheckMouseGamePlay(sf::RenderWindow& window)
{
	float mouseX = sf::Mouse::getPosition(window).x;
	float mouseY = sf::Mouse::getPosition(window).y;

	if (mouseX >= button_back.getPosition().x && mouseX <= (button_back.getPosition().x + 200) && mouseY <= (button_back.getPosition().y + 200) && mouseY >= button_back.getPosition().y)
	{
		return 1;
	}
	return 0;
}