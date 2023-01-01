#include "CCAR.h"

int CCAR::type()
{
	return Constants::car;
}

CCAR::CCAR(string FileTextureName, float x, float y, int speed, int direction) : COBJECT(x, y, direction)
{
	this->speed = speed;

	//sf::Texture tex;

	texture = &LoadPic::GetIns().texture[FileTextureName];
	out.setTexture(*texture);
	out.setPosition(mX, mY);
}

void CCAR::move(float x, float y, float frac)
{
	COBJECT::move(x, y, frac);
}