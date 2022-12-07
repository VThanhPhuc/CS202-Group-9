#include <SFML/Audio.hpp>
#include <iostream>
#include <Windows.h>
#include "Vehicle.h"
#include <conio.h>
#include <mmsystem.h>
#include <cstdlib>
#include <ctime>
#include "Light.h"
using namespace std;


void CCar::draw(sf::RenderWindow& window) {}
int getnextmod1000(int x, int sp)
{
	x = x + sp;
	if (x < 0)
		return x + 1000;
	else if (x > 1000)
		return x - 1000;
	else
		return x;
}

bool COBJECT::CheckOutWindow(sf::RenderWindow& window)
{
	window.getSize().x;
}

int COBJECT::getmX() {
	return mX;
}
int COBJECT::getmY() {
	return mY;
}
int COBJECT::getspeed() {
	return speed;
}
COBJECT::COBJECT() {
	mX = 0;
	mY = 0;
	speed = 1;
}
COBJECT::COBJECT(int x, int y, int sp) {
	mX = x;
	mY = y;
	speed = sp;
}
void COBJECT::move(CLight l) {
	if (l.geton() == true)
		mX = getnextmod1000(mX, speed);
	out.move(speed, 0);
}


void CCar::move(CLight l) {
	COBJECT::move(l);
}
void CCar::draw(sf::RenderWindow& window) {
	sf::Texture pic;
	if (getspeed() > 0) {
		pic.loadFromFile("car1.png");
	}
	else {
		pic.loadFromFile("car.png");
	}
	out.setTexture(pic);
	out.setPosition(getmX(), getmY() * 40);
	window.draw(out);
}

void CBIRD::draw(sf::RenderWindow& window) {
	sf::Texture pic;
	if (getspeed() > 0) {
		pic.loadFromFile("bird.png");
	}
	else {
		pic.loadFromFile("bird1.png");
	}
	sf::Sprite out;
	out.setTexture(pic);
	out.setPosition(getmX() * 10, getmY() * 40);
	window.draw(out);
}

//void CVEHICLE::draw(sf::RenderWindow& window){}
//int getnextmod1000(int x, int sp) {
//	x = x + sp;
//	if (x < 0)
//		return x + 1000;
//	else if (x > 1000)
//		return x - 1000;
//	else
//		return x;
//}
//int CVEHICLE::getmX() {
//	return mX;
//}
//int CVEHICLE::getmY() {
//	return mY;
//}
//int CVEHICLE::getspeed() {
//	return speed;
//}
//CVEHICLE::CVEHICLE() {
//	mX = 0;
//	mY = 0;
//	speed = 1;
//}
//CVEHICLE::CVEHICLE(int x, int y, int sp) {
//	mX = x;
//	mY = y;
//	speed = sp;
//}
//void CVEHICLE::move(CLight l) {
//	if(l.geton()==true)
//	mX = getnextmod1000(mX,speed);
//	//out.move(speed, 0);
//}
//
//
// 
//void CCar::move(CLight l) {
//	CVEHICLE::move(l);
//}
//void CCar::draw(sf::RenderWindow& window) {
//	sf::Texture pic;
//	if (getspeed() > 0) {
//		pic.loadFromFile("car1.png");
//	}
//	else {
//		pic.loadFromFile("car.png");
//	}
//	out.setTexture(pic);
//	out.setPosition(getmX(), getmY()*40);
//	window.draw(out);
//}
//
//
//void CTruck::move(CLight l) {
//	CVEHICLE::move(l);
//}
//void CTruck::draw(sf::RenderWindow& window) {
//	sf::Texture pic;
//	if (getspeed() > 0) {
//		pic.loadFromFile("truck.png");
//	}
//	else {
//		pic.loadFromFile("truck1.png");
//	}
//	out.setTexture(pic);
//	out.setPosition(getmX() * 10, getmY() * 40);
//	window.draw(out);
//}
//CANIMAL::CANIMAL() {
//	mX = 0;
//	mY = 0;
//	speed = 1;
//}
//CANIMAL::CANIMAL(int x, int y, int sp) {
//	mX = x;
//	mY = y;
//	speed = sp;
//}
//
//int CANIMAL::getmX() {
//	return mX;
//}
//int CANIMAL::getmY() {
//	return mY;
//}
//int CANIMAL::getspeed() {
//	return speed;
//}
//void CANIMAL::move() {
//	mX = getnextmod1000(mX, speed);
//}
//void CANIMAL::draw(sf::RenderWindow& window) {}
//
//sf::Sprite CANIMAL::getObj()
//{
//	return out;
//}
//
//void CBIRD::draw(sf::RenderWindow& window) {
//	sf::Texture pic;
//	if (getspeed() > 0) {
//		pic.loadFromFile("bird.png");
//	}
//	else {
//		pic.loadFromFile("bird1.png");
//	}
//	sf::Sprite out;
//	out.setTexture(pic);
//	out.setPosition(getmX() * 10, getmY() * 40);
//	window.draw(out);
//}
//
//
//void CBIRD::move() {
//	CANIMAL::move();
//}
//void CDINO::draw(sf::RenderWindow& window) {
//	sf::Texture pic;
//	if (getspeed() > 0) {
//		pic.loadFromFile("dino.png");
//	}
//	else {
//		pic.loadFromFile("dino1.png");
//	}
//	sf::Sprite out;
//	out.setTexture(pic);
//	out.setPosition(getmX() * 10, getmY() * 40);
//	window.draw(out);
//}
//
//void CDINO::move() {
//	CANIMAL::move();
//}
//void CANIMAL::tell(sf::SoundBuffer& buffer, sf::Sound& sound){}
//void CDINO::tell(sf::SoundBuffer& buffer, sf::Sound& sound) {
//	if (!buffer.loadFromFile("dino.wav"))
//		return;
//	sound.setBuffer(buffer);
//}
//void CBIRD::tell(sf::SoundBuffer& buffer, sf::Sound& sound){
//	if (!buffer.loadFromFile("bird.wav"))
//		return ;
//	sound.setBuffer(buffer);
//
//}
//CCar::CCar(int x, int y, int sp) :CVEHICLE(x, y, sp) {}
//CTruck::CTruck(int x, int y, int sp) :CVEHICLE(x, y, sp) {}
//CBIRD::CBIRD(int x, int y, int sp) :CANIMAL(x, y, sp) {}
//sf::Sprite CCar::getObj() {
//	return out;
//}
//bool crash(CCar b, CCar c) {
//	sf::Sprite car1 = b.getObj();
//	sf::Sprite car2 = c.getObj();
//	sf::FloatRect b1 = car1.getGlobalBounds();
//	sf::FloatRect b2 = car2.getGlobalBounds();
//	if (b1.intersects(b2) == true) {
//		return true;
//	}
//	return false;
//
//}