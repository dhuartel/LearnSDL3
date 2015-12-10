#include "Globals.h"
#include "Application.h"
#include "ModuleParticle.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "SDL/include/SDL.h"

ModuleParticle::ModuleParticle(){
}

void ModuleParticle::CreateParticle(particle newParticle){
	setOfParticles.insert(setOfParticles.end(),newParticle);
	//ahora = newParticle;
	//App->renderer->Blit(ahora->tex, ahora->position.x , ahora->position.y /*- (forward.GetCurrentFrame()).h*/, &(ahora->anim.GetCurrentFrame()), 0.75f);
}

update_status ModuleParticle::Update(){
	list<particle>::iterator it;
	for (it = setOfParticles.begin(); it != setOfParticles.end(); ++it){
		App->renderer->Blit(it->tex, it->position.x, it->position.y, &(it->anim.GetCurrentFrame()), 0.75f);
		it->position.x += it->speed.x;
		it->position.y += it->speed.y;
	}
	return UPDATE_CONTINUE;
}