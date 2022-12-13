#pragma once

#include "COBJECT.h"
#include "CARLANE.h"


class CPEOPLE
{
private:
	float mX, mY;
	bool mState;

	sf::RenderWindow* window;


	sf::Texture* texture;
	sf::Sprite sprite;
public:
	CPEOPLE();
	CPEOPLE(sf::RenderWindow* window, float x, float y);
	

	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();


	//bool isImpact(CVEHICLE*&);
	//bool isImpact(CANIMAL*&);
	bool isImpact(COBJECT*& obj);
	bool isFinish();
	bool isDead();
	void die();
	int getmX();
	int getmY();
	void draw(sf::RenderWindow& window);
	void Control();
	bool isNearRoad(CROAD& road);
	sf::Sprite getObj();
};

/*
//<<<<<<< Updated upstream
class CPEOPLE
{
private:
	int mX, mY;
	bool mState;
protected:
	sf::Sprite sprite;
public:
	CPEOPLE();
	CPEOPLE(int x, int y);
	void Up(int);
	void Left(int);
	void Right(int);
	void Down(int);
	//bool isImpact(CVEHICLE*&);
	//bool isImpact(CANIMAL*&);
	bool isImpact(COBJECT*& obj);
	bool isFinish();
	bool isDead();
	int getmX();
	int getmY();
	void draw(sf::RenderWindow& window);
	void Control(int step);
	sf::Sprite getObj();
};
*/






//=======
//class CPEOPLE
//{
//private:
//	int mX, mY;
//	bool mState;
//protected:
//	sf::Sprite sprite;
//public:
//	CPEOPLE();
//	CPEOPLE(int x, int y);
//	void Up(int);
//	void Left(int);
//	void Right(int);
//	void Down(int);
//	bool isImpact(CVEHICLE*&);
//	bool isImpact(CANIMAL*&);
//	bool isFinish();
//	bool isDead();
//	int getmX();
//	int getmY();
//	void draw(sf::RenderWindow& window);
//	sf::Sprite getObj();
//};
//>>>>>>> Stashed changes
