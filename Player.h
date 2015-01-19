#include <stdio.h>
#include "allegro5/allegro.h"
#include <allegro5/allegro_image.h>

#include "GameObject.h"

#pragma once

#define NUM_FRAMES 8

class Player :
	public GameObject
{
protected:
	int direction;
public:
	ALLEGRO_BITMAP* animR[NUM_FRAMES];
	ALLEGRO_BITMAP* animL[NUM_FRAMES];
	ALLEGRO_BITMAP* animU[NUM_FRAMES];
	ALLEGRO_BITMAP* animD[NUM_FRAMES];

	bool male;
	int currentFrame;
	void Advance(int d);
	void Gender();
	Player();
	~Player();
};

