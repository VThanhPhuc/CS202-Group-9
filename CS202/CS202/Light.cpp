#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <Windows.h>
#include "Light.h"

using namespace std;

CLight::CLight() {
	number = 10;
	on = true;
}
void CLight::update() {
	number--;
	if (number < 0) {
		on = !on;
		number = 10;
	}
}
bool CLight::geton() {
	return on;
}