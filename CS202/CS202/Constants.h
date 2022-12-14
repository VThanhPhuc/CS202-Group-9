#pragma once
#include <iostream>
#include <string>
using namespace std;
const float up = 0.09;
const float maxi = 35;
namespace Constants
{
	//window
	const float Height_screen = 1000;
	const float width_screen = 1500;

	// velocity
	const float ShiftVelocity = 1.1;
	const float VelcocityX = 3.6;

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
	const string Cartype[] = { "car","car3" ,"truck","truck3" ,"pickup", "race" };
	const int NCartype = 6;
	const int Height_Cartype[] = { 64,64,64,64,64,64};
	const float speedCar[] = { 1,1.2, 0.7,0.8,0.85, 2 };
	const string Animaltype[] = { "bird", "dino", "ghost", "cat", "dog", "penguin", "pika" };
	const int Height_AniType[] = { 80,80,80,80,80,80,80 };
	const float speedAni[] = { 1.2,0.7,0.9,1,0.8,0.5,1 };
	// type
	const int car = 1;
	const int animal = 2;

	//Person
	const float width_person = 50;
	const float height_person = 100;
	const int Height_PerImage = 75;
	//number of lights
	const int numLights = 6;
	const string lightname = "light";

	const float Width_hiddenRoad = 1500;
	const float Height_HiddenRoad = 100;

	//save game
	const std::string dataFile = "data.dat";
	const std::string pointFile = "point.dat";

	//sound
	const std::string Soundtype[] = { "car", "car3","truck", "truck3", "pickup", "race",
									"bird", "dino", "ghost", "cat", "dog", "penguin", "pika"};
}
