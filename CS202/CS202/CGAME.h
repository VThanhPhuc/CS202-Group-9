#pragma once
#pragma once
#include "Vehicle.h"
#include "People.h"
#include "Menu.h"
enum GAME_STATUS { MENU, PLAYING, GAMEOVER, PAUSE, SETTING };

class CGAME
{
private:

	//Variables
	int highestPoint;
	GAME_STATUS game_state;
	GAME_STATUS preGame_state;

	

	CCar* car;
	CTruck* truck;
	CDINO* dino;
	CBIRD* bird;
	CPEOPLE* peo;

	//window
	sf::RenderWindow* window;
	sf::Event ev;
	sf::VideoMode videoMode;

	// obiect
	Menu m;

	// private function
	void initializeVariable();
	void initWindow();
	void initGame();

public:
	// Constructor | destructor
	// CGAME();
	// ~CGAME();

	//Accessors
	const bool running() const;
	
}

