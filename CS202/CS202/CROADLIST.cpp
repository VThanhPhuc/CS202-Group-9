#include "CROADLIST.h"

CROADLIST::CROADLIST(CPEOPLE* player)
{
	this->player = player;
	mX = mY = 0;
	mY_origin = Constants::Height_HiddenRoad;
}

CROADLIST::~CROADLIST()
{
	for (auto it : roadList)
	{
		delete it;
	}
}

void CROADLIST::initRoad()
{
	while (CROAD::getNumRoads() <= Constants::MAX_ROAD)
	{
		roadList.push_front(createRoad(Constants::MAX_ROAD - CROAD::getNumRoads()));
	}
}


CROAD* CROADLIST::createRoad(sf::Vector2f pos)
{
	RoadType type = RoadType(rand() % LAST);
	if (type == LANE)
	{
		return new CARLANE(pos);
	}
	else if (type == GRASS)
	{
		return new CGRASS(pos);
	}

}

CROAD* CROADLIST::createRoad(float index)
{
	RoadType type = RoadType(rand() % LAST);
	int diff = 1;

	if (type == LANE)
	{
		return new CARLANE(index - diff);
	}
	else if(type == GRASS)
	{
		return new CGRASS(index - diff);
	}
}


void CROADLIST::shiftObj(char shift)
{
	mY += Constants::ShiftVelocity;
	if (mY > mY_origin)
		mY_origin = mY;
	for (auto it : roadList) it->shiftObject(shift);
	/*else if ((shift == 'D' || shift == 'd') && ((mY_origin - mY) <= Constants::Height_HiddenRoad))
	{
		mY -= Constants::ShiftVelocity;
		for (auto it : roadList) it->shiftObject(shift);
	}*/
}

void CROADLIST::draw(sf::RenderWindow& window)
{
	for (auto it : roadList)
	{
		it->draw(window);
		player->draw(window);

		it->drawSubObj(window);


	}
}

void CROADLIST::update(sf::RenderWindow& window)
{
	/*if (mY > Constants::Height_screen)
	{
		roadList.push_front(createRoad(roadList.front()->getPos() + sf::Vector2f(0, 100)));
		roadList.front()->draw(window);
		mY = -200;
	}*/
	if (roadList.back()->checkoutwindow(window))
	{
		roadList.push_front(createRoad(roadList.front()->getPos()));
		roadList.front()->draw(window);

		CROAD* tmp = roadList.back();
		roadList.pop_back();
		delete tmp;
	}
	for (auto it : roadList)
	{
		it->update(window);
	}
}
