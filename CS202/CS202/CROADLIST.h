#pragma once
#include <deque>
#include "CARLANE.h"
#include "People.h"
#include "CGRASS.h"
#include "CFREELANE.h"
enum RoadType { LANE, GRASS,FREE ,LAST };

class CROADLIST
{
private:
	friend class Menu;

	deque<CROAD*> roadList;
	sf::Sound mySound;
	bool soundOn;

	CPEOPLE* player;

	float mX;
	float mY;
	float mY_origin;

public:
	CROADLIST(CPEOPLE* player, bool soundOn);
	~CROADLIST();
	void initRoad();

	void shiftObj(char shift,const float& point);
	void draw(sf::RenderWindow& window);
	void update(sf::RenderWindow& window);
	CROAD* createRoad(sf::Vector2f pos);
	CROAD* createRoad(float index = 1);

	//sound
	void turnSound();
	void playSound(CROAD& it);

	// save to file | load from file
	void save(ofstream& fout);
	void load(ifstream& fin);
};
