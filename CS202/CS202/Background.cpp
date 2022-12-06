#include "Background.h"

//Constructor
Background::Background()
{
	// set size of background elements
	rectBottomPavement.setSize(sf::Vector2f(1500, 80));
	rectBottomRoad.setSize(sf::Vector2f(1500, 100));
	rectCentralRes.setSize(sf::Vector2f(1500, 100));
	rectTopRoad.setSize(sf::Vector2f(1500, 100));
	m_rectTopPavement.setSize(sf::Vector2f(1500, 100));
	rectRiver.setSize(sf::Vector2f(1500, 100));

	//// set position of background elements
	//rectBottomPavement.setPosition(sf::Vector2f(0, 300));
	//rectBottomRoad.setPosition(sf::Vector2f(0, 100));
	//rectCentralRes.setPosition(sf::Vector2f(0, 200));
	//rectTopRoad.setPosition(sf::Vector2f(0,0));
	loadTexture();
}


// Draws the background to the supplied window
void Background::draw(sf::RenderWindow& window)
{
	//top
	window.draw(m_rectTopPavement);
	

	rectBottomRoad.setPosition(sf::Vector2f(0, 100));
	rectCentralRes.setPosition(sf::Vector2f(0, 200));
	window.draw(rectBottomRoad);
	window.draw(rectCentralRes);

	rectBottomRoad.setPosition(sf::Vector2f(0, 300));
	rectCentralRes.setPosition(sf::Vector2f(0, 400));
	window.draw(rectBottomRoad);
	window.draw(rectCentralRes);

	// central
	rectRiver.setPosition(sf::Vector2f(0, 500));
	window.draw(rectRiver);

	rectCentralRes.setPosition(sf::Vector2f(0, 600));
	window.draw(rectCentralRes);


	rectBottomRoad.setPosition(sf::Vector2f(0, 700));
	rectCentralRes.setPosition(sf::Vector2f(0, 800));
	window.draw(rectBottomRoad);
	window.draw(rectCentralRes);

	rectBottomRoad.setPosition(sf::Vector2f(0, 900));
	window.draw(rectBottomRoad);

	//bottom
	rectBottomPavement.setPosition(sf::Vector2f(0, 1000));
	window.draw(rectBottomPavement);


}



void Background::loadTexture()
{
	m_texBottomPavement.loadFromFile("background/Pavement_bottom.png");
	m_texCentralRes.loadFromFile("background/CenteralRes.png");
	m_texTopPavement.loadFromFile("background/Pavement_top.png");
	m_texRoad.loadFromFile("background/Road.png");
	m_texRiver.loadFromFile("background/river.png");


	rectBottomPavement.setTexture(&m_texBottomPavement);
	rectCentralRes.setTexture(&m_texCentralRes);
	rectTopRoad.setTexture(&m_texTopPavement);
	rectBottomRoad.setTexture(&m_texRoad);
	m_rectTopPavement.setTexture(&m_texTopPavement);
	rectRiver.setTexture(&m_texRiver);

}