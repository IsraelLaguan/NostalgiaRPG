#include <stdio.h>
#include "math.h" 
#include "allegro5/allegro.h"
#include <allegro5/allegro_image.h>

#pragma once

#include "GameObject.h"

#define COLL_DISTANCE 30

class Physics
{
public:
	Physics();
	~Physics();

	ALLEGRO_BITMAP* bw = al_load_bitmap("Sprites/BWMap.jpg");

	void Move(GameObject* a, bool Xplane);
	bool Collision(GameObject* o1, GameObject* o2);
	void Check(GameObject* a, int d);
	void enemyCheck(GameObject* a, int* d);
};

