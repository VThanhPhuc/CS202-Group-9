#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <random>

#include "Constants.h"
#include "LoadPic.h"

using namespace std;


class CLight {
private:
	int width = 60, height = 180;

	float mX;
	float mY;
	int status;
	float diff;
	sf::Clock clo;

	sf::Texture* texture;
	sf::Sprite out;

	bool traffic; // check the existence of things
public:
	CLight();
	CLight(float x, float y);
	int statusLight();
	void red();
	void green();
	void yellow();
	void update(sf::RenderWindow& window); // update picture after changing the light traffic
	void draw(sf::RenderWindow& window);
	void shiftObject(char shift,const float& point);
	bool Traffic();
};
