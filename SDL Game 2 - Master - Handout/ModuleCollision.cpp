#include "ModuleCollision.h"
#include "Collider.h"
#include "SDL\include\SDL.h"
#include "Application.h"
#include "ModuleWindow.h"
#include "ModuleRender.h"

ModuleCollision::ModuleCollision(){}

ModuleCollision::~ModuleCollision(){}

Collider* ModuleCollision::CreateCollider(SDL_Rect box,Module* m,colliderType type){
	Collider* a = new Collider(box, m,type);
	setOfColliders.push_back(a);
	return a;
}

update_status ModuleCollision::PreUpdate(){
	list<Collider*>::iterator it = setOfColliders.begin();
	while (it!=setOfColliders.end()){
		if ((*it)->flag){
			RELEASE(*it);
			it = setOfColliders.erase(it);
		}
		else{
			++it;
		}
	}
	return UPDATE_CONTINUE;
}

update_status ModuleCollision::Update(){
	list<Collider*>::iterator it;
	list<Collider*>::iterator it2;
	for (it = setOfColliders.begin(); it != setOfColliders.end(); it++){
		it2 = it;
		advance(it2, 1);
		for (it2; it2 != setOfColliders.end(); it2++){
			if (DetectCollision((*it)->collisionBox, (*it2)->collisionBox)){
				if ((*it)->status == OUT){
					LOG("Entering");
					(*it)->mod->OnCollision(*it, *it2);
					(*it2)->mod->OnCollision(*it, *it2);
				}
			}
		}
	}
	//LOG("SAN CHOCAOOOO");
	for (it = setOfColliders.begin(); it != setOfColliders.end(); ++it){
		SDL_SetRenderDrawColor(App->renderer->renderer, 255, 0, 0, 100);
		App->renderer->DrawRect((*it)->collisionBox);
	}
	return UPDATE_CONTINUE;
}

bool ModuleCollision::DetectCollision(SDL_Rect a, SDL_Rect b){
	return SDL_HasIntersection(&a, &b);
}