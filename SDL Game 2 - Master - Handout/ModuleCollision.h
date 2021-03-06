#ifndef __MODULECOLLISION_H__
#define __MODULECOLLISION_H__

#include "Module.h"
#include "Globals.h"
#include <list>
#include "Collider.h"

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
	Collider* CreateCollider(SDL_Rect, Module*, colliderType);
	bool DetectCollision(SDL_Rect, SDL_Rect);

};

#endif // __MODULECOLLISION_H__