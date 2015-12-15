#ifndef __MODULECOLLISION_H__
#define __MODULECOLLISION_H__

#include "Module.h"
#include "Globals.h"
#include <list>

struct SDL_Texture;
class Collider;

class ModuleCollision : public Module
{
public:
	ModuleCollision();
	~ModuleCollision();
	list<Collider*> setOfColliders;

	update_status PreUpdate();
	update_status Update();
	void CreateCollider(SDL_Rect, Module*);


};

#endif // __MODULECOLLISION_H__