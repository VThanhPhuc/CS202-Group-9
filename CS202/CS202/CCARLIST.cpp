#include "CCARLIST.h"
#include <SFML/Audio.hpp>
#include <iostream>
#include <Windows.h>
#include "COBJECT.h"
#include <conio.h>
#include <mmsystem.h>
#include <cstdlib>
#include <ctime>
#include "Light.h"
#include "CCARLIST.h"
#include <vector>

using namespace std;

CCARLIST::CCARLIST()
{
	type = CARTYPE(rand() % LASTTYPE);
	dir = CARDIR(rand() % LASTDIR);
}

void CCARLIST::initGame(float mX, float mY)
{
	while (carlist.size() < 12)
	{
		carlist.push_front(createCar(mX, mY));
	}
}

deque<COBJECT*>* CCARLIST::getCarList()
{
	return &carlist;
}

CCAR* CCARLIST::createCar(float mX, float mY)
{
	if (dir == TORIGHT)
	{
		while (mX < Constants::WidthRoad)
		{
			mX += 20;
		}
		if (!carlist.empty())
		{
			while (mX < carlist.front()->getPos().x + 100)
			{
				mX += 20;
			}
		}

	}
	else if (dir == TOLEFT)
	{
		while (mX > -150)
		{
			mX -= 20;
		}
		if (!carlist.empty())
		{
			while (mX > carlist.front()->getPos().x - 200)
			{
				mX -= 20;
			}
		}

	}

	return new CCAR(Constants::Cartype[type], mX, mY, 2, 2 * dir - 1);
}


void CCARLIST::update(float mX, float mY, sf::RenderWindow& window, CLight& l)
{
	if (carlist.empty())
	{
		initGame(mX, mY);
	}
	else {
		for (auto i : carlist)
		{
			if (l.Traffic())
			{
				if (l.statusLight() == 2)
				{
					i->move(0, 0);
				}
				else if (l.statusLight() == 1)
				{
					i->move(0, 0);
				}
			}
			else
			{
				i->move(0, 0);
			}
		}
	}
	while (!carlist.empty() && carlist.back()->CheckOutWindow(window))
	{

		COBJECT* tmp = carlist.back();
		carlist.pop_back();
		delete tmp;
	}

}
