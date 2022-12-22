#include "CARLANE.h"
#include <fstream>

CARLANE::CARLANE(sf::Vector2f pos) : CROAD()
{
	// main
	mX = pos.x;
	mY = pos.y /*- Constants::HeightRoad*/;
	texture = &LoadPic::GetIns().texture[file];
	out.setTexture(*texture);
	out.setPosition(mX, mY);
	if (rand() % Constants::numLights == 0)
	{
		light = CLight(mX, mY);
	}
}

CARLANE::CARLANE(float index) : CROAD()
{

	// main
	mX = 0;
	mY = index * Constants::HeightRoad - 2 * Constants::Height_HiddenRoad;

	// create texture
	texture = &LoadPic::GetIns().texture[file];
	out.setTexture(*texture);
	out.setPosition(mX, mY);

	if (rand() % Constants::numLights == 0) light = CLight(mX, mY);
}

CARLANE::CARLANE(float x, float y, bool traffic) :CROAD(x, y)
{
	// create texture
	texture = &LoadPic::GetIns().texture[file];
	out.setTexture(*texture);
	out.setPosition(mX, mY);

	//main
	if (traffic)
	{
		light = CLight(mX, mY);
	}
}

CARLANE::~CARLANE()
{
	carli.~CCARLIST();
}

void CARLANE::drawSubObj(sf::RenderWindow& window)
{
	if (light.Traffic())
	{
		light.draw(window);
	}
	carli.draw(window);
}

void CARLANE::shiftObj(char shift)
{
	carli.shiftObject(shift);
	if (light.Traffic())
	{
		light.shiftObject(shift);
	}
}

void CARLANE::update(sf::RenderWindow& window)
{
	if (light.Traffic())
	{
		light.update(window);
	}
	carli.update(mX, mY, window, light);
}

deque<COBJECT*>* CARLANE::getObjLi()
{
	return carli.getCarList();
}

void CARLANE::saveCarLane() {

}

void CARLANE::loadCarLane() {

}