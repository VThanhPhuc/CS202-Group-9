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
	const float ShiftVelocity = 1.2;
	const float VelcocityX = 3.3;

	const int widthVehicle = 100;
	const int heightVehicle = 100;

	const int widthAnimal = 100;
	const int heightAnimal = 100;

	// Lane
	const int MAX_ROAD = 12;
	const float WidthRoad = 1500;
	const float HeightRoad = 100;

	//Car
	const int NCar = 25; // number of cars
	const int NAnimal = 25; //number of animals
	const string Cartype[] = { "car", "truck", "pickup", "race" };
	const float speedCar[] = { 1, 0.7, 0.85, 2 };
	const string Animaltype[] = {"bird", "dino" };
	const float speedAni[] = { 1.2,0.7 };
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

	//save game
	const std::string dataFile = "data.dat";

	//sound
	const std::string Soundtype[] = { "car", "truck", "pickup", "race", "bird", "dino" };
}