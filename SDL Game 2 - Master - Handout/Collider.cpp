#include "Collider.h"
#include "Module.h"
Collider::Collider(SDL_Rect box,module* m){
	collisionBox = box;
	mod = m;
}

Collider::~Collider(){
}