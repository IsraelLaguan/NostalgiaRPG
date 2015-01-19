#include "EnemyDefense.h"


EnemyDefense::EnemyDefense()
{
	speed = 5;
	attack = 5;
	defense = 25;
	health = 30;
	movement = 3;
	width = 48;
	height = 70;
	x = 200;
	y = 200;
	direction = DIR_RIGHT;

	shapeD = al_load_bitmap("Sprites/Toadstool/F1.png");
	shapeU = al_load_bitmap("Sprites/Toadstool/B1.png");
	shapeL = al_load_bitmap("Sprites/Toadstool/L1.png");
	shapeR = al_load_bitmap("Sprites/Toadstool/R1.png");

	animR[0] = al_load_bitmap("Sprites/Toadstool/R1.png");
	animR[1] = al_load_bitmap("Sprites/Toadstool/R1.png");
	animR[2] = al_load_bitmap("Sprites/Toadstool/R2.png");
	animR[3] = al_load_bitmap("Sprites/Toadstool/R2.png");
	animR[4] = al_load_bitmap("Sprites/Toadstool/R3.png");
	animR[5] = al_load_bitmap("Sprites/Toadstool/R3.png");


	animL[0] = al_load_bitmap("Sprites/Toadstool/L1.png");
	animL[1] = al_load_bitmap("Sprites/Toadstool/L1.png");
	animL[2] = al_load_bitmap("Sprites/Toadstool/L2.png");
	animL[3] = al_load_bitmap("Sprites/Toadstool/L2.png");
	animL[4] = al_load_bitmap("Sprites/Toadstool/L3.png");
	animL[5] = al_load_bitmap("Sprites/Toadstool/L3.png");


	animU[0] = al_load_bitmap("Sprites/Toadstool/B1.png");
	animU[1] = al_load_bitmap("Sprites/Toadstool/B1.png");
	animU[2] = al_load_bitmap("Sprites/Toadstool/B2.png");
	animU[3] = al_load_bitmap("Sprites/Toadstool/B2.png");
	animU[4] = al_load_bitmap("Sprites/Toadstool/B3.png");
	animU[5] = al_load_bitmap("Sprites/Toadstool/B3.png");


	animD[0] = al_load_bitmap("Sprites/Toadstool/F1.png");
	animD[1] = al_load_bitmap("Sprites/Toadstool/F1.png");
	animD[2] = al_load_bitmap("Sprites/Toadstool/F2.png");
	animD[3] = al_load_bitmap("Sprites/Toadstool/F2.png");
	animD[4] = al_load_bitmap("Sprites/Toadstool/F3.png");
	animD[5] = al_load_bitmap("Sprites/Toadstool/F3.png");


	shape = al_load_bitmap("Sprites/Toadstool/R1.png");

	currentFrame = 0;
}


EnemyDefense::~EnemyDefense()
{
}
