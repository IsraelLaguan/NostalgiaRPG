#include "EnemyAttack.h"


EnemyAttack::EnemyAttack()
{
	speed = 5;
	attack = 25;
	defense = 5;
	health = 30;
	movement = 5;
	width = 42;
	height = 45;
	x = 800;
	y = 200;
	direction = DIR_LEFT;

	shapeD = al_load_bitmap("Sprites/Wasp/F1.png");
	shapeU = al_load_bitmap("Sprites/Wasp/B1.png");
	shapeL = al_load_bitmap("Sprites/Wasp/L1.png");
	shapeR = al_load_bitmap("Sprites/Wasp/R1.png");

	animR[0] = al_load_bitmap("Sprites/Wasp/R1.png");
	animR[1] = al_load_bitmap("Sprites/Wasp/R1.png");
	animR[2] = al_load_bitmap("Sprites/Wasp/R2.png");
	animR[3] = al_load_bitmap("Sprites/Wasp/R2.png");
	animR[4] = al_load_bitmap("Sprites/Wasp/R1.png");
	animR[5] = al_load_bitmap("Sprites/Wasp/R1.png");


	animL[0] = al_load_bitmap("Sprites/Wasp/L1.png");
	animL[1] = al_load_bitmap("Sprites/Wasp/L1.png");
	animL[2] = al_load_bitmap("Sprites/Wasp/L2.png");
	animL[3] = al_load_bitmap("Sprites/Wasp/L2.png");
	animL[4] = al_load_bitmap("Sprites/Wasp/L1.png");
	animL[5] = al_load_bitmap("Sprites/Wasp/L1.png");


	animU[0] = al_load_bitmap("Sprites/Wasp/B1.png");
	animU[1] = al_load_bitmap("Sprites/Wasp/B1.png");
	animU[2] = al_load_bitmap("Sprites/Wasp/B2.png");
	animU[3] = al_load_bitmap("Sprites/Wasp/B2.png");
	animU[4] = al_load_bitmap("Sprites/Wasp/B1.png");
	animU[5] = al_load_bitmap("Sprites/Wasp/B1.png");


	animD[0] = al_load_bitmap("Sprites/Wasp/F1.png");
	animD[1] = al_load_bitmap("Sprites/Wasp/F1.png");
	animD[2] = al_load_bitmap("Sprites/Wasp/F2.png");
	animD[3] = al_load_bitmap("Sprites/Wasp/F2.png");
	animD[4] = al_load_bitmap("Sprites/Wasp/F1.png");
	animD[5] = al_load_bitmap("Sprites/Wasp/F1.png");


	shape = al_load_bitmap("Sprites/Wasp/L1.png");

	currentFrame = 0;

}


EnemyAttack::~EnemyAttack()
{
	
}

