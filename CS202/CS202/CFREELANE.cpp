#include "CFREELANE.h"
CFREELANE::CFREELANE(sf::Vector2f pos) : CROAD()
{
	// main
	mX = pos.x;
	mY = pos.y /*- Constants::HeightRoad*/;
	texture = &LoadPic::GetIns().texture[file];
	out.setTexture(*texture);
	out.setPosition(mX, mY);
}

CFREELANE::CFREELANE(float index) : CROAD()
{

	// main
	mX = 0;
	mY = index * Constants::HeightRoad - 2 * Constants::Height_HiddenRoad;

	// create texture
	texture = &LoadPic::GetIns().texture[file];
	out.setTexture(*texture);
	out.setPosition(mX, mY);

}

CFREELANE::CFREELANE(float x, float y, ifstream& fin) :CROAD(x, y)
{
	// create texture
	texture = &LoadPic::GetIns().texture[file];
	out.setTexture(*texture);
	out.setPosition(mX, mY);


}


deque<COBJECT*>* CFREELANE::getObjLi()
{
	return NULL;
}

int CFREELANE::isCarlane()
{
	return 3;
}

void CFREELANE::saveLight(ofstream& fout)
{
	bool isLight = false;
	fout.write((char*)&isLight, sizeof(isLight));
}

int CFREELANE::soundType()
{
	return -1;
}

