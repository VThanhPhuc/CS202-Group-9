#include "People.h"

CPEOPLE::CPEOPLE()
{
	mX = 0;
	mY = 0;
	mState = 1; //1 is alive, 0 is dead
}
CPEOPLE::CPEOPLE(int x, int y)
{
	mX = x;
	mY = y;
	mState = 1;
}

void CPEOPLE::Up(int step)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		sf::Vector2f pos = this->sprite.getPosition();
		if (pos.y - step < 0)
			this->sprite.setPosition(pos.x, 0);
		else
			this->sprite.move(0, -step);
	}
}

void CPEOPLE::Left(int step)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		sf::Vector2f pos = this->sprite.getPosition();
		if (pos.x - step < 0)
			this->sprite.setPosition(0, pos.y);
		else
			this->sprite.move(-step, 0);
	}
}

void CPEOPLE::Right(int step)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		sf::Vector2f pos = this->sprite.getPosition();
		if (pos.x + step > screenwidth)
			this->sprite.setPosition(screenwidth, pos.y);
		else
			this->sprite.move(step, 0);
	}
}

void CPEOPLE::Down(int step)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		sf::Vector2f pos = this->sprite.getPosition();
		if (pos.y + step > screenheight)
			this->sprite.setPosition(pos.x, screenheight);
		else
			this->sprite.move(0, step);
	}
}

bool CPEOPLE::isImpact(CVEHICLE*& v)
{
	sf::FloatRect b1 = v->getObj().getGlobalBounds();
	sf::FloatRect b2 = this->getObj().getGlobalBounds();
	if (b1.intersects(b2) == true)
	{
		mState = 0;
		return true;
	}
	return false;
}

bool CPEOPLE::isImpact(CANIMAL*& a)
{
	sf::FloatRect b1 = a->getObj().getGlobalBounds();
	sf::FloatRect b2 = this->getObj().getGlobalBounds();
	if (b1.intersects(b2) == true)
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

void CPEOPLE::Control(int step)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		cout << "Up" << endl;
		mY -= step;
		if (mY < 0)
		{
			mY = 0;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		cout << "Left" << endl;
		mX -= step;
		if (mX < 0)
		{
			mX = 0;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		cout << "Right" << endl;
		mX += step;
		if (mX > 1450)
		{
			mX = 1450;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		cout << "Down" << endl;
		mY = mY + step;
		if (mY > 1080) mY = 900;
	}
}
sf::Sprite CPEOPLE::getObj() 
{
	return sprite;
}
