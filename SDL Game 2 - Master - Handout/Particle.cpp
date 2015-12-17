#include "Particle.h"
#include "SDL/include/SDL.h"
#include "Application.h"
#include "Globals.h"
#include "ModuleCollision.h"
#include "Module.h"
#include "Collider.h"

Particle::Particle(particle newPart, Module* mod){
	part = newPart;
	creationTime = SDL_GetTicks();
}

Particle::~Particle(){
	part.anim.frames.clear();
}
