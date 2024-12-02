#include "PhysicsWorld.h"


void PhysicsWorld::addParticle(Particle* particle) {
	this->particles.push_back(particle);
}

void PhysicsWorld::Update(float deltaTime) {
    for (Particle* particle : this->particles) {
        particle->Update(deltaTime);


        for (Particle* otherParticle : this->particles) {
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
