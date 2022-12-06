#include "CGAME.h"
void CGAME::initializeVariable()
{
	srand((unsigned)time(0));
	this->window = nullptr;
}

void CGAME::initWindow()
{
	this->videoMode.height = 1080;
	this->videoMode.width = 1920;

	this->window = new sf::RenderWindow(this->videoMode, "sfml works!", sf::Style::Titlebar | sf::Style::Fullscreen);
	this->window->setFramerateLimit(60);
	this->window->setVerticalSyncEnabled(true);

}

void CGAME::initGame()
{
	peo = new CPEOPLE(955, 1080);
	
	// init vehicle, animal

	game_state = PLAYING;
}