#pragma once
#include "CROAD.h"
class CFREELANE : public CROAD
{
private:
	const string file = "Free";

public:
	// Constructor | destructor
	CFREELANE(sf::Vector2f pos);
	CFREELANE(float index = 1);
	CFREELANE(float x, float y, ifstream& fin);
	~CFREELANE() {};

	// other function
	void drawSubObj(sf::RenderWindow& window) {};
	void shiftObj(char shift,const float& point) {};
	void update(sf::RenderWindow& window) {};
	int isCarlane();
	void saveLight(ofstream& fout);
	int soundType();

	deque<COBJECT*>* getObjLi();
};
