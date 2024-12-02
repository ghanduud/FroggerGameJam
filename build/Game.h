#pragma once
#include "MovingPlatform.h"
#include <list>

using namespace std;

class PhysicsWorld
{
private:
	list<MovingPlatform*> particles;
public:
	void addMovingPlatform(MovingPlatform* particle);
	void Update(float deltaTime);;
};

