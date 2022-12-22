#include "CANIMALLIST.h"
#include <SFML/Audio.hpp>
#include <iostream>
#include <Windows.h>
#include "COBJECT.h"
#include <conio.h>
#include <mmsystem.h>
#include <cstdlib>
#include <ctime>
#include "Light.h"
#include <vector>

using namespace std;

CANIMALLIST::CANIMALLIST()
{
	type = ANITYPE(rand() % LASTTY);
	dir = ANIDIR(rand() % LASTDI);
}

void CANIMALLIST::initGame(float mX, float mY)
{
	/*int i = 0;*/
	while (Anlist.size() < Constants::NAnimal)
	{
		Anlist.push_front(createAnimal(mX, mY));
	}
}

deque<COBJECT*>* CANIMALLIST::getAniList()
{
	return &Anlist;
}
CANIMAL* CANIMALLIST::createAnimal(float mX, float mY)
{
	string t = "1";
	if (dir == TLEFT)
	{
		t = "0";
		//mX = Constants::WidthRoad / 4 * index;

		while (mX < Constants::WidthRoad + 100)
		{
			mX += Constants::widthAnimal;
		}
		if (!Anlist.empty())
		{
			while (mX < (Anlist.front()->getPos().x + 2 * Constants::widthAnimal + 10))
			{
				mX += Constants::widthAnimal;
			}
		}

	}
	else if (dir == TRIGHT)
	{
		//mX = Constants::WidthRoad / 4 * index;


		while (mX > (-Constants::widthAnimal - 50))
		{
			mX -= Constants::widthAnimal;
		}
		if (!Anlist.empty())
		{
			while (mX > (Anlist.front()->getPos().x - 2 * Constants::widthAnimal - 10))
			{
				mX -= Constants::widthAnimal;
			}
		}

	}

	return new CANIMAL(Constants::Animaltype[type]+t, mX, mY, Constants::speedAni[type], 2 * dir - 1);
}


void CANIMALLIST::update(float mX, float mY, sf::RenderWindow& window)
{
	for (auto i : Anlist)
	{
		i->move(0, 0);
	}
	if (Anlist.empty()) initGame(mX, mY);
	while (!Anlist.empty() && Anlist.back()->CheckOutWindow(window))
	{

		COBJECT* tmp = Anlist.back();
		Anlist.pop_back();
		delete tmp;

	}

}
int CANIMALLIST::direction()
{
	return dir;
}


void CANIMALLIST::shiftObject(char shift)
{
	for (auto i : Anlist)
	{
		i->shiftObject(shift);
	}
}

void CANIMALLIST::draw(sf::RenderWindow& window)
{
	for (auto i : Anlist)
	{
		i->draw(window);
	}

}

CANIMALLIST::~CANIMALLIST()
{
	while (!Anlist.empty())
	{
		COBJECT* temp = Anlist.front();
		Anlist.pop_front();
		delete temp;
	}
}