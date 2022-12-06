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
	void InnitMenuBackground();
	void draw(sf::RenderWindow& window);
	int IsMouseOver(sf::RenderWindow& window);
};