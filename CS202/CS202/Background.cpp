#include "Background.h"

//Constructor
Background::Background()
{
	// set size of background elements
	rectBottomPavement.setSize(sf::Vector2f(1920, 270));
	rectBottomRoad.setSize(sf::Vector2f(1920, 270));
	rectCentralRes.setSize(sf::Vector2f(1920, 270));
	rectTopRoad.setSize(sf::Vector2f(1920, 270));
	m_rectTopPavement.setSize(sf::Vector2f(1920, 270));


	// set position of background elements
	rectBottomPavement.setPosition(sf::Vector2f(0, 0));
	rectBottomRoad.setPosition(sf::Vector2f(0, 270));
	rectCentralRes.setSize(sf::Vector2f(0, 540));
	rectTopRoad.setSize(sf::Vector2f(0, 810));
	loadTexture();
}


// Draws the background to the supplied window
void Background::draw(sf::RenderWindow& window)
{
	window.draw(rectTopRoad);
	window.draw(rectBottomRoad);
	window.draw(rectCentralRes);
	window.draw(rectBottomPavement);
}



void Background::loadTexture()
{
	m_texBottomPavement.loadFromFile("background/Pavement_bottom.png");
	m_texCentralRes.loadFromFile("background/CenteralRes.png");
	m_texTopPavement.loadFromFile("background/Pavement_top.png");
	m_texRoad.loadFromFile("background/Road.png");

	rectBottomPavement.setTexture(& m_texBottomPavement);
	rectCentralRes.setTexture(&m_texCentralRes);
	rectTopRoad.setTexture(&m_texTopPavement);
	rectBottomRoad.setTexture(&m_texRoad);
	m_rectTopPavement.setTexture(&m_texTopPavement);

}