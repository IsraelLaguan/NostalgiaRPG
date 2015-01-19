#include "BattleSystem.h"
#include <time.h>  
#include <stdlib.h>

BattleSystem::BattleSystem()
{

}


BattleSystem::~BattleSystem()
{
}

int BattleSystem::enemyState(int enemy)
{
	int decision = rand() % 100;
	int state;

	if (enemy == 1)
	{
		if (decision >= 0 && decision < 50)
			state = 1;
		else
			state = 2;
	}
	else if (enemy == 2)
	{
		if (decision >= 0 && decision < 25)
			state = 1;
		else
			state = 2;
	}
	else if (enemy == 3)
	{
		if (decision >= 0 && decision < 75)
			state = 1;
		else
			state = 2;
	}

	return state;
}



int BattleSystem::attackDamage(int attack, int defense)
{
	srand(time(NULL));

	int damage = attack - (defense / 2);

	if (damage <= 0)
	{
		damage = rand() % 2;
	}

	return damage;
}


bool BattleSystem::checkSpeed(int playerSpeed, int enemySpeed)
{
	bool playerFirst;

	srand(time(NULL));

	if (playerSpeed > enemySpeed)
		playerFirst = true;
	else if (playerSpeed < enemySpeed)
		playerFirst = false;
	else if (playerSpeed == enemySpeed)
	{
		int randomStart = rand() % 2;

		if (randomStart == 0)
			playerFirst = true;
		else
			playerFirst = false;
	}

	return playerFirst;
}

bool BattleSystem::checkRun(int playerSpeed, int enemySpeed)
{
	srand(time(NULL));

	bool runAway;
	int runAwayChance = rand() % 100;


	if (playerSpeed >= enemySpeed)
	{
		if (runAwayChance < 95)
		{
			runAway = true;
		}
		else
			runAway = false;
	}
	else if (playerSpeed < enemySpeed)
	{
		if (runAwayChance < 10)
		{
			runAway = true;
		}
		else
			runAway = false;
	}

	return runAway;
}