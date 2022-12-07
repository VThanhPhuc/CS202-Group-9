#pragma once
#include "Vehicle.h"

class Menu
{
private:
	sf::Sprite MenuBackground;
	sf::RectangleShape button_start;
	sf::RectangleShape button_exit;
	sf::RectangleShape button_back;

	sf::Texture t;
	sf::Texture exit_button;
	sf::Texture s_button;
	sf::Texture b_button;
public:
	void InnitMenuBackground();
	void draw_menu(sf::RenderWindow& window);
	void draw_gameplay(sf::RenderWindow& window);
	int IsMouseOver(sf::RenderWindow& window);
	int CheckMouseGamePlay(sf::RenderWindow& window);
};