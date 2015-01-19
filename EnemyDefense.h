#include <stdio.h>
#include "allegro5/allegro.h"
#include <allegro5/allegro_image.h>

#pragma once
#include "Enemy.h"

class EnemyDefense :
	public Enemy
{

public:
	EnemyDefense();
	~EnemyDefense();
};

