#include "EnemySpeed.h"


EnemySpeed::EnemySpeed()
{
	speed = 25;
	attack = 5;
	defense = 5;
	health = 30;
	movement = 10;
	width = 48;
	height = 48;
	x = 400;
	y = 300;
	direction = DIR_UP;

	shapeD = al_load_bitmap("Sprites/Bat/F1.png");
	shapeU = al_load_bitmap("Sprites/Bat/B1.png");
	shapeL = al_load_bitmap("Sprites/Bat/L1.png");
	shapeR = al_load_bitmap("Sprites/Bat/R1.png");

	animR[0] = al_load_bitmap("Sprites/Bat/R1.png");
	animR[1] = al_load_bitmap("Sprites/Bat/R1.png");
	animR[2] = al_load_bitmap("Sprites/Bat/R2.png");
	animR[3] = al_load_bitmap("Sprites/Bat/R2.png");
	animR[4] = al_load_bitmap("Sprites/Bat/R3.png");
	animR[5] = al_load_bitmap("Sprites/Bat/R3.png");


	animL[0] = al_load_bitmap("Sprites/Bat/L1.png");
	animL[1] = al_load_bitmap("Sprites/Bat/L1.png");
	animL[2] = al_load_bitmap("Sprites/Bat/L2.png");
	animL[3] = al_load_bitmap("Sprites/Bat/L2.png");
	animL[4] = al_load_bitmap("Sprites/Bat/L3.png");
	animL[5] = al_load_bitmap("Sprites/Bat/L3.png");


	animU[0] = al_load_bitmap("Sprites/Bat/B1.png");
	animU[1] = al_load_bitmap("Sprites/Bat/B1.png");
	animU[2] = al_load_bitmap("Sprites/Bat/B2.png");
	animU[3] = al_load_bitmap("Sprites/Bat/B2.png");
	animU[4] = al_load_bitmap("Sprites/Bat/B3.png");
	animU[5] = al_load_bitmap("Sprites/Bat/B3.png");


	animD[0] = al_load_bitmap("Sprites/Bat/F1.png");
	animD[1] = al_load_bitmap("Sprites/Bat/F1.png");
	animD[2] = al_load_bitmap("Sprites/Bat/F2.png");
	animD[3] = al_load_bitmap("Sprites/Bat/F2.png");
	animD[4] = al_load_bitmap("Sprites/Bat/F3.png");
	animD[5] = al_load_bitmap("Sprites/Bat/F3.png");


	shape = al_load_bitmap("Sprites/Bat/B1.png");

	currentFrame = 0;
}


EnemySpeed::~EnemySpeed()
{
}
