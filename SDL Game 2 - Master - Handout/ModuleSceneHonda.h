#ifndef __MODULESCENEHONDA_H__
#define __MODULESCENEHONDA_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include <vector>

struct SDL_Texture;

class ModuleSceneHonda : public Module
{
public:
	ModuleSceneHonda(bool start_enabled = true);
	~ModuleSceneHonda();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* graphics = nullptr;
	SDL_Rect ground;
	SDL_Rect background;
	SDL_Rect pool;
	SDL_Rect wall;
	//Animation flag;
	//Animation girl;
	//bool shipmov = false;
	//int shippixmov = 0;
};

#endif // __MODULESCENEHONDA_H__