#include "LoadPic.h"
void LoadPic::initTexture(string texFileName, bool isplayer)
{
	string file = texFileName + ".png";
	if (!texture[texFileName].loadFromFile(file))
	{
		cout << "Unable to load" << file << endl;
		return;
	}
	texture[texFileName].setSmooth(true);
	cout << file << "load successfully" << endl;
}

LoadPic::LoadPic()
{
	//load road
	initTexture("Pavement_bottom");
	initTexture("river");
	initTexture("Grass");

	//load people
	initTexture("person", 1);

	//load object
	initTexture("car0");
	initTexture("car1");
	initTexture("truck0");
	initTexture("truck1");
	initTexture("bird1");
	initTexture("bird0");
	initTexture("dino1");
	initTexture("dino0");
	initTexture("pickup1");
	initTexture("pickup0");

	//load light
	initTexture("light");
}