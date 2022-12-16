#include "CROADLIST.h"

CROADLIST::CROADLIST(CPEOPLE* player)
{
	this->player = player;
	mX = mY = 0;
	//mY_Origin = Constants::Height_HiddenRoad / 1.2;
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
	//RoadType type = RoadType(rand() % LAST);
	//if (type == LANE)
	//{

	return new CARLANE(pos);
	//}

}

CROAD* CROADLIST::createRoad(float index)
{

	//RoadType type = RoadType(rand() % LAST);
	int diff = 1;

	//if (type == LANE)
	//{
	return new CARLANE(index - diff);
	//}

}


void CROADLIST::shiftObj(char shift)
{
	if (shift == 'U' || shift == 'u')
	{
		mY += Constants::ShiftVelocity;
		for (auto it : roadList) it->shiftObject(shift);

	}
	else if ((shift == 'D' || shift == 'd'))
	{
		mY -= Constants::ShiftVelocity;
		for (auto it : roadList) it->shiftObject(shift);
	}

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
	if (mX > 1500)
	{
		roadList.push_front(createRoad(roadList.front()->getPos() + sf::Vector2f(0, 100)));
		roadList.front()->draw(window);
		mX = 0;
	}
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