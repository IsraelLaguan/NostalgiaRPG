#pragma once
#include "GameObject.h"
class WeaponBalanced :
	public GameObject
{
public:
	bool on;
	bool active;
	WeaponBalanced();
	~WeaponBalanced();
};

