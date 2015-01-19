#pragma once
#include "GameObject.h"
class WeaponSpeed :
	public GameObject
{
public:
	bool on;
	bool active;
	WeaponSpeed();
	~WeaponSpeed();
};

