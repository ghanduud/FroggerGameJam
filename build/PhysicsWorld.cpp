#include "PhysicsWorld.h"


void PhysicsWorld::addParticle(MovingOpject* particle) {
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
                particle->velocity = sf::Vector2f(-(particle->velocity.x), -(particle->velocity.y));
                otherParticle->velocity = sf::Vector2f(-(otherParticle->velocity.x), -(otherParticle->velocity.y));
            }
     

        }
    }
}
