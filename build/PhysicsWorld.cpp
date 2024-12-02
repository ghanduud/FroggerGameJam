#include "PhysicsWorld.h"


void PhysicsWorld::addMovingOpject(MovingOpject* particle) {
	this->particles.push_back(particle);
}

void PhysicsWorld::Update(float deltaTime) {
    for (MovingOpject* particle : this->particles) {
        particle->Update(deltaTime);


        for (MovingOpject* otherParticle : this->particles) {
            if (particle == otherParticle) {
                continue;
            }

            if (particle->rectangleCollider.checkCollision(otherParticle->rectangleCollider)) {
                
            }
     

        }
    }
}
