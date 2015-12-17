#ifndef __COLLIDER_H__
#define __COLLIDER_H__

#include "Globals.h"

class Module;

enum colliderType{
	PLAYER=1,
	PARTICLE,
	TERRAIN
};

class Collider{
public:
	Collider(SDL_Rect,Module*,colliderType);
	~Collider();
	void flagRelease();
public:
	SDL_Rect collisionBox;
	Module* mod=nullptr;
	bool flag;
	colliderType type;
};
#endif //__COLLIDER_H__