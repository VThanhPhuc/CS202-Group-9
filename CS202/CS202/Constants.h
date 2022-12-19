#pragma once
#include <iostream>
#include <string>
using namespace std;

namespace Constants
{
	//window
	const float Height_screen = 1000;
	const float width_screen = 1500;

	// velocity
	const float ShiftVelocity = 100;
	const float VelcocityX = 1;

	const int widthVehicle = 80;
	const int heightVehicle = 80;


	// Lane
	const int MAX_ROAD = 12;
	const float WidthRoad = 1500;
	const float HeightRoad = 100;

	//Car
	const int NCar = 30; // number of car
	const string Cartype[] = { "car1","car","truck","truck1" };

	// type
	const int car = 1;
	const int animal = 2;

	//Person
	const float width_person = 50;
	const float height_person = 100;

	//number of lights
	const int numLights = 6;
	const string lightname = "light";

	const float Width_hiddenRoad = 1500;
	const float Height_HiddenRoad = 100;
}