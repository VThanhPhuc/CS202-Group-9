#include "CROAD.h"

CROAD::CROAD(float x, float y)
{
	mX = x;
	mY = y;
	NumRoad += 1;
	playing = false;
}

CROAD::CROAD()
{
	NumRoad += 1;
	playing = false;
}


CROAD::~CROAD()
{
	--NumRoad;
}


bool CROAD::checkoutwindow(sf::RenderWindow& window)
{
	return out.getPosition().y >= Constants::Height_screen;

}

void CROAD::draw(sf::RenderWindow& window)
{
	window.draw(out);
}

void CROAD::shiftObject(char shift,const float& point)
{
	float go;
	go = up * min(point, float(30));
	out.move(0, Constants::ShiftVelocity+go);


	/*mX = out.getPosition().x;
	mY = out.getPosition().y;*/
	shiftObj(shift,point);
	//out.setPosition(mX, mY);
}

void CROAD::setplaying()
{
	playing = !playing;
}

int CROAD::getNumRoads()
{
	return NumRoad;
}

sf::Vector2f CROAD::getPos()
{
	return sf::Vector2f(out.getPosition().x, out.getPosition().y - 100);
	/*return sf::Vector2f(mX, mY);*/
}

void CROAD::save(ofstream& fout)
{
	fout.write((char*)&out.getPosition().x, sizeof(out.getPosition().x));
	fout.write((char*)&out.getPosition().y, sizeof(out.getPosition().y));

	int isCarlane = this->isCarlane();
	fout.write((char*)&isCarlane, sizeof(isCarlane));

	saveLight(fout);
}
