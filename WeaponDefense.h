#pragma once
#include "GameObject.h"
class WeaponDefense :
	public GameObject
{
public:
	bool on;
	bool active;
	WeaponDefense();
	~WeaponDefense();
};

