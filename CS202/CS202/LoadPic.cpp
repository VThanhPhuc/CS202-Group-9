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

void  LoadPic::initSound(string soundFileName)
{
	string file = soundFileName + ".wav";
	if (!sound[soundFileName].loadFromFile(file))
	{
		cout << "Unable to load" << file << endl;
		return;
	}
	cout << file << "load successfully" << endl;
}

LoadPic::LoadPic()
{
	//load road
	initTexture("Road");
	initTexture("river");
	initTexture("Grass");
	initTexture("Free");
	//load people
	initTexture("boyside2", 1);
	initTexture("boyside3", 1);
	initTexture("boyside0", 1);
	initTexture("boyside1", 1);

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
	initTexture("race1");
	initTexture("race0");
	initTexture("ghost1");
	initTexture("ghost0");
	initTexture("truck30");
	initTexture("truck31");
	initTexture("car30");
	initTexture("car31");
	initTexture("cat0");
	initTexture("cat1");
	initTexture("dog0");
	initTexture("dog1");
	initTexture("penguin0");
	initTexture("penguin1");
	initTexture("pika0");
	initTexture("pika1");

	//load light
	initTexture("light");

	//load sound
	initSound("bird");
	initSound("dino");
	initSound("car");
	initSound("truck");
	initSound("pickup");
	initSound("race");
	initSound("bird");
	initSound("dino");
	initSound("ingame");
	initSound("step");
	initSound("death");
	initSound("ghost");
	initSound("truck3");
	initSound("menuS");
	initSound("car3");
	initSound("cat");
	initSound("dog");
	initSound("penguin");
	initSound("pika");
	initSound("conflictsound");
}
