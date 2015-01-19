#pragma once
#include "GameObject.h"
class WeaponAttack :
	public GameObject
{
public:
	bool on;
	bool active;
	WeaponAttack();
	~WeaponAttack();
};

