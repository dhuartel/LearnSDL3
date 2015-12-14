#include "ModuleCollision.h"
#include "Globals.h"
#include "Application.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "Particle.h"
#include "SDL/include/SDL.h"

ModuleCollision::ModuleCollision(){
}

ModuleCollision::~ModuleCollision(){
}

void ModuleCollision::CreateCollider(SDL_Rect box,Module* m){
}

update_status ModuleCollision::PreUpdate(){
	return UPDATE_CONTINUE;
}
update_status ModuleCollision::Update(){
	return UPDATE_CONTINUE;
}