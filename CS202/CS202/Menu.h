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
	void Menu_control(sf::RenderWindow& window, sf::Event event, Background d, CCar b);
};