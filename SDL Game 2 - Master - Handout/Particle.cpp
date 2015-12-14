#include "Particle.h"
#include "SDL/include/SDL.h"

Particle::Particle(particle newPart){
	part = newPart;
	creationTime = SDL_GetTicks();
}

Particle::~Particle(){
	part.anim.frames.clear();
}