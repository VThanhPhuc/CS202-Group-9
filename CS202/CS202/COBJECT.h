#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <Windows.h>
#include "Light.h"
#include "Constants.h"
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
	sf::Sound sound;
public:
	friend class CROAD;
	friend class CPEOPLE;

	COBJECT(float x, float y);
	COBJECT(float x, float y, int direction);



	void shiftObject(char shift); // use char: U(up), D(down)

	

	
};


/*  old source
class COBJECT
{
protected:
	int mX, mY;
	int speed;

	bool isVisible;

	double objScale;
	sf::Sprite out;
	sf::SoundBuffer buffer;
	sf::Sound sound;
public:
	virtual void move(CLight l);
	virtual void draw(sf::RenderWindow& window, int type) = 0;
	virtual void tell() = 0;

	bool CheckOutWindow(sf::RenderWindow& window);

	COBJECT();
	COBJECT(int x, int y, int sp);
	int getmX();
	int getmY();
	int getspeed();
	virtual sf::Sprite getObj() = 0;
};


int getnextmod1500(int x, int sp);

class CCar : public COBJECT
{
private:

public:
	CCar(int x, int y, int sp);
	void draw(sf::RenderWindow& window, int type);
	void move(CLight l);
	sf::Sprite getObj();
	void setspr(int type);
	void tell() {};
};

class CBIRD :public COBJECT {
private:
	

public:
	CBIRD(int x, int y, int sp);
	void draw(sf::RenderWindow& window, int type);
	void move(CLight l);
	sf::Sprite getObj();
	void setspr(int type);
	void tell(){};
};
*/




//bool crash(CCar b, CCar c);

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
