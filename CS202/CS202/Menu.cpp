#include "Menu.h"
void Menu::InnitMenuBackground()
{
	if (!this->t.loadFromFile("universe.png"))
	{
		cout << "Can not load" << endl;
	};
	if (!this->button.loadFromFile("button.png"/*,sf::IntRect(100,100,200,200))*/))
	{
		cout << "Can not load" << endl;
	};
	this->MenuBackground.setTexture(t);

	this->button_start.setTexture(&this->button);
	this->button_start.setSize(sf::Vector2f(200, 200));
	this->button_start.setPosition(100, 600);

	this->button_exit.setTexture(&this->button);
	this->button_exit.setSize(sf::Vector2f(200, 200));
	this->button_exit.setPosition(400, 600);
}
void Menu::draw(sf::RenderWindow& window)
{
	InnitMenuBackground();
	window.draw(this->MenuBackground);
	window.draw(this->button_start);
	window.draw(this->button_exit);
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