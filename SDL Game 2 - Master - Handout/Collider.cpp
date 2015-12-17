#include "Collider.h"
#include "Module.h"


Collider::Collider(SDL_Rect box,Module* m,colliderType colType){
	collisionBox = box;
	mod = m;
	flag = false;
	type = colType;
}

Collider::~Collider(){
}

void Collider::flagRelease(){
	flag = true;
}