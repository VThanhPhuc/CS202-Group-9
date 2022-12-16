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

	//load people
	initTexture("person", 1);

	//load object
	initTexture("car");
	initTexture("car1");
	initTexture("truck");
	initTexture("truck1");

	//load light
	initTexture("light");
}