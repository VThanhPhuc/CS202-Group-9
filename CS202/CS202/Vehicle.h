#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>

using namespace std;
int getnextmod1000(int x, int sp);
class CVEHICLE {
private:
	int mX, mY;
	int speed;
public:
	virtual void move();
	virtual void draw(sf::RenderWindow& window);
	CVEHICLE();
	CVEHICLE(int x, int y, int sp);
	int getmX();
	int getmY();
	int getspeed();
};

class CCar :public CVEHICLE {
private:
	sf::Sprite out;
public:
	CCar(int x, int y, int sp);
	void draw(sf::RenderWindow& window);
	void move();
	sf::Sprite getObj();
};

class CTruck :public CVEHICLE {
private:
public:
	CTruck(int x, int y, int sp);
	void draw(sf::RenderWindow& window);
	void move();
};

class CANIMAL {
private:
	int mX, mY;
	int speed;
public:
	virtual void move();
	virtual void draw(sf::RenderWindow& window);
	virtual void tell(sf::SoundBuffer& buffer, sf::Sound& sound)=0;
	
	CANIMAL();
	CANIMAL(int x, int y, int sp);
	int getmX();
	int getmY();
	int getspeed();
};

class CBIRD :public CANIMAL {
private:
public:
	CBIRD(int x, int y, int sp);
	void draw(sf::RenderWindow& window);
	void move();
	void tell(sf::SoundBuffer& buffer, sf::Sound& sound);
};

class CDINO :public CANIMAL {
private:
public:
	void draw(sf::RenderWindow& window);
	void move();
	void tell(sf::SoundBuffer& buffer, sf::Sound& sound);
	
};