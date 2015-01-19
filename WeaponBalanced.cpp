#include "WeaponBalanced.h"


WeaponBalanced::WeaponBalanced()
{
	speed = 7;
	attack = 7;
	defense = 7;
	on = false;
	active = false;
	shape = al_load_bitmap("Sprites/banner/swoff.png");
}


WeaponBalanced::~WeaponBalanced()
{
}
