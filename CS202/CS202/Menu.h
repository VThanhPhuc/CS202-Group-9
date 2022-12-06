#pragma once
#include "Vehicle.h"

class Menu
{
private:
	sf::Sprite MenuBackground;
	sf::RectangleShape button_start;
	sf::RectangleShape button_exit;

	sf::Texture t;
	sf::Texture button;
public:
	void InnitMenuBackground()
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
};