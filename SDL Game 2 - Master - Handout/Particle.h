#ifndef __PARTICLE_H__
#define __PARTICLE_H__
#include "Globals.h"

class Particle{
public:
	particle part;
	Uint32 creationTime;

	Particle(particle);
	~Particle();

};

#endif __PARTICLE_H__