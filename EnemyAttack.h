#include <stdio.h>
#include "allegro5/allegro.h"
#include <allegro5/allegro_image.h>

#pragma once
#include "Enemy.h"

class EnemyAttack :
	public Enemy
{
	
public:
	EnemyAttack();
	~EnemyAttack();
};

