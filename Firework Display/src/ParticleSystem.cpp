//referenced from the particle example taught in class
#include "ParticleSystem.hpp"

ParticleSystem::ParticleSystem()
{
    pos = glm::vec2(0,0);       // default value
}

ParticleSystem::ParticleSystem(glm::vec2 _pos)
{
    pos = _pos;                 // assigned value
}

void ParticleSystem::applyForce(glm::vec2 force)
{
    // add the force to all particles
    
    for (int i=0; i<particles.size(); i++)
    {
        particles[i].applyForce(force);
    }
}

void ParticleSystem::update(int numNewParticles, int maxParticles)
{
    
    // create new particles:
    if (increase){
        for (int i=0; i<numNewParticles; i++)
        {
            glm::vec2 vel   = glm::vec2(ofRandom(-3,3), ofRandom(-3,-5));   // move up
            float mass      = ofRandom(.01, 1);
            Particle particle = Particle(pos,vel,mass);     // start at system's position
            particles.push_back(particle);
        }
    }
    
    // update particles:
    
    for (int i=0; i<particles.size(); i++)
    {
        particles[i].update();
    }
    
    // erase old particles:
    
    while (particles.size() > maxParticles)     // keep the number of particles under a limit
    {
        particles.erase(particles.begin());
        increase = false;
    }
    
}

void ParticleSystem::draw()
{
    for (int i=0; i<particles.size(); i++)
    {
        particles[i].draw();
    }
}

