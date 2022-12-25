#include "CGRASS.h"
CGRASS::CGRASS(sf::Vector2f pos) : CROAD()
{
	// main
	mX = pos.x;
	mY = pos.y /*- Constants::HeightRoad*/;
	texture = &LoadPic::GetIns().texture[file];
	out.setTexture(*texture);
	out.setPosition(mX, mY);
}

CGRASS::CGRASS(float index) : CROAD()
{

	// main
	mX = 0;
	mY = index * Constants::HeightRoad - 2 * Constants::Height_HiddenRoad;

	// create texture
	texture = &LoadPic::GetIns().texture[file];
	out.setTexture(*texture);
	out.setPosition(mX, mY);

}

CGRASS::CGRASS(float x, float y) :CROAD(x, y)
{
	// create texture
	texture = &LoadPic::GetIns().texture[file];
	out.setTexture(*texture);
	out.setPosition(mX, mY);

}

CGRASS::~CGRASS()
{
	Animali.~CANIMALLIST();
}

void CGRASS::drawSubObj(sf::RenderWindow& window)
{
	Animali.draw(window);
}

void CGRASS::shiftObj(char shift)
{
	Animali.shiftObject(shift);
}

void CGRASS::update(sf::RenderWindow& window)
{
	Animali.update(mX, mY, window);
}


deque<COBJECT*>* CGRASS::getObjLi()
{
	return Animali.getAniList();
}

bool CGRASS::isCarlane()
{
	return false;
}

void CGRASS::saveLight(ofstream& fout)
{
	bool isLight = false;
	fout.write((char*)&isLight, sizeof(isLight));
}
