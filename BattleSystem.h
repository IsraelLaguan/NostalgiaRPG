#include <stdio.h>
#include "allegro5/allegro.h"
#include <allegro5/allegro_image.h>

#include "GameObject.h"
#include "Player.h"
#include "EnemyAttack.h"
#include "EnemyDefense.h"
#include "EnemySpeed.h"
#include "WeaponAttack.h"
#include "WeaponDefense.h"
#include "WeaponSpeed.h"
#include "WeaponBalanced.h"

#pragma once
class BattleSystem
{
public:
	BattleSystem();
	~BattleSystem();

	ALLEGRO_BITMAP *textBox;

	bool heroMoveFirst;
	int damage;

	int enemyState(int enemy);
	int attackDamage(int Attack, int Defense);
	bool checkSpeed(int playerSpeed, int enemySpeed);
	bool checkRun(int playerSpeed, int enemySpeed);


};

