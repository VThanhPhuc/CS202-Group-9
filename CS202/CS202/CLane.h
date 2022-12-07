#pragma once
#include <vector>
#include "Vehicle.h"
#include "Light.h"

class CarLane {
private:
	vector<CCar> l1;
	int type;//1: car, 2 truck
	int number;
	int yL;
	int speed;
public:
	CarLane(int ty,int num, int y,int sp);
	void move(CLight l);
	void draw(sf::RenderWindow& window);
};
