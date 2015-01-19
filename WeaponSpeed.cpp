#include "WeaponSpeed.h"


WeaponSpeed::WeaponSpeed()
{
	speed = 15;
	attack = 6;
	defense = 0;
	on = false;
	active = false;
	shape = al_load_bitmap("Sprites/banner/spoff.png");
}


WeaponSpeed::~WeaponSpeed()
{
}
