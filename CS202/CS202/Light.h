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
public:
	CLight();
	void update();
	bool geton();
};