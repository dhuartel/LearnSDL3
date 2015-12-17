#include "Globals.h"
#include "Application.h"
#include "ModuleParticle.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "Particle.h"
#include "SDL/include/SDL.h"
#include "ModuleCollision.h"
#include "Collider.h"


ModuleParticle::ModuleParticle(){
}

ModuleParticle::~ModuleParticle(){
}

void ModuleParticle::CreateParticle(particle newParticle){
	setOfParticles.push_back(new Particle(newParticle, this));
	SDL_Rect aux;
	aux.x = newParticle.position.x*SCREEN_SIZE;
	aux.y = newParticle.position.y*SCREEN_SIZE;
	aux.w = newParticle.anim.frames[0].w * SCREEN_SIZE;
	aux.h = newParticle.anim.frames[0].h * SCREEN_SIZE;
	collidersOfParticles.push_back(App->collisions->CreateCollider(aux, this,PARTICLE));
}

update_status ModuleParticle::PreUpdate(){
	list<Particle*>::iterator it = setOfParticles.begin();
	list<Collider*>::iterator it2 = collidersOfParticles.begin();
	Uint32 currentTime = SDL_GetTicks();
	while ( it != setOfParticles.end()){
		if (currentTime > (*it)->creationTime + 1000){
			RELEASE(*it);
			it = setOfParticles.erase(it);
			(*it2)->flagRelease();
			it2 = collidersOfParticles.erase(it2);
		}
		else{
			++it;
			++it2;
		}
	}
	return UPDATE_CONTINUE;
}
update_status ModuleParticle::Update(){
	list<Particle*>::iterator it;
	list<Collider*>::iterator it2=collidersOfParticles.begin();
	for (it = setOfParticles.begin(), it2 = collidersOfParticles.begin(); it != setOfParticles.end(); ++it,++it2){
		App->renderer->Blit((*it)->part.tex, (*it)->part.position.x, (*it)->part.position.y, &((*it)->part.anim.GetCurrentFrame()), 0.75f);
		(*it)->part.position.x += (*it)->part.speed.x;
		(*it)->part.position.y += (*it)->part.speed.y;
		(*it2)->collisionBox.x = (*it)->part.position.x*SCREEN_SIZE;
		(*it2)->collisionBox.y = (*it)->part.position.y*SCREEN_SIZE;
		(*it2)->collisionBox.w = (*it)->part.anim.GetCurrentFrame().w*SCREEN_SIZE;
		(*it2)->collisionBox.h = (*it)->part.anim.GetCurrentFrame().h*SCREEN_SIZE;
	}
	return UPDATE_CONTINUE;
}

void ModuleParticle::OnCollision(Collider* a, Collider* b){
	list<Collider*>::iterator it = collidersOfParticles.begin();
	list<Particle*>::iterator it2 = setOfParticles.begin();
	if (a->type == PARTICLE && b->type == PARTICLE){

	}
	else{
		if (a->type == PARTICLE){
			while (*it != a && it != collidersOfParticles.end()){
				++it;
			}
			advance(it2, distance(collidersOfParticles.begin(), it));
			(*it)->flagRelease();
			it = collidersOfParticles.erase(it);
			RELEASE(*it2);
			it2 = setOfParticles.erase(it2);
		}
		if (b->type == PARTICLE){
			while (*it != b){
				++it;
			}
			advance(it2, distance(collidersOfParticles.begin(), it));
			(*it)->flagRelease();
			it = collidersOfParticles.erase(it);
			RELEASE(*it2);
			it2 = setOfParticles.erase(it2);
		}
	}
	LOG("AAAAAAAA");
}