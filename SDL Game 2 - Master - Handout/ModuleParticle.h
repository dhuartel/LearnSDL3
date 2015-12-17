#ifndef __MODULEPARTICLE_H__
#define __MODULEPARTICLE_H__

#include "Module.h"
#include "Globals.h"

struct SDL_Texture;
class Particle;
class Collider;

class ModuleParticle : public Module
{
public:
	ModuleParticle();
	~ModuleParticle();
	list<Particle*> setOfParticles;
	list<Collider*> collidersOfParticles;

	//bool Start();
	update_status PreUpdate();
	update_status Update();
	//bool CleanUp();
	void CreateParticle(particle);
	void OnCollision(Collider*,Collider*);

};

#endif // __MODULEPARTICLE_H__