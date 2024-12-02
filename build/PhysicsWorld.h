#pragma once
#include "MovingOpject.h"
#include <list>

using namespace std;

class PhysicsWorld
{
private:
	list<MovingOpject*> particles;
public:
	void addMovingOpject(MovingOpject* particle);
	void Update(float deltaTime);;
};

