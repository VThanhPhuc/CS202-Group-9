#pragma once
#include "CROAD.h"
class CGRASS : public CROAD 
{
private:
	const string file = "Grass";
	CANIMALLIST Animali;

public:
	// Constructor | destructor
	CGRASS(sf::Vector2f pos);
	CGRASS(float index = 1);
	CGRASS(float x, float y, ifstream& fin);
	~CGRASS();

	// other function
	void drawSubObj(sf::RenderWindow& window);
	void shiftObj(char shift,const float& point);
	void update(sf::RenderWindow& window);
	int isCarlane();
	void saveLight(ofstream& fout);
	int soundType();

	deque<COBJECT*>* getObjLi();
};

