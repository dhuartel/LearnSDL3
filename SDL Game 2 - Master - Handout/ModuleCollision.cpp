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
	//= setOfColliders.begin();
	//advance(it2, 1);
	for (it = setOfColliders.begin(); it != setOfColliders.end(); it++){
		it2 = it;
		advance(it2, 1);
		for (it2; it2 != setOfColliders.end(); it2++){
			if ((((*it)->collisionBox.x + (*it)->collisionBox.w) > (*it2)->collisionBox.x) && ((*it)->collisionBox.x < ((*it2)->collisionBox.x + (*it2)->collisionBox.w))){
				if ((((*it)->collisionBox.y + (*it)->collisionBox.h) >(*it2)->collisionBox.y) && ((*it)->collisionBox.y < ((*it2)->collisionBox.y + (*it2)->collisionBox.h))){
					(*it)->mod->OnCollision(*it,*it2);
					(*it2)->mod->OnCollision(*it,*it2);
				}
			}
		}
	}
	//LOG("SAN CHOCAOOOO");
	for (it = setOfColliders.begin(); it != setOfColliders.end(); ++it){
		SDL_SetRenderDrawColor(App->renderer->renderer, 255, 0, 0, 100);
		SDL_RenderDrawRect(App->renderer->renderer, &(*it)->collisionBox);
		SDL_RenderFillRect(App->renderer->renderer, &(*it)->collisionBox);
	}
	return UPDATE_CONTINUE;
}