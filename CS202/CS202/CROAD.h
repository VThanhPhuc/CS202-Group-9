#pragma once
#include "Constants.h"
#include "CCARLIST.h"
#include "LoadPic.h"
#include "CANIMALLIST.h"
#include<fstream>
using namespace std;
class CROAD
{
protected:
	friend class CGAME;
	friend class Menu;
	float mX;
	float mY;

	bool playing;

	sf::Texture* texture;
	sf::Sprite out;

private:
	static int NumRoad;

public:

	CROAD(float x, float y);
	CROAD();
	virtual ~CROAD();

	//function
	bool checkoutwindow(sf::RenderWindow& window);
	void  draw(sf::RenderWindow& window);
	void shiftObject(char shift);
	sf::Vector2f getPos();
	void setplaying();

	//get total lane
	static int getNumRoads();

	//virtual
	virtual void drawSubObj(sf::RenderWindow& window) = 0;
	virtual void shiftObj(char shift) = 0;
	virtual void update(sf::RenderWindow& window) = 0;

	virtual deque<COBJECT*>* getObjLi() = 0;

	//save to file

};

