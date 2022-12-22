#include "People.h"

CPEOPLE::CPEOPLE()
{
	mX = 750;
	mY = 500;
	mState = true; //1 is alive, 0 is dead
}
CPEOPLE::CPEOPLE(sf::RenderWindow* window, float x, float y)
{
	mX = x;
	mY = y;
	this->window = window;
	texture = &LoadPic::GetIns().texture["person"];

	sprite.setTexture(*texture);
	//sprite.setOrigin(50, 50);
	sprite.setPosition(mX, mY);
	mState = true;
}
bool CPEOPLE::isImpact(COBJECT*& obj)
{
	if (sprite.getGlobalBounds().intersects(obj->out.getGlobalBounds()))
	{
		return true;
	}
	return false;
}


bool CPEOPLE::isNearRoad(CROAD& road)
{
	if (mState == 0) return false;
	return abs((mY + (100 * 100) / 2) - 100 - 100) <= 250;

}

void CPEOPLE::die()
{
	cout << "DIE" << endl;
	mState = 0;
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

void CPEOPLE::shiftObj()
{
	sprite.move(0, Constants::ShiftVelocity);
}

void CPEOPLE::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}


void CPEOPLE::moveUp()
{
	cout << "Up" << endl;
	sprite.move(0, -Constants::HeightRoad);
	if (sprite.getPosition().y < 0)
	{
		sprite.move(0, Constants::HeightRoad);
	}
}
void CPEOPLE::moveDown()
{
	cout << "Down" << endl;
	sprite.move(0, Constants::HeightRoad);
	if (sprite.getPosition().y > (Constants::Height_screen - Constants::HeightRoad))
	{
		sprite.move(0, -Constants::HeightRoad);
	}
}
void CPEOPLE::moveRight()
{
	cout << "Right" << endl;
	sprite.move(Constants::width_person, 0);
	if (sprite.getPosition().x > (Constants::WidthRoad - Constants::width_person))
	{
		sprite.move(-Constants::width_person, 0);
	}

}
void CPEOPLE::moveLeft()
{
	cout << "Left" << endl;
	sprite.move(-Constants::width_person, 0);
	if (sprite.getPosition().x < 0)
	{
		sprite.move(Constants::width_person, 0);
	}
}




void CPEOPLE::Control()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		cout << "Up" << endl;
		--mY;
		if (mY < 0)
		{
			mY = 0;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		cout << "Left" << endl;
		--mX;
		if (mX < 0)
		{
			mX = 0;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		cout << "Right" << endl;
		++mX;
		if (mX > 1450)
		{
			mX = 1450;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		cout << "Down" << endl;
		++mY;
		if (mY > 1080) mY = 900;
	}
}
sf::Sprite CPEOPLE::getObj()
{
	return sprite;
}

