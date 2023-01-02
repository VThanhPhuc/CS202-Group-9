#pragma once

#include "COBJECT.h"
#include "CARLANE.h"


class CPEOPLE
{
private:
	friend class CLANE;
	float mX, mY;
	bool mState;

	sf::RenderWindow* window;

	sf::SoundBuffer* buffer;
	sf::Sound step;
	bool soundOn;

	sf::Texture* texture;
	sf::Sprite sprite;
public:
	CPEOPLE();
	CPEOPLE(sf::RenderWindow* window, float x, float y, bool soundOn);
	

	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();
	void shiftObj();

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
	void save(ofstream& fout);
	void load(ifstream& fin);
	void turnSound();
};

