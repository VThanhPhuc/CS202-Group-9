#pragma once
#include "CROAD.h"
#include <deque>
#include "COBJECT.h"

class CARLANE : public CROAD
{
private:
	CLight light;
	const string file = "Road";
	CCARLIST carli;
public:
	// Constructor | destructor
	CARLANE(sf::Vector2f pos);
	CARLANE(float index = 1);
	CARLANE(float x, float y, bool traffic, ifstream& fin);
	~CARLANE();

	// other function
	void drawSubObj(sf::RenderWindow& window);
	void shiftObj(char shift,const float&point);
	void update(sf::RenderWindow& window);
	int isCarlane();
	void saveLight(ofstream& fout);
	int soundType();

	deque<COBJECT*>* getObjLi();
};

