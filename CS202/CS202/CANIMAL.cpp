#include "CANIMAL.h"
int CANIMAL::type()
{
	return Constants::animal;
}

CANIMAL::CANIMAL(string FileTextureName, float x, float y, int speed, int direction) : COBJECT(x, y, direction)
{
	this->speed = speed;

	//sf::Texture tex;

	texture = &LoadPic::GetIns().texture[FileTextureName];
	out.setTexture(*texture);
	out.setPosition(mX, mY);
}

void CANIMAL::move(float x, float y, float frac)
{
	COBJECT::move(x, y, frac);