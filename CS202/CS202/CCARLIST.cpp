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
	/*int i = 0;*/
	while (carlist.size() < Constants::NCar)
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
	string t = "1";
	if (dir == TOLEFT)
	{
		t = "0";
		//mX = Constants::WidthRoad / 4 * index;

		while (mX < Constants::WidthRoad + 100)
		{
			mX += Constants::widthVehicle;
		}
		if (!carlist.empty())
		{
			while (mX < (carlist.front()->getPos().x + 3*Constants::widthVehicle + 10))
			{
				mX += Constants::widthVehicle;
			}
		}

	}
	else if (dir == TORIGHT)
	{
		//mX = Constants::WidthRoad / 4 * index;


		while (mX > (-Constants::widthVehicle-100))
		{
			mX -= Constants::widthVehicle;
		}
		if (!carlist.empty())
		{
			while (mX > (carlist.front()->getPos().x - 3 * Constants::widthVehicle - 10))
			{
				mX -= Constants::widthVehicle;
			}
		}

	}
	return new CCAR(Constants::Cartype[type]+t, mX, mY, Constants::speedCar[type], 2 * dir - 1);
}


void CCARLIST::update(float mX, float mY, sf::RenderWindow& window, CLight& l)
{
	for (auto i : carlist)
	{

		if (l.Traffic())
		{
			if (l.statusLight() == 2)
			{
				i->move(0, 0, 0.35);
			}
			else if (l.statusLight() == 1)
			{
				i->move(0, 0, 0.15);
			}
			else if (l.statusLight() == 0)
			{
				i->move(0, 0, 0);
			}
		}
		else
		{
			i->move(0, 0);
		}

	}
	mY += 3;
	if (carlist.empty()) initGame(mX, mY);
	while (!carlist.empty() && carlist.back()->CheckOutWindow(window))
	{
		COBJECT* tmp = carlist.back();
		carlist.pop_back();
		delete tmp;
	}
}
int CCARLIST::direction()
{
	return dir;
}


void CCARLIST::shiftObject(char shift,const float& point)
{
	for (auto i : carlist)
	{
		i->shiftObject(shift,point);
	}
}

void CCARLIST::draw(sf::RenderWindow& window)
{
	for (auto i : carlist)
	{
		i->draw(window);
	}
}

CCARLIST::~CCARLIST()
{
	while (!carlist.empty())
	{
		COBJECT* temp = carlist.front();
		carlist.pop_front();
		delete temp;
	}
}

void CCARLIST::save(ofstream& fout)
{
	fout.write((char*)&type, sizeof(type));
	fout.write((char*)&dir, sizeof(dir));

	int size = carlist.size();
	fout.write((char*)&size, sizeof(size));

	for (auto i : carlist)
		i->save(fout);
}

void CCARLIST::load(ifstream& fin)
{
	fin.read((char*)&type, sizeof(type));
	fin.read((char*)&dir, sizeof(dir));

	int size;
	fin.read((char*)&size, sizeof(size));
	while (carlist.size() < size)
	{
		float mX, mY;
		fin.read((char*)&mX, sizeof(mX));
		fin.read((char*)&mY, sizeof(mY));

		string t = "1";
		if (dir == TOLEFT)
			t = "0";
		carlist.push_front(new CCAR(Constants::Cartype[type] + t, mX, mY, Constants::speedCar[type], 2 * dir - 1));
	}
}

int CCARLIST::soundType()
{
	return type;
}
