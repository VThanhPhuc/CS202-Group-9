#pragma once
#include "CROAD.h"
#include <deque>
#include "COBJECT.h"

class CARLANE : public CROAD
{
private:
	CLight light;
	const string file = "Pavement_bottom";
	CCARLIST carli;

public:
	// Constructor | destructor
	CARLANE(sf::Vector2f pos);
	CARLANE(float index = 1);
	CARLANE(float x, float y, bool traffic);
	~CARLANE();

	// other function
	void drawSubObj(sf::RenderWindow& window);
	void shiftObj(char shift);
	void update(sf::RenderWindow& window);
	bool isCarlane();
	void saveLight(ofstream& fout);

	deque<COBJECT*>* getObjLi();

	//sound

	//save to file

};

