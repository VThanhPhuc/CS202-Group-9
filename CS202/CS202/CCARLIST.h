#pragma once
#include "Light.h"
#include "CCAR.h"
#include <deque>
#include <random>
#include<fstream>
enum CARTYPE {car, truck, truck3 ,pickup, race, LASTTYPE }; // LASTTYPE is to determine the number of cartypes.

enum CARDIR { TOLEFT, TORIGHT, LASTDIR }; // LASTDIR is to determine the number of CARDIR

class CCARLIST {
private:
	deque<COBJECT*> carlist;
	CARTYPE type;
	CARDIR dir;
	bool playing;
public:
	CCARLIST();
	void initGame(float mX, float mY);
	void shiftObject(char shift,const float&point);
	void draw(sf::RenderWindow& window);
	void update(float mX, float mY, sf::RenderWindow& window, CLight& l);

	CCAR* createCar(float mX, float mY);

	deque<COBJECT*>* getCarList();
	int direction();
	~CCARLIST();

	void save(ofstream& fout);
	void load(ifstream& fin);

	int soundType();
};
