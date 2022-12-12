#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <random>

#include "Constants.h"

using namespace std;


class CLight {
private:
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
	void shiftObject(char shift);
	bool Traffic();
};

//class CLight {
//private:
//	int number;
//	bool on;
//	bool avail;//1: car, 0: animal
//public:
//	CLight(bool a);
//	void update();
//	bool geton();
//	bool getstatus();
//};