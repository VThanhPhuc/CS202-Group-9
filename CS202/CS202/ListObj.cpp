#include <SFML/Audio.hpp>
#include <iostream>
#include <Windows.h>
#include "Vehicle.h"
#include <conio.h>
#include <mmsystem.h>
#include <cstdlib>
#include <ctime>
#include "Light.h"
#include "CLane.h"
#include <vector>

using namespace std;

CarLane::CarLane(int ty, int num, int y, int sp) {
	type = ty; number = num; yL = y; speed = sp;
	int dis = 1500 / num;
	for (int i = 0; i < num; i++) {
		CCar c(dis * i, y, sp);
		//c.setspr(ty);
		l1.push_back(c);
	}
}
void CarLane::move(CLight l) {
	for (int i = 0; i < number; i++) {
		l1[i].move(l);
	}
}
void CarLane::draw(sf::RenderWindow& window) {
	
	for (int i = 0; i < number; i++) {
		//l1[i].setspr(type);
		l1[i].draw(window,type);
	}
}

AniLane::AniLane(int ty, int num, int y, int sp) {
	type = ty; number = num; yL = y; speed = sp;
	int dis = 1500 / num;
	for (int i = 0; i < num; i++) {
		CBIRD c(dis * i, y, sp);
		//c.setspr(ty);
		l1.push_back(c);
	}
}
void AniLane::move(CLight l) {
	for (int i = 0; i < number; i++) {
		l1[i].move(l);
	}
}
void AniLane::draw(sf::RenderWindow& window) {

	for (int i = 0; i < number; i++) {
		//l1[i].setspr(type);
		l1[i].draw(window, type);
	}
}