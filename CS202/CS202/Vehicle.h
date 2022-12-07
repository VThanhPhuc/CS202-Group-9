#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <Windows.h>
#include "Light.h"
using namespace std;


class COBJECT
{
protected:
	int mX, mY;
	int speed;

	bool isVisible;

	double objScale;

	int direction; // 1 - LR or -1  -RL

	sf::Texture* texture;
	sf::Sprite out;

public:
	virtual void move(CLight l);
	virtual void draw(sf::RenderWindow& window);
	virtual void tell(sf::SoundBuffer& buffer, sf::Sound& sound) = 0;

	bool CheckOutWindow(sf::RenderWindow& window);

	COBJECT();
	COBJECT(int x, int y, int sp);
	int getmX();
	int getmY();
	int getspeed();
	virtual sf::Sprite getObj() = 0;
};


int getnextmod1000(int x, int sp);

class CCar : public COBJECT
{
public:
	CCar(int x, int y, int sp);
	void draw(sf::RenderWindow& window);
	void move(CLight l);
	sf::Sprite getObj();
	void tell(sf::SoundBuffer& buffer, sf::Sound& sound) {};
};

class CBIRD :public COBJECT {
private:
public:
	CBIRD(int x, int y, int sp);
	void draw(sf::RenderWindow& window);
	void move();
	void tell(sf::SoundBuffer& buffer, sf::Sound& sound);
};
bool crash(CCar b, CCar c);

//class CVEHICLE {
//private:
//	int mX, mY;
//	int speed;
//protected:
//	sf::Sprite out;
//public:
//	virtual void move(CLight l);
//	virtual void draw(sf::RenderWindow& window);
//	CVEHICLE();
//	CVEHICLE(int x, int y, int sp);
//	int getmX();
//	int getmY();
//	int getspeed();
//	virtual sf::Sprite getObj() = 0;
//};
//
//class CCar :public CVEHICLE {
//private:
//public:
//	CCar(int x, int y, int sp);
//	void draw(sf::RenderWindow& window);
//	void move(CLight l);
//	sf::Sprite getObj();
//};
//
//class CTruck :public CVEHICLE {
//private:
//public:
//	CTruck(int x, int y, int sp);
//	void draw(sf::RenderWindow& window);
//	void move(CLight l);
//};
//
//class CANIMAL {
//private:
//	int mX, mY;
//	int speed;
//protected:
//	sf::Sprite out;
//public:
//	virtual void move();
//	virtual void draw(sf::RenderWindow& window);
//	virtual void tell(sf::SoundBuffer& buffer, sf::Sound& sound)=0;
//	
//	CANIMAL();
//	CANIMAL(int x, int y, int sp);
//	int getmX();
//	int getmY();
//	int getspeed();
//	sf::Sprite getObj();
//};
//
//class CBIRD :public CANIMAL {
//private:
//public:
//	CBIRD(int x, int y, int sp);
//	void draw(sf::RenderWindow& window);
//	void move();
//	void tell(sf::SoundBuffer& buffer, sf::Sound& sound);
//};
//
//class CDINO :public CANIMAL {
//private:
//public:
//	void draw(sf::RenderWindow& window);
//	void move();
//	void tell(sf::SoundBuffer& buffer, sf::Sound& sound);
//	
//};
