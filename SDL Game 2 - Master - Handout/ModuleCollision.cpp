#include "ModuleCollision.h"
#include "Collider.h"
#include "SDL\include\SDL.h"
#include "Application.h"
#include "ModuleWindow.h"
#include "ModuleRender.h"

ModuleCollision::ModuleCollision(){}

ModuleCollision::~ModuleCollision(){}

void ModuleCollision::CreateCollider(SDL_Rect box,Module* m){
	setOfColliders.push_back(new Collider(box, m));
}

update_status ModuleCollision::PreUpdate(){
	return UPDATE_CONTINUE;
}
update_status ModuleCollision::Update(){
	list<Collider*>::iterator it;
	for (it = setOfColliders.begin(); it != setOfColliders.end(); ++it){
		SDL_SetRenderDrawColor(App->renderer->renderer, 255, 0, 0, 100);
		SDL_RenderDrawRect(App->renderer->renderer, &(*it)->collisionBox);
		SDL_RenderFillRect(App->renderer->renderer, &(*it)->collisionBox);
	}
	return UPDATE_CONTINUE;
}