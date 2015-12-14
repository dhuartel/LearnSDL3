#ifndef __MODULECOLLISION_H__
#define __MODULECOLLISION_H__

#include "Module.h"
#include "Globals.h"

struct SDL_Texture;
class Collider;

class ModuleCollision : public Module
{
public:
	ModuleCollision();
	~ModuleCollision();

	update_status PreUpdate();
	update_status Update();
	void CreateCollider(SDL_Rect,Module*);


};

#endif // __MODULECOLLISION_H__