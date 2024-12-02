#include "PhysicsWorld.h"


void PhysicsWorld::addMovingPlatform(MovingPlatform* particle) {
	this->particles.push_back(particle);
}

void PhysicsWorld::Update(float deltaTime) {
    for (MovingPlatform* particle : this->particles) {
        particle->Update(deltaTime);


        for (MovingPlatform* otherParticle : this->particles) {
            if (particle == otherParticle) {
                continue;
            }

            if (particle->rectangleCollider.checkCollision(otherParticle->rectangleCollider)) {
                
            }
     

        }
    }
}
