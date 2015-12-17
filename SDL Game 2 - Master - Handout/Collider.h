#ifndef __COLLIDER_H__
#define __COLLIDER_H__

#include "Globals.h"

class Module;

enum colliderType{
	PLAYER=1,
	PARTICLE,
	TERRAIN
};

enum collidingStatus{
	OUT=1,
	ENTERING,
	IN,
	EXITING
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
	collidingStatus status = OUT;
};
#endif //__COLLIDER_H__