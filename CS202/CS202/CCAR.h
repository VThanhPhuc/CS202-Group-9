#pragma once
#include "COBJECT.h"
class CCAR : public COBJECT
{
private:

public:
	int type();

	CCAR(string FileTextureName, float x, float y, int speed, int direction);

	void move(float x, float y, float frac = 1);
};
