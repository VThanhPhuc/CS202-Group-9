#pragma once
#include"Vehicle.h"

#define screenheight 1920
#define screenwidth 1980

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
