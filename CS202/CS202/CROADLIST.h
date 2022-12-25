#pragma once
#include <deque>
#include "CARLANE.h"
#include "People.h"
#include "CGRASS.h"
enum RoadType { LANE, GRASS, LAST };

class CROADLIST
{
private:
	friend class CGAME;
	friend class Menu;
	deque<CROAD*> roadList;

	CPEOPLE* player;

	float mX;
	float mY;
	float mY_origin;

public:
	CROADLIST(CPEOPLE* player);
	~CROADLIST();
	void initRoad();

	void shiftObj(char shift);
	void draw(sf::RenderWindow& window);
	void update(sf::RenderWindow& window);
	CROAD* createRoad(sf::Vector2f pos);
	CROAD* createRoad(float index = 1);

	//sound


	// save to file | load from file
	void save(ofstream& fout);
	void load(ifstream& fin);
};
