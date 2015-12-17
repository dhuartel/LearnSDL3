#ifndef __MODULEPLAYER_H__
#define __MODULEPLAYER_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "Point.h"

struct SDL_Texture;
class Collider;

class ModulePlayer : public Module
{
public:
	ModulePlayer(bool start_enabled = true,int player=1);
	~ModulePlayer();

	bool Start();
	update_status PreUpdate();
	update_status Update();
	bool CleanUp();
	void OnCollision(Collider*,Collider*);

public:

	SDL_Texture* graphics = nullptr;
	Animation idle;
	Animation backward;
	Animation forward;
	fPoint position;
	Collider* myCollider;
	bool colliding=false;
};

#endif // __MODULEPLAYER_H__