#pragma once
#include "Background.h"
#include "People.h"
#include "CCAR.h"
#include "textbox.h"
#include "button.h"
#include "COBJECT.h"
#include "CROADLIST.h"
#include "SFML/Graphics.hpp"
class Menu
{
protected:
	sf::Sprite MenuBackground;
	sf::RectangleShape menu_in_game; 
	sf::RectangleShape you_lose1;
	sf::RectangleShape instruction;

	sf::Texture t;
	sf::Texture menu_;
	sf::Texture you_lose;
	sf::Texture instruct;

	sf::Texture sound_on;
	sf::Texture sound_off;
	sf::Texture music_on;
	sf::Texture music_off;

	sf::RectangleShape Sound_on;
	sf::RectangleShape Sound_off;
	sf::RectangleShape Music_on;
	sf::RectangleShape Music_off;

	sf::RenderWindow* window;
	sf::Event ev;
	sf::VideoMode videoMode;
	// game obj
	CPEOPLE* player;
	CROADLIST* roadli;
	int point;
	int highpoint;
	//sound
	sf::Sound ingameSound;
	sf::Sound deathSound;
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

		player = new CPEOPLE(this->window, 750, 700, soundOn);
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

		deathSound = sf::Sound(LoadPic::GetIns().sound["death"]);
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
	void Draw_Menu_In_game(sf::RenderWindow& window);
	void Menu_control(sf::RenderWindow& window, sf::Event event, Background d, Button b1, Button exit1, Button load, Button setting);
	void LoseGame(sf::RenderWindow& window);
	void Begin();
	void PlayGame(sf::RenderWindow& window, Background d, int& return1, bool playLoad);

	void save();
	void load();

	void savepoint();
	void loadpoint();
};
