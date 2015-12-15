#ifndef __COLLIDER_H__
#define __COLLIDER_H__

#include "Globals.h"

class Module;

class Collider{
public:
	Collider(SDL_Rect,Module*);
	~Collider();
public:
	SDL_Rect collisionBox;
	Module* mod=nullptr;
};
#endif //__COLLIDER_H__