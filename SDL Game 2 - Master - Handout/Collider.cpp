#include "Collider.h"
#include "Module.h"
Collider::Collider(SDL_Rect box,Module* m){
	collisionBox = box;
	mod = m;
}

Collider::~Collider(){
}