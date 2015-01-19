#include "WeaponAttack.h"


WeaponAttack::WeaponAttack()
{
	speed = 0;
	attack = 21;
	defense = 0;
	on = false;
	active = false;
	shape = al_load_bitmap("Sprites/banner/maoff.png");
}


WeaponAttack::~WeaponAttack()
{
}
