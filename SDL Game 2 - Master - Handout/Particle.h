#ifndef __PARTICLE_H__
#define __PARTICLE_H__
#include "Globals.h"

class Module;
class Collider;

class Particle{
public:
	particle part;
	Uint32 creationTime;

	Particle(particle,Module*);
	~Particle();
	Collider* myCollider;
};

#endif __PARTICLE_H__