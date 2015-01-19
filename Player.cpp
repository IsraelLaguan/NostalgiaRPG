#include "Player.h"

Player::Player()
{
	x = 150; 
	y = 900;
	speed = 5;
	attack = 5;
	defense = 5;
	health = 50;
	movement = 7;
	height = 48;
	width = 32;
	direction = DIR_UP;
	vx = movement;
	vy = movement;

	currentFrame = 0;
	
}


Player::~Player()
{
	for (int i = 0; i < NUM_FRAMES; i++)
	{
		al_destroy_bitmap(animR[i]);
		al_destroy_bitmap(animL[i]);
		al_destroy_bitmap(animU[i]);
		al_destroy_bitmap(animD[i]);
	}
}

void Player::Advance(int d)
{
	SetDirection(d);
	currentFrame++;
	if (currentFrame == NUM_FRAMES)
		currentFrame = 0;
	switch (d)
	{
	case DIR_RIGHT:
		shape = animR[currentFrame];
		break;
	case DIR_LEFT:
		shape = animL[currentFrame];
		break;
	case DIR_UP:
		shape = animU[currentFrame];
		break;
	case DIR_DOWN:
		shape = animD[currentFrame];
		break;
	default:
		break;
	}
}

void Player::Gender()
{
	if (male == true)
	{
		shapeD = al_load_bitmap("Sprites/CharMale/F1.png");
		shapeU = al_load_bitmap("Sprites/CharMale/B1.png");
		shapeL = al_load_bitmap("Sprites/CharMale/L1.png");
		shapeR = al_load_bitmap("Sprites/CharMale/R1.png");
		shape = shapeU;

		animR[0] = al_load_bitmap("Sprites/CharMale/R1.png");
		animR[1] = al_load_bitmap("Sprites/CharMale/R1.png");
		animR[2] = al_load_bitmap("Sprites/CharMale/R2.png");
		animR[3] = al_load_bitmap("Sprites/CharMale/R2.png");
		animR[4] = al_load_bitmap("Sprites/CharMale/R3.png");
		animR[5] = al_load_bitmap("Sprites/CharMale/R3.png");
		animR[6] = al_load_bitmap("Sprites/CharMale/R4.png");
		animR[7] = al_load_bitmap("Sprites/CharMale/R4.png");

		animL[0] = al_load_bitmap("Sprites/CharMale/L1.png");
		animL[1] = al_load_bitmap("Sprites/CharMale/L1.png");
		animL[2] = al_load_bitmap("Sprites/CharMale/L2.png");
		animL[3] = al_load_bitmap("Sprites/CharMale/L2.png");
		animL[4] = al_load_bitmap("Sprites/CharMale/L3.png");
		animL[5] = al_load_bitmap("Sprites/CharMale/L3.png");
		animL[6] = al_load_bitmap("Sprites/CharMale/L4.png");
		animL[7] = al_load_bitmap("Sprites/CharMale/L4.png");

		animU[0] = al_load_bitmap("Sprites/CharMale/B1.png");
		animU[1] = al_load_bitmap("Sprites/CharMale/B1.png");
		animU[2] = al_load_bitmap("Sprites/CharMale/B2.png");
		animU[3] = al_load_bitmap("Sprites/CharMale/B2.png");
		animU[4] = al_load_bitmap("Sprites/CharMale/B3.png");
		animU[5] = al_load_bitmap("Sprites/CharMale/B3.png");
		animU[6] = al_load_bitmap("Sprites/CharMale/B4.png");
		animU[7] = al_load_bitmap("Sprites/CharMale/B4.png");

		animD[0] = al_load_bitmap("Sprites/CharMale/F1.png");
		animD[1] = al_load_bitmap("Sprites/CharMale/F1.png");
		animD[2] = al_load_bitmap("Sprites/CharMale/F2.png");
		animD[3] = al_load_bitmap("Sprites/CharMale/F2.png");
		animD[4] = al_load_bitmap("Sprites/CharMale/F3.png");
		animD[5] = al_load_bitmap("Sprites/CharMale/F3.png");
		animD[6] = al_load_bitmap("Sprites/CharMale/F4.png");
		animD[7] = al_load_bitmap("Sprites/CharMale/F4.png");
	}
	else if (male == false)
	{
		shapeD = al_load_bitmap("Sprites/CharFemale/F1.png");
		shapeU = al_load_bitmap("Sprites/CharFemale/B1.png");
		shapeL = al_load_bitmap("Sprites/CharFemale/L1.png");
		shapeR = al_load_bitmap("Sprites/CharFemale/R1.png");
		shape = shapeU;

		animR[0] = al_load_bitmap("Sprites/CharFemale/R1.png");
		animR[1] = al_load_bitmap("Sprites/CharFemale/R1.png");
		animR[2] = al_load_bitmap("Sprites/CharFemale/R2.png");
		animR[3] = al_load_bitmap("Sprites/CharFemale/R2.png");
		animR[4] = al_load_bitmap("Sprites/CharFemale/R3.png");
		animR[5] = al_load_bitmap("Sprites/CharFemale/R3.png");
		animR[6] = al_load_bitmap("Sprites/CharFemale/R4.png");
		animR[7] = al_load_bitmap("Sprites/CharFemale/R4.png");

		animL[0] = al_load_bitmap("Sprites/CharFemale/L1.png");
		animL[1] = al_load_bitmap("Sprites/CharFemale/L1.png");
		animL[2] = al_load_bitmap("Sprites/CharFemale/L2.png");
		animL[3] = al_load_bitmap("Sprites/CharFemale/L2.png");
		animL[4] = al_load_bitmap("Sprites/CharFemale/L3.png");
		animL[5] = al_load_bitmap("Sprites/CharFemale/L3.png");
		animL[6] = al_load_bitmap("Sprites/CharFemale/L4.png");
		animL[7] = al_load_bitmap("Sprites/CharFemale/L4.png");

		animU[0] = al_load_bitmap("Sprites/CharFemale/B1.png");
		animU[1] = al_load_bitmap("Sprites/CharFemale/B1.png");
		animU[2] = al_load_bitmap("Sprites/CharFemale/B2.png");
		animU[3] = al_load_bitmap("Sprites/CharFemale/B2.png");
		animU[4] = al_load_bitmap("Sprites/CharFemale/B3.png");
		animU[5] = al_load_bitmap("Sprites/CharFemale/B3.png");
		animU[6] = al_load_bitmap("Sprites/CharFemale/B4.png");
		animU[7] = al_load_bitmap("Sprites/CharFemale/B4.png");

		animD[0] = al_load_bitmap("Sprites/CharFemale/F1.png");
		animD[1] = al_load_bitmap("Sprites/CharFemale/F1.png");
		animD[2] = al_load_bitmap("Sprites/CharFemale/F2.png");
		animD[3] = al_load_bitmap("Sprites/CharFemale/F2.png");
		animD[4] = al_load_bitmap("Sprites/CharFemale/F3.png");
		animD[5] = al_load_bitmap("Sprites/CharFemale/F3.png");
		animD[6] = al_load_bitmap("Sprites/CharFemale/F4.png");
		animD[7] = al_load_bitmap("Sprites/CharFemale/F4.png");
	}
}
