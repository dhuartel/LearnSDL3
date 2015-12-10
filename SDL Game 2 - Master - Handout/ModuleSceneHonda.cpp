#include "Globals.h"
#include "Application.h"
#include "ModuleSceneHonda.h"
#include "ModuleSceneKen.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleAudio.h"
#include "ModuleFadeToBlack.h"
#include "SDL/include/SDL.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleSceneHonda::ModuleSceneHonda(bool start_enabled) : Module(start_enabled)
{
	// ground
	ground.x = 8;
	ground.y = 376;
	ground.w = 896;
	ground.h = 87;

	// TODO 2 : setup the foreground (pool) with
	// coordinates x,y,w,h from ken_stage.png
	pool.x = 8;
	pool.y = 23;
	pool.w = 521;
	pool.h = 181;

	//Left wall
	wall.x = 120;
	wall.y = 128;
	wall.w = 96;
	wall.h = 246;
	// Background
	background.x = 216;
	background.y = 176;
	background.w = 671;
	background.h = 130;
}

ModuleSceneHonda::~ModuleSceneHonda()
{}

// Load assets
bool ModuleSceneHonda::Start()
{
	LOG("Loading Honda scene");

	graphics = App->textures->Load("honda_stage.png");

	// TODO 7: Enable the player module
	App->player->Enable();
	// TODO 0: trigger background music
	App->audio->PlayMusic("honda.ogg");
	return true;
}

// UnLoad assets
bool ModuleSceneHonda::CleanUp()
{
	LOG("Unloading honda scene");

	App->textures->Unload(graphics);
	App->player->Disable();

	return true;
}

// Update: draw background
update_status ModuleSceneHonda::Update()
{
	
	// Draw everything --------------------------------------
	// TODO 1: Tweak the movement speed of the sea&sky + flag to your taste
	App->renderer->Blit(graphics, 0, 170, &ground);
	App->renderer->Blit(graphics, 0, 40, &wall, 0.75f); // left wall
	App->renderer->Blit(graphics, 96, 40, &background, 0.75f); // rest of wall

	//App->renderer->Blit(graphics, 0, 0, &pool, 0.75f);
	// TODO 6: Draw the girl. Make sure it follows the ship movement!


	// TODO 10: Build an entire new scene "honda", you can find its
	// and music in the Game/ folder

	// TODO 11: Make that pressing space triggers a switch to honda logic module
	// using FadeToBlack module
	if (App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_DOWN){
		App->fade->FadeToBlack(App->scene_ken, nullptr, 5.0f);
	}

	return UPDATE_CONTINUE;
}