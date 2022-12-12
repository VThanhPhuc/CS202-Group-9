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