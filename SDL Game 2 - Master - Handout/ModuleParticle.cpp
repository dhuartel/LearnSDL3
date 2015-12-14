#include "Globals.h"
#include "Application.h"
#include "ModuleParticle.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "Particle.h"
#include "SDL/include/SDL.h"

ModuleParticle::ModuleParticle(){
}

ModuleParticle::~ModuleParticle(){
}

void ModuleParticle::CreateParticle(particle newParticle){
	setOfParticles.insert(setOfParticles.end(),new Particle(newParticle));
}

update_status ModuleParticle::PreUpdate(){
	list<Particle*>::iterator it;
	Uint32 currentTime = SDL_GetTicks();
	it = setOfParticles.begin();
	while ( it != setOfParticles.end()){
		if (currentTime > (*it)->creationTime+1000){
			RELEASE(*it);
			it=setOfParticles.erase(it);
		}
		else{
			++it;
		}
	}
	return UPDATE_CONTINUE;
}
update_status ModuleParticle::Update(){
	list<Particle*>::iterator it;
	for (it = setOfParticles.begin(); it != setOfParticles.end(); ++it){
		App->renderer->Blit((*it)->part.tex, (*it)->part.position.x, (*it)->part.position.y, &((*it)->part.anim.GetCurrentFrame()), 0.75f);
		(*it)->part.position.x += (*it)->part.speed.x;
		(*it)->part.position.y += (*it)->part.speed.y;
	}
	return UPDATE_CONTINUE;
}