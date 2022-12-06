
#ifndef  BACKGROUND_H
#define BAKGROUND_H

#include "SFML/Graphics.hpp"

class Background
{
private:
	void loadTexture();// Loads the textures onto the game objects

	// The elements that make up the background
	sf::RectangleShape rectTopRoad;
	sf::RectangleShape rectBottomRoad;
	sf::RectangleShape rectCentralRes;
	sf::RectangleShape rectBottomPavement;

	// The textures that will be applied to the background elements
	sf::Texture m_texRoad;
	sf::Texture m_texTopPavement;
	sf::Texture m_texCentralRes;
	sf::Texture m_texBottomPavement;


public:
	Background();
	void draw(sf::RenderWindow& window);

	sf::RectangleShape m_rectTopPavement; // Public so the bounds can be checked

};

#endif 
