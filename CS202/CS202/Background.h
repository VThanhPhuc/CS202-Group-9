#pragma once
#ifndef  BACKGROUND_H
#define BAKGROUND_H

#define DELETE_KEY  8
#define ENTER_KEY  13
#define ESCAPE_KEY  27
#include <iostream>
#include <sstream>
#include "SFML/Graphics.hpp"

class Background
{
private:
	void loadTexture();// Loads the textures onto the game objects
	void blur_loadTexture()
	{
		m_texBottomPavement.loadFromFile("blur_background/Pavement_bottom.png");
		m_texCentralRes.loadFromFile("blur_background/CenteralRes.png");
		m_texTopPavement.loadFromFile("blur_background/Pavement_top.png");
		m_texRoad.loadFromFile("blur_background/Road.png");
		m_texRiver.loadFromFile("blur_background/river.png");


		rectBottomPavement.setTexture(&m_texBottomPavement);
		rectCentralRes.setTexture(&m_texCentralRes);
		rectTopRoad.setTexture(&m_texTopPavement);
		rectBottomRoad.setTexture(&m_texRoad);
		m_rectTopPavement.setTexture(&m_texTopPavement);
		rectRiver.setTexture(&m_texRiver);

	}
	// The elements that make up the background
	sf::RectangleShape rectTopRoad;
	sf::RectangleShape rectBottomRoad;
	sf::RectangleShape rectCentralRes;
	sf::RectangleShape rectBottomPavement;
	sf::RectangleShape rectRiver;

	// The textures that will be applied to the background elements
	sf::Texture m_texRoad;
	sf::Texture m_texTopPavement;
	sf::Texture m_texCentralRes;
	sf::Texture m_texBottomPavement;
	sf::Texture m_texRiver;

public:
	Background();
	void draw(sf::RenderWindow& window);
	void blur_draw(sf::RenderWindow& window)
	{
		this->blur_loadTexture();
		this->draw(window);
	}
	void reload()
	{
		this->loadTexture();
	}
	sf::RectangleShape m_rectTopPavement; // Public so the bounds can be checked
};

#endif 
