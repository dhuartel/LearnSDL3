#ifndef __MODULEPARTICLE_H__
#define __MODULEPARTICLE_H__

#include "Module.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleParticle : public Module
{
public:
	ModuleParticle();
	~ModuleParticle();
	list<particle> setOfParticles;
	particle* ahora;

	//bool Start();
	update_status Update();
	//bool CleanUp();
	void CreateParticle(particle);

public:

};

#endif // __MODULEPARTICLE_H__