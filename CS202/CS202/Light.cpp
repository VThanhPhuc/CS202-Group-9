#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <Windows.h>
#include "Light.h"

using namespace std;
CLight::CLight()
{
	traffic = false;
}
CLight::CLight(float x, float y)
{
	mX = x + 10;
	mY = y + 50;
	traffic = true;
	diff = rand() % 6 - 1;

	texture = &LoadPic::GetIns().texture[Constants::lightname];
	out.setTexture(*texture);
	out.setOrigin(0, height);
	out.setPosition(mX, mY);

	green();
}
int CLight::statusLight()
{
	return status;
}
void CLight::red()
{
	status = 0;
	out.setTextureRect(sf::IntRect(width * status, 0, width, height));
	clo.restart();
}
void CLight::green()
{
	status = 2;
	out.setTextureRect(sf::IntRect(width * status, 0, width, height));
	clo.restart();
}
void CLight::yellow()
{
	status = 1;
	out.setTextureRect(sf::IntRect(width * status, 0, width, height));
	clo.restart();
}
void CLight::update(sf::RenderWindow& window)
{

	switch (status)
	{
	case 0:
		if (clo.getElapsedTime().asSeconds() >= 4 + diff) green();
		break;
	case 1:
		if (clo.getElapsedTime().asSeconds() >= 3 + diff) red();
		break;
	case 2:
		if (clo.getElapsedTime().asSeconds() >= 10 + diff) yellow();
		break;
	default:
		break;
	}
}
void CLight::draw(sf::RenderWindow& window)
{
	window.draw(out);
}
void CLight::shiftObject(char shift,const float& point)
{
	float go;
	go = up * min(point, float(30));
	out.move(0, Constants::ShiftVelocity+go);
	mX = out.getPosition().x;
	mY = out.getPosition().y;
}

bool CLight::Traffic()
{
	return traffic;
}
