#pragma once
#include "Light.h"
#include "CANIMAL.h"
#include <deque>
#include <random>
enum ANITYPE {bird, dino, LASTTY }; 

enum ANIDIR { TLEFT, TRIGHT, LASTDI };

class CANIMALLIST
{
private:
	deque<COBJECT*> Anlist;
	ANITYPE type;
	ANIDIR dir;
	bool playing;
public:
	CANIMALLIST();
	void initGame(float mX, float mY);
	void shiftObject(char shift);
	void draw(sf::RenderWindow& window);
	void update(float mX, float mY, sf::RenderWindow& window);

	CANIMAL* createAnimal(float mX, float mY);

	deque<COBJECT*>* getAniList();
	int direction();
	~CANIMALLIST();
};
