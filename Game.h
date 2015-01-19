#include <stdio.h>
#include "allegro5/allegro.h"
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_font.h> 
#include <allegro5/allegro_ttf.h>

#include "GameObject.h"
#include "Player.h"
#include "EnemyAttack.h"
#include "EnemyDefense.h"
#include "EnemySpeed.h"
#include "textBox.h"
#include "Physics.h"
#include "WeaponAttack.h"
#include "WeaponDefense.h"
#include "WeaponSpeed.h"
#include "WeaponBalanced.h"
#include "BattleSystem.h"
#include "Render.h"
#include "Sound.h"

#pragma once

class Game
{
public:
	Player player;
	EnemyAttack wasp;
	EnemyDefense toadstool;
	EnemySpeed bat;
	WeaponBalanced sword;
	GameObject chest1;
	WeaponAttack mace;
	GameObject chest2;
	WeaponSpeed spear;
	GameObject chest3;
	WeaponDefense shield;
	GameObject chest4;
	GameObject crystal;
	ALLEGRO_BITMAP *bg;
	ALLEGRO_BITMAP *banner;
	ALLEGRO_BITMAP *Bplayer;
	ALLEGRO_BITMAP *chest;
	ALLEGRO_BITMAP *chestOpen;
	ALLEGRO_BITMAP *crystalChest;
	ALLEGRO_BITMAP *crystalChestOpen;
	ALLEGRO_BITMAP *titlescreen = al_load_bitmap("Sprites/titlescreen.png");
	ALLEGRO_BITMAP *charscreen = al_load_bitmap("Sprites/GenderSelection.png");
	BattleSystem battlesystem;
	textBox textbox;
	ALLEGRO_EVENT_QUEUE *event_queue;
	Render render;
	Physics physics;
	Sound sound;

	bool quit;
	bool enter;
	bool select;
	bool battlearena;
	bool reset;
	bool reset2;
	bool gameover;
	bool win;
	bool caseX;
	int enemyFace;
	bool turnOne;
	bool endBattle;
	bool pickState;
	bool enemyDead;
	int oldx = player.x;
	int oldy = player.y;
	int oldxscroll = render.xscroll;
	int oldyscroll = render.yscroll;

	int A1 = 480;
	int A2 = 960;
	int A3 = 0;
	int A4 = 640;
	int oldA1 = A1;
	int oldA2 = A2;
	int oldA3 = A3;
	int oldA4 = A4;

	int totalhealth;
	int totalattack;
	int totalspeed;
	int totaldefense;

	int enemySpeed;
	int enemyAttack;
	int enemyDefense;
	int enemyHealth;

	char health[20];
	char attack[20];
	char speed[20];
	char defense[20];

	char line1[80];
	char line2[80];
	char line3[80];
	char line4[80];
	char enemyHealthText[20];
	char playerHealthText[20];

	int playerState;
	int enemyState;

	Game();
	~Game();
	void Init();
	void Update();
	void Draw();
	void Run();
};