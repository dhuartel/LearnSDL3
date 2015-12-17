#include "Globals.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "ModuleParticle.h"
#include "SDL/include/SDL.h"
#include "ModuleCollision.h"
#include "Collider.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA
ModulePlayer::ModulePlayer(bool start_enabled,int player) : Module(start_enabled)
{
	if (player == 1){
		position.x = 100;
		position.y = 216;
	}
	if (player == 2){
		position.x = 300;
		position.y = 216;
	}

	// idle animation (arcade sprite sheet)
	idle.frames.push_back({7, 14, 60, 90});
	idle.frames.push_back({95, 15, 60, 89});
	idle.frames.push_back({184, 14, 60, 90});
	idle.frames.push_back({276, 11, 60, 93});
	idle.frames.push_back({366, 12, 60, 92});
	idle.speed = 0.1f;
	
	// walk backward animation (arcade sprite sheet)
	backward.frames.push_back({542, 131, 61, 87});
	backward.frames.push_back({628, 129, 59, 90});
	backward.frames.push_back({713, 128, 57, 90});
	backward.frames.push_back({797, 127, 57, 90});
	backward.frames.push_back({883, 128, 58, 91});
	backward.frames.push_back({974, 129, 57, 89});
	backward.speed = 0.1f;

	// TODO 8: setup the walk forward animation from ryu4.png
	forward.frames.push_back({ 9, 136, 53, 83 });
	forward.frames.push_back({ 78, 131, 61, 88 });
	forward.frames.push_back({ 162, 128, 65, 92 });
	forward.frames.push_back({ 259, 128, 64, 91 });
	forward.frames.push_back({ 352, 128, 54, 92 });
	forward.frames.push_back({ 432, 131, 51, 90 });
	forward.speed = 0.1f;
}

ModulePlayer::~ModulePlayer()
{
	// Homework : check for memory leaks
	RELEASE(myCollider);
}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");
	graphics = App->textures->Load("ryu4.png"); // arcade version

	SDL_Rect aux;
	aux.x = position.x;
	aux.y = (position.y - idle.frames[0].h);
	aux.w = 60;
	aux.h = 90;
	myCollider=App->collisions->CreateCollider(aux, this,PLAYER);
	return true;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	App->textures->Unload(graphics);

	return true;
}

update_status ModulePlayer::PreUpdate(){
	if (App->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT){
		position.x--;
	}
	else if (App->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT){
		position.x++;
	}
	return UPDATE_CONTINUE;
}

// Update
update_status ModulePlayer::Update()
{
	// TODO 9: Draw the player with its animation
	// make sure to detect player movement and change its
	// position while cycling the animation(check Animation.h)
	if (App->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT){
		App->renderer->Blit(graphics, position.x, position.y - (backward.GetCurrentFrame()).h, &(backward.GetCurrentFrame()) ); // ryu animation
	}
	else if (App->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT){
		App->renderer->Blit(graphics, position.x, position.y - (forward.GetCurrentFrame()).h, &(forward.GetCurrentFrame()) ); // ryu animation
	}
	else
		App->renderer->Blit(graphics, position.x, position.y - (idle.GetCurrentFrame()).h, &(idle.GetCurrentFrame())); // ryu animation
	//Fire hadouken
	if (App->input->GetKey(SDL_SCANCODE_F) == KEY_DOWN){
		particle aux;
		aux.position.x = position.x + 61;
		aux.position.y = position.y - 75;
		aux.anim.frames.push_back({ 493, 1563, 43, 32 });
		aux.anim.frames.push_back({ 550, 1565, 56, 28 });
		aux.anim.speed = 0.1f;
		aux.tex = graphics;
		aux.speed.x = 3;
		aux.speed.y = 0;
		App->particles->CreateParticle(aux);
	}
	myCollider->collisionBox.x = position.x;
	myCollider->collisionBox.y = (position.y - 90);
	return UPDATE_CONTINUE;
}

void ModulePlayer::OnCollision(Collider* a,Collider* b){
	LOG("M'an daoooo");
}

