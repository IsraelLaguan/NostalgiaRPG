#include "WeaponDefense.h"


WeaponDefense::WeaponDefense()
{
	speed = 0;
	attack = 6;
	defense = 15;
	on = false;
	active = false;
	shape = al_load_bitmap("Sprites/banner/shoff.png");
}


WeaponDefense::~WeaponDefense()
{
}
