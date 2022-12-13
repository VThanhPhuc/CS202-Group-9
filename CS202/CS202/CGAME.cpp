#include "CGAME.h"
int CROAD::NumRoad = 0;
void CGAME::initializeVariable()
{
	srand((unsigned)time(0));
	this->window = nullptr;
}

void CGAME::initWindow()
{
	this->videoMode.height = Constants::Height_screen;
	this->videoMode.width = Constants::width_screen;

	this->window = new sf::RenderWindow(this->videoMode, "sfml works!", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);
	this->window->setVerticalSyncEnabled(true);


}

void CGAME::initGame()
{
	delete roadli;
	delete player;

	player = new CPEOPLE(this->window, 750, 500);
	roadli = new CROADLIST(player);
	roadli->initRoad();



	game_state = PLAYING;
}

// accessors
const bool CGAME::running() const
{
	return this->window->isOpen();
}



CGAME::CGAME()
{
	//gui.draw_menu(*this->window);

	game_state = MENU;
	this->initializeVariable();
	this->initWindow();
	initGame();

	game_state = PLAYING;
}

CGAME::~CGAME()
{
	delete roadli;
	delete player;
	delete this->window;
}

void CGAME::update() {
	pollEvent();
	if (roadli)
	{
		//if (game_state == PLAYING)
		//{
		checkMove();
		roadli->update(*this->window);
		//}
	}
}
bool CGAME::checkMove() {
	for (auto road : roadli->roadList) {
		if (road->getObjLi() != NULL)
		{
			deque<COBJECT*>* curRoad = road->getObjLi();

			for (long i = 0; i < curRoad->size(); i++)
			{
				bool collisionType = player->isImpact(curRoad->at(i));
				if (collisionType == true)
				{
					player->die();
					render();
					game_state = GAMEOVER;
					//Sleep(2000);
					//game_state = GAMEOVER;

				}
				return false;
			}
		}

	}
	return true;
}

void CGAME::pollEvent()
{
	game_state = PLAYING;
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyReleased:
			switch (ev.key.code) {
			case sf::Keyboard::Up:
				player->moveUp();
				break;
			case sf::Keyboard::Right:
				player->moveRight();
				break;
			case sf::Keyboard::Down:
				player->moveDown();
				break;
			case sf::Keyboard::Left:
				player->moveLeft();
				break;
			case sf::Keyboard::Escape:
				window->close();
				/*if (game_state == MENU)
					choiceMenu(gui->getChoice());
				else if (game_state == GAMEOVER)
					choiceGameOver(gui->getChoice());
				else if (game_state == PAUSE)
					choicePause(gui->getChoice());
				else if (game_state == SETTING)
					choiceSetting(gui->getChoice());
				*/
				break;
			}
			break;
		}
	}
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	//{
	//	player->moveUp();
	//	roadli->shiftObj('U');
	//	//if (!checkMove()) {
	//		//roadli->shiftObj('D');
	//	//}
	//}
	//else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	//{
	//	player->moveDown();
	//	roadli->shiftObj('D');
	//	//if (!checkMove())
	//	//{
	//		//roadli->shiftObj('U');
	//	//}
	//}
	//else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	//{
	//	player->moveLeft();
	//	/*if (!checkMove())
	//	{
	//		player->moveRight();
	//	}*/
	//
	//}
	//else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	//{
	//	player->moveRight(); 
	//	/*if (!checkMove())
	//	{
	//		player->moveLeft();
	//	}*/
	//}
	//else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	//{
	//	return;
	//}


}

void CGAME::run()
{
	while (running())
	{

		update();

		render();
	}
}

void CGAME::render()
{
	this->window->clear();
	game_state = PLAYING;
	//draw obj
	switch (game_state)
	{
	case MENU:
		//gui.draw_menu(*this->window);
		break;
	case PLAYING:
		roadli->draw(*this->window);
		break;
	case GAMEOVER:
		break;
	case PAUSE:
		roadli->draw(*this->window);

		break;
	case SETTING:
		break;
	}

	this->window->display();
}
/*
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

// accessors
const bool CGAME::running() const
{
	return this->window->isOpen();
}
*/