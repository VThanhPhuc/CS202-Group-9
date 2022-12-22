#pragma once
#include "COBJECT.h"
class CANIMAL : public COBJECT
{
private:

public:
	int type();

	CANIMAL(string FileTextureName, float x, float y, int speed, int direction);

	void move(float x, float y, float frac = 1);
};
