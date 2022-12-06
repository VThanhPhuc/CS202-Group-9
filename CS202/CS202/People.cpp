#include "People.h"

const int step = 100;

CPEOPLE::CPEOPLE()
{
	mX = 0;
	mY = 0;
	mState = 1; //1 is alive, 0 is dead
}

void CPEOPLE::Up(int)
{
	if (mY - step < 0)
		mY = 0;
	else
		mY -= step;
}

void CPEOPLE::Left(int)
{
	mX += step;
}

void CPEOPLE::Right(int)
{
	if (mX - step < 0)
		mX = 0;
	else
		mX -= step;
}

void CPEOPLE::Down(int)
{
	mY += step;
}

bool CPEOPLE::isImpact(CVEHICLE*& v)
{
	if (mX == v->getmX() && mY == v->getmY())
	{
		mState = 0;
		return true;
	}
	return false;
}

bool CPEOPLE::isImpact(CANIMAL*& a)
{
	if (mX == a->getmX() && mY == a->getmY())
	{
		mState = 0;
		return true;
	}
	return false;
}

bool CPEOPLE::isFinish()
{
	return (mY == 0);
}

bool CPEOPLE::isDead()
{
	return !mState;
}

int CPEOPLE::getmX()
{
	return mX;
}

int CPEOPLE::getmY()
{
	return mY;
}

void CPEOPLE::draw(sf::RenderWindow& window)
{
	sf::Texture pic;
	if (!pic.loadFromFile("person.png"))
	{
		return;
	}
	sf::Sprite sprite(pic);
	sprite.setPosition(getmX(), getmY());
	sprite.setScale(0.1, 0.1);
	window.draw(sprite);
}