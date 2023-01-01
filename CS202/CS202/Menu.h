#pragma once
#include "Background.h"
#include "People.h"
#include "CCAR.h"
#include "textbox.h"
#include "button.h"
#include "CGAME.h"
#include "COBJECT.h"
#include "CROADLIST.h"
#include "SFML/Graphics.hpp"
class Menu
{
protected:
	sf::Sprite MenuBackground;
	//sf::RectangleShape button_start; // begin the game
	//sf::RectangleShape button_exit; // quit the game
/*	sf::RectangleShape button_back;*/ //get back to the menu
	sf::RectangleShape menu_in_game; // menu
	//sf::RectangleShape button_resume;

	//sf::RectangleShape continue_button;
	//sf::RectangleShape button_back1;
	sf::RectangleShape you_lose1;

	sf::RectangleShape instruction;

	sf::Texture t;
	//sf::Texture exit_button;
	//sf::Texture s_button;
	//sf::Texture b_button;
	sf::Texture menu_;
	//sf::Texture resume;
	//sf::Texture continue_p;
	//sf::Texture b1_button;
	sf::Texture you_lose;
	sf::Texture instruct;


	sf::RenderWindow* window;
	sf::Event ev;
	sf::VideoMode videoMode;
	// game obj
	CPEOPLE* player;
	CROADLIST* roadli;
	int point;
	//sound
	sf::Sound ingameSound;
	bool soundOn;
	// private function
	void initializeVariable()
	{
		srand((unsigned)time(0));
		this->window = nullptr;
	}
	void initGame()
	{
		delete roadli;
		delete player;

		player = new CPEOPLE(this->window, 750, 700);
		roadli = new CROADLIST(player, soundOn);
		roadli->initRoad();
		point = 0;
	}

public:
	Menu()
	{
		ingameSound = sf::Sound(LoadPic::GetIns().sound["ingame"]);
		ingameSound.setLoop(true);
		ingameSound.setVolume(60);
		ingameSound.play();
		soundOn = true;

		initializeVariable();
		//initGame();
	}
	~Menu()
	{
		delete roadli;
		delete player;
		delete this->window;
	}
	void InnitMenuBackground();
	void draw_menu(sf::RenderWindow& window);
	//int Start_Play(sf::RenderWindow& window);
	//int CheckMouseGamePlay(sf::RenderWindow& window);
	void Draw_Menu_In_game(sf::RenderWindow& window);
	void Menu_control(sf::RenderWindow& window, sf::Event event, Background d, Button b1, Button exit1, Button load);
	void LoseGame(sf::RenderWindow& window);
	//int ChoiceLoseGame(sf::RenderWindow& window);
	void Begin();
	void PlayGame(sf::RenderWindow& window, Background d, int& return1, bool playLoad);

	// save to file | load from file
	void save();
	void load();

	int getpoint();
	void setpoint(int point);
};