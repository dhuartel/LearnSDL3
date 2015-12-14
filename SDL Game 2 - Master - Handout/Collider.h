#ifndef __COLLIDER_H__
#define __COLLIDER_H__

#include "Globals.h"

class module;

class Collider{
public:
	Collider(SDL_Rect,module*);
	~Collider();
public:
	SDL_Rect collisionBox;
	module* mod=nullptr;
};
#endif //__COLLIDER_H__