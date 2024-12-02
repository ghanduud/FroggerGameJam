#pragma once
#include "MovingPlatform.h"
#include <list>

using namespace std;

class Game
{
private:
	list<MovingPlatform*> particles;
public:
	void addMovingPlatform(MovingPlatform* particle);
	void Update(float deltaTime);;
};

