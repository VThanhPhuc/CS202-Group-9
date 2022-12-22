#pragma once
#pragma once
#include "COBJECT.h"
#include "People.h"
//#include "Menu.h"
#include "Constants.h"
#include "CROADLIST.h"
#include "COBJECT.h"
enum GAME_STATUS { MENU, PLAYING, GAMEOVER, PAUSE, SETTING };

class CGAME
{
private:

	//Variables
	int highestPoint;
	GAME_STATUS game_state;
	GAME_STATUS preGame_state;


	// game obj
	CPEOPLE* player;
	CROADLIST* roadli;


	//window
	sf::RenderWindow* window;
	sf::Event ev;
	sf::VideoMode videoMode;

	//Menu gui;

	// private function
	void initializeVariable();
	void initWindow();
	void initGame();

public:
	// Constructor | destructor
	CGAME();
	~CGAME();


	//Accessors
	const bool running() const;

	// functions
	bool checkMove();
	void pollEvent();
	void update();
	void render();
	void run();

	// save to file | load from file

};

