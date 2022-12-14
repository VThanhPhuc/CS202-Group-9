#include "CROADLIST.h"

CROADLIST::CROADLIST(CPEOPLE* player, bool soundOn)
{
	this->player = player;
	this->soundOn = soundOn;
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
	else if (type == FREE)
	{
		return new CFREELANE(pos);
	}
}

CROAD* CROADLIST::createRoad(float index)
{
	RoadType type = RoadType(rand() % LAST);
	int diff = 1;
	if (type == FREE || index >= 10)
	{
		return new CFREELANE(index - diff);
	}
	else if (type == LANE)
	{
		return new CARLANE(index - diff);
	}
	else if(type == GRASS)
	{
		return new CGRASS(index - diff);
	}
}


void CROADLIST::shiftObj(char shift,const float& point)
{
	float go;
	go = up * min(point, maxi);
	mY += Constants::ShiftVelocity+go;
	if (mY > mY_origin)
		mY_origin = mY;
	for (auto it : roadList) it->shiftObject(shift,point);
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

		if (player->isNearRoad(*it) && soundOn)
		{
			playSound(*it);
		}
	}
}

void CROADLIST::save(ofstream& fout)
{
	fout.write((char*)&mY, sizeof(mY));
	fout.write((char*)&mX, sizeof(mX));
	fout.write((char*)&mY_origin, sizeof(mY_origin));

	for (auto i : roadList)
		i->save(fout);
}

void CROADLIST::load(ifstream& fin)
{
	fin.read((char*)&mY, sizeof(mY));
	fin.read((char*)&mX, sizeof(mX));
	fin.read((char*)&mY_origin, sizeof(mY_origin));
	int roadsNum = Constants::MAX_ROAD + 1;
	while (roadsNum--)
	{
		float x, y;	
		fin.read((char*)&x, sizeof(x));
		fin.read((char*)&y, sizeof(y));
		
		int isCarlane;
		bool isLight;
		fin.read((char*)&isCarlane, sizeof(isCarlane));
		fin.read((char*)&isLight, sizeof(isLight));
		
		if (isCarlane == 1)
			roadList.push_back(new CARLANE(x, y, isLight, fin));
		else if (isCarlane == 2)
			roadList.push_back(new CGRASS(x, y, fin));
		else
			roadList.push_back(new CFREELANE(x, y, fin));
	}
}

void CROADLIST::turnSound()
{
	soundOn = !soundOn;
}

void CROADLIST::playSound(CROAD& it)
{
	int type = it.soundType();
	if (type != -1)
	{
		mySound = sf::Sound(LoadPic::GetIns().sound[Constants::Soundtype[type]]);		
		mySound.play();
		it.setplaying();	
	}
}
