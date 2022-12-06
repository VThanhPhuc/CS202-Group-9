#pragma once
#include"Vehicle.h"

class CPEOPLE
{
private:
	int mX, mY;
	bool mState;
protected:
	sf::Sprite sprite;
public:
	CPEOPLE();
	void Up(int);
	void Left(int);
	void Right(int);
	void Down(int);
	bool isImpact(CVEHICLE*&);
	bool isImpact(CANIMAL*&);
	bool isFinish();
	bool isDead();
	int getmX();
	int getmY();
	void draw(sf::RenderWindow& window);
	sf::Sprite getObj();
};
