#include "Globals.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "ModuleParticle.h"
#include "SDL/include/SDL.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA
ModulePlayer::ModulePlayer(bool start_enabled) : Module(start_enabled)
{
	position.x = 100;
	position.y = 216;

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
}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");

	graphics = App->textures->Load("ryu4.png"); // arcade version

	return true;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	App->textures->Unload(graphics);

	return true;
}

// Update
update_status ModulePlayer::Update()
{
	// TODO 9: Draw the player with its animation
	// make sure to detect player movement and change its
	// position while cycling the animation(check Animation.h)
	if (App->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT){
		position.x--;
		App->renderer->Blit(graphics, position.x, position.y - (backward.GetCurrentFrame()).h, &(backward.GetCurrentFrame()), 0.75f); // ryu animation
	}
	else if (App->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT){
		position.x++;
		App->renderer->Blit(graphics, position.x, position.y - (forward.GetCurrentFrame()).h, &(forward.GetCurrentFrame()), 0.75f); // ryu animation
	}
	else
		App->renderer->Blit(graphics, position.x, position.y - (idle.GetCurrentFrame()).h, &(idle.GetCurrentFrame()), 0.75f); // ryu animation
	//Fire hadouken
	if (App->input->GetKey(SDL_SCANCODE_F) == KEY_DOWN){
		particle aux;
		aux.position.x = position.x + 40;
		aux.position.y = position.y - 75;
		aux.anim.frames.push_back({ 493, 1563, 43, 32 });
		aux.anim.frames.push_back({ 550, 1565, 56, 28 });
		aux.anim.speed = 0.1f;
		aux.tex = graphics;
		aux.speed.x = 3;
		aux.speed.y = 0;
		App->particles->CreateParticle(aux);
	}
	return UPDATE_CONTINUE;
}