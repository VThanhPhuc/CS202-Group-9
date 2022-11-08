#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>

using namespace std;

class CVEHICLE {
private: 
	int mX, mY;
	int speed;
public:
	virtual void move();
	virtual void draw(sf::RenderWindow window);
	CVEHICLE();
	CVEHICLE(int x, int y, int sp);
	int getmX();
	int getmY();
	int getspeed();
};

void CVEHICLE::draw(sf::RenderWindow window){}
int getnextmod200(int x, int sp) {
	x = x + sp;
	if (x < 0)
		return x + 200;
	else if (x > 200)
		return x + 200;
	else
		return x;
}
int CVEHICLE::getmX() {
	return mX;
}
int CVEHICLE::getmY() {
	return mY;
}
int CVEHICLE::getspeed() {
	return speed;
}
CVEHICLE::CVEHICLE() {
	mX = 0;
	mY = 0;
	speed = 1;
}
CVEHICLE::CVEHICLE(int x, int y, int sp) {
	mX = x;
	mY = y;
	speed = sp;
}
void CVEHICLE::move() {
	mX = getnextmod200(mX,speed);
}

class CCar :public CVEHICLE {
private:
public:
	void draw(sf::RenderWindow& window);
	void move();
};
 
void CCar::move() {
	CVEHICLE::move();
}
void CCar::draw(sf::RenderWindow& window) {
	sf::Texture pic;
	if (getspeed() > 0) {
		pic.loadFromFile("car.png");
	}
	else {
		pic.loadFromFile("car1.png");
	}
	sf::Sprite out;
	out.setTexture(pic);
	out.setPosition(getmX()*30, getmY()*40);
	window.draw(out);
}

class CTruck :public CVEHICLE {
private:
public:
	void draw(sf::RenderWindow& window);
	void move();
};
void CTruck::move() {
	CVEHICLE::move();
}
void CTruck::draw(sf::RenderWindow& window) {
	sf::Texture pic;
	if (getspeed() > 0) {
		pic.loadFromFile("truck.png");
	}
	else {
		pic.loadFromFile("truck1.png");
	}
	sf::Sprite out;
	out.setTexture(pic);
	out.setPosition(getmX() * 30, getmY() * 40);
	window.draw(out);
}
