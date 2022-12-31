#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <Windows.h>
#include "Light.h"
#include "Constants.h"
#include "LoadPic.h"
using namespace std;

class COBJECT
{
protected:
	friend class CPEOPLE;
	friend class CGAME;

	float mX, mY;
	int speed;
	bool isVisible;
	int direction;

	sf::Texture* texture;
	sf::Sprite out;
	sf::SoundBuffer buffer;
	//sf::Sound sound;
public:
	friend class CROAD;
	friend class CPEOPLE;

	COBJECT(float x, float y);
	COBJECT(float x, float y, int direction = 1);

	void shiftObject(char shift); // use char: U(up), D(down)

	// virtual
	virtual void move(float x, float y, float frac = 1);
	virtual void draw(sf::RenderWindow& window);
	virtual int type() = 0;
	virtual void setVisible(bool);
	//virtual void tell() = 0;

	bool CheckOutWindow(sf::RenderWindow& window);
	sf::Vector2f getPos();	

	void save(ofstream& fout);
	//void load(ifstream& fin);
};

