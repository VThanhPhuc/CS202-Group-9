#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <Windows.h>

using namespace std;

class CLight {
private:
	int number;
	bool on;
	bool avail;//1: car, 0: animal
public:
	CLight(bool a);
	void update();
	bool geton();
	bool getstatus();
};