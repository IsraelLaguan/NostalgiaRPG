#include "Game.h"

extern ALLEGRO_FONT *font;

Game::Game()
{
	quit = false;
	battlearena = false;
	enter = false;
	select = false;

	chest = al_load_bitmap("Sprites/chest.png");
	chestOpen = al_load_bitmap("Sprites/chestOpen.png");
	crystalChest = al_load_bitmap("Sprites/crystalChest.png");
	crystalChestOpen = al_load_bitmap("Sprites/crystalChestOpen.png");

	chest1.shape = chest2.shape = chest3.shape = chest4.shape = chest;

	crystal.shape = crystalChest;

	chest1.x = 141;
	chest1.y = 368;

	chest2.x = 19;
	chest2.y = 142;

	chest3.x = 693;
	chest3.y = 789;

	chest4.x = 1241;
	chest4.y = 113;

	crystal.visibility = 0;

	turnOne = true;
	pickState = true;

	totalhealth = player.health;
	totalattack = player.attack;
	totalspeed = player.speed;
	totaldefense = player.defense;

}
Game::~Game()
{
	al_destroy_bitmap(bg);
	al_destroy_bitmap(banner);
	al_destroy_bitmap(Bplayer);
}
void Game::Init()
{
	enter = false;

	if (battlearena == false)
	{
		bg = al_load_bitmap("Sprites/Map.jpg");
		banner = al_load_bitmap("Sprites/banner/bannerbg.png");
		//player icon
		if (player.male == true)
			Bplayer = al_load_bitmap("Sprites/banner/maleicon.png");
		else
			Bplayer = al_load_bitmap("Sprites/banner/femaleicon.png");
		
		player.Gender();

		//Saving old points before battle
		player.x = oldx;
		player.y = oldy;
		render.xscroll = oldxscroll;
		render.yscroll = oldyscroll;
		A1 = oldA1;
		A2 = oldA2;
		A3 = oldA3;
		A4 = oldA4;
	}
	else if (battlearena == true)
	{
		bg = al_load_bitmap("Sprites/Map2.png");

		oldxscroll = render.xscroll;
		oldyscroll = render.yscroll;
		render.xscroll = 0;
		render.yscroll = 0;

		oldx = player.x;
		oldy = player.y;
		player.x = 120;
		player.y = 200;

		oldA1 = A1;
		oldA2 = A2;
		oldA3 = A3;
		oldA4 = A4;

		playerState = 0;
		pickState = TRUE;

		if (player.male == true)
			player.shape = al_load_bitmap("Sprites/Battle/battle_male.png");
		else
			player.shape = al_load_bitmap("Sprites/Battle/battle_female.png");

		if (enemyFace == 1)
		{
			enemySpeed = bat.speed;
			enemyAttack = bat.attack;
			enemyDefense = bat.defense;
			enemyHealth = bat.health;
			bat.shape = al_load_bitmap("Sprites/Battle/battle_bat.png");
			bat.x = 440;
			bat.y = 160;
		}
		else if (enemyFace == 2)
		{
			enemySpeed = toadstool.speed;
			enemyAttack = toadstool.attack;
			enemyDefense = toadstool.defense;
			enemyHealth = toadstool.health;
			toadstool.shape = al_load_bitmap("Sprites/Battle/battle_toadstool.png");
			toadstool.x = 420;
			toadstool.y = 220;
		}
		else if (enemyFace == 3)
		{
			enemySpeed = wasp.speed;
			enemyAttack = wasp.attack;
			enemyDefense = wasp.defense;
			enemyHealth = wasp.health;
			wasp.shape = al_load_bitmap("Sprites/Battle/battle_wasp.png");
			wasp.x = 440;
			wasp.y = 160;
		}

	}

};

void Game::Update()
{
	ALLEGRO_KEYBOARD_STATE key_state;
	al_get_keyboard_state(&key_state);

	if (al_key_down(&key_state, ALLEGRO_KEY_ESCAPE))
	{
		quit = true;
	}

	if (battlearena == false)
	{
		//sword icon
		if (sword.on == true)
		{
			if (sword.active == true)
				sword.shape = al_load_bitmap("Sprites/banner/swon.png");
			else
				sword.shape = al_load_bitmap("Sprites/banner/swoff.png");
		}
		else
			sword.shape = al_load_bitmap("Sprites/banner/emptyWP.png");

		//mace icon
		if (mace.on == true)
		{
			if (mace.active == true)
				mace.shape = al_load_bitmap("Sprites/banner/maon.png");
			else
				mace.shape = al_load_bitmap("Sprites/banner/maoff.png");
		}
		else
			mace.shape = al_load_bitmap("Sprites/banner/emptyWP.png");

		//spear icon
		if (spear.on == true)
		{
			if (spear.active == true)
				spear.shape = al_load_bitmap("Sprites/banner/spon.png");
			else
				spear.shape = al_load_bitmap("Sprites/banner/spoff.png");
		}
		else
			spear.shape = al_load_bitmap("Sprites/banner/emptyWP.png");

		//shield icon
		if (shield.on == true)
		{
			if (shield.active == true)
				shield.shape = al_load_bitmap("Sprites/banner/shon.png");
			else
				shield.shape = al_load_bitmap("Sprites/banner/shoff.png");
		}
		else
			shield.shape = al_load_bitmap("Sprites/banner/emptyWP.png");

		if (al_key_down(&key_state, ALLEGRO_KEY_RIGHT))
		{
			player.SetDirection(DIR_RIGHT);
			player.Advance(DIR_RIGHT);
			physics.Check(&player, DIR_RIGHT);
			caseX = true;
		}
		else if (al_key_down(&key_state, ALLEGRO_KEY_LEFT))
		{
			player.SetDirection(DIR_LEFT);
			player.Advance(DIR_LEFT);
			physics.Check(&player, DIR_LEFT);
			caseX = true;
		}
		else if (al_key_down(&key_state, ALLEGRO_KEY_UP))
		{
			player.SetDirection(DIR_UP);
			player.Advance(DIR_UP);
			physics.Check(&player, DIR_UP);
			caseX = false;
		}
		else if (al_key_down(&key_state, ALLEGRO_KEY_DOWN))
		{
			player.SetDirection(DIR_DOWN);
			player.Advance(DIR_DOWN);
			physics.Check(&player, DIR_DOWN);
			caseX = false;
		}
		else
		{
			player.SetDirection(DIR_STOP);
		}

		if (al_key_down(&key_state, ALLEGRO_KEY_SPACE))
		{
			if (physics.Collision(&player, &chest1))
			{
				chest1.shape = chestOpen;
				sword.on = true;
				sound.chestsound();
			}
			if (physics.Collision(&player, &chest2))
			{
				chest2.shape = chestOpen;
				mace.on = true;
				sound.chestsound();
			}
			if (physics.Collision(&player, &chest3))
			{
				chest3.shape = chestOpen;
				spear.on = true;
				sound.chestsound();
			}
			if (physics.Collision(&player, &chest4))
			{
				chest4.shape = chestOpen;
				shield.on = true;
				sound.chestsound();
			}
			if (physics.Collision(&player, &crystal))
			{
				crystal.shape = crystalChestOpen;
				win = true;
				sound.chestsound();
			}
		}
		if (sword.on == true)
			if (al_key_down(&key_state, ALLEGRO_KEY_1))
			{
				sound.weaponsound();
				sword.active = true;
				mace.active = false;
				spear.active = false;
				shield.active = false;
				totalattack = player.attack + sword.attack;
				totalspeed = player.speed + sword.speed;
				totaldefense = player.defense + sword.defense;
			}
		if (mace.on == true)
			if (al_key_down(&key_state, ALLEGRO_KEY_2))
			{
				sound.weaponsound();
				sword.active = false;
				mace.active = true;
				spear.active = false;
				shield.active = false;
				totalattack = player.attack + mace.attack;
				totalspeed = player.speed + mace.speed;
				totaldefense = player.defense + mace.defense;
			}
		if (spear.on == true)
			if (al_key_down(&key_state, ALLEGRO_KEY_3))
			{
				sound.weaponsound();
				sword.active = false;
				mace.active = false;
				spear.active = true;
				shield.active = false;
				totalattack = player.attack + spear.attack;
				totalspeed = player.speed + spear.speed;
				totaldefense = player.defense + spear.defense;
			}
		if (shield.on == true)
			if (al_key_down(&key_state, ALLEGRO_KEY_4))
			{
				sound.weaponsound();
				sword.active = false;
				mace.active = false;
				spear.active = false;
				shield.active = true;
				totalattack = player.attack + shield.attack;
				totalspeed = player.speed + shield.speed;
				totaldefense = player.defense + shield.defense;
			}

		if (physics.Collision(&player, &wasp))
		{
			enemyFace = 3;
			battlearena = true;
			reset = true;
		}
		else if (physics.Collision(&player, &bat))
		{
			enemyFace = 1;
			battlearena = true;
			reset = true;
		}
		else if (physics.Collision(&player, &toadstool))
		{
			enemyFace = 2;
			battlearena = true;
			reset = true;
		}


		//actual move
		if (player.action == false)
		{
			int oldx = player.x;
			int oldy = player.y;
			physics.Move(&player, caseX);
			if ((player.y - A1) <= 52 && A1 >= 5)
			{
				render.yscroll += oldy - player.y;
				A1 = A1 - player.movement;
				A2 = A2 - player.movement;
			}
			if ((A2 - player.y) <= 100 && A2 <= 955)
			{
				render.yscroll += oldy - player.y;
				A1 = A1 + player.movement;
				A2 = A2 + player.movement;
			}
			if ((player.x - A3) <= 68 && A3 >= 5)
			{
				render.xscroll += oldx - player.x;
				A3 = A3 - player.movement;
				A4 = A4 - player.movement;
			}
			if ((A4 - player.x) <= 100 && A4 <= 1275)
			{
				render.xscroll += oldx - player.x;
				A3 = A3 + player.movement;
				A4 = A4 + player.movement;
			}
		}

		physics.enemyCheck(&wasp, &wasp.direction);
		wasp.Move();

		physics.enemyCheck(&bat, &bat.direction);
		bat.Move();

		physics.enemyCheck(&toadstool, &toadstool.direction);
		toadstool.Move();

		sprintf_s(health, "%d", totalhealth);
		sprintf_s(attack, "%d", totalattack);
		sprintf_s(speed, "%d", totalspeed);
		sprintf_s(defense, "%d", totaldefense);
	}
	else if (battlearena == true)
	{

		if (pickState == true)
		{
			//Player State and Enemy State

			enemyState = battlesystem.enemyState(enemyFace);

			if (al_key_down(&key_state, ALLEGRO_KEY_Q))
			{
				playerState = 1;

				pickState = false;
			}
			else if (al_key_down(&key_state, ALLEGRO_KEY_W))
			{
				playerState = 2;

				pickState = false;
			}
			else if (al_key_down(&key_state, ALLEGRO_KEY_E))
			{
				playerState = 3;

				pickState = false;
			}
			else
			{
				sprintf_s(line1, "Q: Attack | W: Defend | E: Run");
				sprintf_s(playerHealthText, "Player: %d", player.health);
				sprintf_s(enemyHealthText, "Enemy: %d", enemyHealth);
			}
		}
		//Once a command is picked
		else if (pickState == false)
		{
			//Player and enemy attacks
			if (playerState == 1 && enemyState == 1)
			{
				sound.attacksound();
				sound.enemysound();
				bool attackOrder = battlesystem.checkSpeed(totalspeed, enemySpeed);

				if (attackOrder == true)
				{

					int playerDamage = battlesystem.attackDamage(totalattack, enemyDefense);
					enemyHealth = enemyHealth - playerDamage;

					if (enemyHealth <= 0)
					{
						battlearena = false;
						reset2 = true;
						enemyDead = true;
						player.health = 50;
					}

					else
					{
						int enemyDamage = battlesystem.attackDamage(enemyAttack, totaldefense);
						player.health = player.health - enemyDamage;

						if (player.health <= 0)
						{
							gameover = true;
						}
						else
						{
							sprintf_s(line2, "You attack first, you dealt %d damage", playerDamage);
							sprintf_s(line3, "Enemy attacks second, it dealt %d damage", enemyDamage);
							sprintf_s(line4, " ");

							pickState = TRUE;
						}
					}
				}
				else if (attackOrder == false)
				{
					int enemyDamage = battlesystem.attackDamage(enemyAttack, totaldefense);
					player.health = player.health - enemyDamage;

					if (player.health <= 0)
					{
						gameover = true;
					}

					else
					{
						int playerDamage = battlesystem.attackDamage(totalattack, enemyDefense);
						enemyHealth = enemyHealth - playerDamage;


						if (enemyHealth <= 0)
						{
							battlearena = false;
							reset2 = true;
							enemyDead = true;
							player.health = 50;
						}
						else
						{

							sprintf_s(line2, "Enemy attacks first, it dealt %d damage", enemyDamage);
							sprintf_s(line3, "You attack second, you dealt %d damage", playerDamage);
							sprintf_s(line4, " ");

							pickState = TRUE;
						}
					}
				}
			}
			//Player attacks and enemy defends
			else if (playerState == 1 && enemyState == 2)
			{
				sound.weaksound();
				enemyDefense = enemyDefense + 5;

				int playerDamage = battlesystem.attackDamage(totalattack, enemyDefense);
				enemyHealth = enemyHealth - playerDamage;


				if (enemyHealth <= 0)
				{
					battlearena = false;
					reset2 = true;
					enemyDead = true;
					player.health = 50;
				}
				else
				{
					enemyDefense = enemyDefense - 5;

					sprintf_s(line2, "Enemy defends");
					sprintf_s(line3, "You attack second, you dealt %d damage", playerDamage);
					sprintf_s(line4, " ");

					pickState = TRUE;
				}

			}
			//Player defends and enemy attacks
			else if (playerState == 2 && enemyState == 1)
			{
				sound.enemysound();
				totaldefense = totaldefense + 5;

				int enemyDamage = battlesystem.attackDamage(enemyAttack, totaldefense);
				player.health = player.health - enemyDamage;


				if (player.health <= 0)
				{
					gameover = true;
				}
				else
				{
					totaldefense = totaldefense - 5;

					sprintf_s(line2, "You defend");
					sprintf_s(line3, "Enemy attacks, it dealt %d damage", enemyDamage);
					sprintf_s(line4, " ");

					pickState = TRUE;
				}
			}
			//Player and enemy defends
			else if (playerState == 2 && enemyState == 2)
			{
				sprintf_s(line2, "You defend");
				sprintf_s(line3, "Enemy defends");
				sprintf_s(line4, "Nothing happend");

				pickState = true;
			}
			//Player runs and enemy attacks
			else if (playerState == 3 && enemyState == 1)
			{
				sound.enemysound();
				bool runAway = battlesystem.checkRun(totalspeed, enemySpeed);

				if (runAway == TRUE)
				{
					sound.runsound();
					sprintf_s(line1, " ");
					sprintf_s(line2, " ");
					sprintf_s(line3, " ");
					sprintf_s(line4, " ");

					battlearena = false;
					reset2 = true;
					enemyFace = 0;
					player.health = 50;
				}
				else
				{
					sound.enemysound();
					int enemyDamage = battlesystem.attackDamage(enemyAttack, totaldefense);
					player.health = player.health - enemyDamage;

					if (player.health <= 0)
					{
						gameover = true;
					}
					else
					{
						sprintf_s(line2, "You couldn't run away");
						sprintf_s(line3, "Enemy attacks first, it dealt %d damage", enemyDamage);
						sprintf_s(line4, " ");

						pickState = TRUE;
					}
				}

			}
			//Player runs and enemy defends
			else if (playerState == 3 && enemyState == 2)
			{
				bool runAway = battlesystem.checkRun(totalspeed, enemySpeed);

				if (runAway == TRUE)
				{
					sound.runsound();

					sprintf_s(line1, " ");
					sprintf_s(line2, " ");
					sprintf_s(line3, " ");
					sprintf_s(line4, " ");

					battlearena = false;
					reset2 = true;
					enemyFace = 0;
					player.health = 50;
				}
				else
				{
					sound.enemysound();
					sprintf_s(line2, "You couldn't run away");
					sprintf_s(line3, "Enemy defends");
					sprintf_s(line4, "Nothing happend");

					pickState = true;
				}
			}
		}

		if (enemyDead == true)
		{
			if (enemyFace == 1)
			{
				bat.visibility = 0;
				bat.x = bat.y = 2000;
			}
			if (enemyFace == 2)
			{
				toadstool.visibility = 0;
				toadstool.x = toadstool.y = 2000;
			}
			if (enemyFace == 3)
			{
				wasp.visibility = 0;
				wasp.x = wasp.y = 2000;
			}
			
			enemyDead = false;
		}
	}

	if (bat.visibility == 0 && wasp.visibility == 0 && toadstool.visibility == 0)
	{
		crystal.x = 1025;
		crystal.y = 290;
		crystal.visibility = 100;
	}
};

void Game::Draw()
{
	if (battlearena == false)
	{
		render.Begin(bg);
		render.Draw(&wasp);
		render.Draw(&bat);
		render.Draw(&toadstool);
		render.Draw(&chest1);
		render.Draw(&chest2);
		render.Draw(&chest3);
		render.Draw(&chest4);
		render.Draw(&crystal);
		render.Draw(&player);
		al_draw_bitmap(banner, (A3 + render.xscroll), (A1 + render.yscroll), 0);
		al_draw_bitmap(Bplayer, (A3 + render.xscroll), (A1 + render.yscroll), 0);
		al_draw_bitmap(sword.shape, (A3 + render.xscroll + 30), (A1 + render.yscroll), 0);
		al_draw_bitmap(mace.shape, (A3 + render.xscroll + 60), (A1 + render.yscroll), 0);
		al_draw_bitmap(spear.shape, (A3 + render.xscroll + 90), (A1 + render.yscroll), 0);
		al_draw_bitmap(shield.shape, (A3 + render.xscroll + 120), (A1 + render.yscroll), 0);
		al_draw_text(font, al_map_rgb(255, 255, 255), (A3 + render.xscroll + 250), (A1 + render.yscroll + 10), 0, health);
		al_draw_text(font, al_map_rgb(255, 255, 255), (A3 + render.xscroll + 360), (A1 + render.yscroll + 10), 0, attack);
		al_draw_text(font, al_map_rgb(255, 255, 255), (A3 + render.xscroll + 470), (A1 + render.yscroll + 10), 0, speed);
		al_draw_text(font, al_map_rgb(255, 255, 255), (A3 + render.xscroll + 580), (A1 + render.yscroll + 10), 0, defense);
	}
	else if (battlearena == true)
	{
		render.Begin(bg);
		render.Draw(&player);
		if(enemyFace == 1)
		{
			render.Draw(&bat);
		}
		else if (enemyFace == 2)
		{
			render.Draw(&toadstool);
		}
		else if (enemyFace == 3)
		{
			render.Draw(&wasp);
		}
		render.Draw(&textbox);
		al_draw_text(font, al_map_rgb(0, 0, 0), 50, 380, 0, line1);
		al_draw_text(font, al_map_rgb(0, 0, 0), 50, 380, 0, line1);
		al_draw_text(font, al_map_rgb(0, 0, 0), 50, 420, 0, line2);
		al_draw_text(font, al_map_rgb(0, 0, 0), 50, 435, 0, line3);
		al_draw_text(font, al_map_rgb(0, 0, 0), 50, 450, 0, line4);
		al_draw_text(font, al_map_rgb(0, 0, 0), 400, 380, 0, playerHealthText);
		al_draw_text(font, al_map_rgb(0, 0, 0), 400, 395, 0, enemyHealthText);
	}

	render.End();
};

void Game::Run()
{
	Init();
	sound.titlemusic();
	while (!enter)
	{
		ALLEGRO_KEYBOARD_STATE key_state;
		al_get_keyboard_state(&key_state);

		al_draw_bitmap(titlescreen, 0, 0, 0);
		if (al_key_down(&key_state, ALLEGRO_KEY_ENTER))
		{
			sound.selectsound();
			enter = true;
		}

		render.End();
	}

	while (!select)
	{
		ALLEGRO_KEYBOARD_STATE key_state;
		al_get_keyboard_state(&key_state);

		al_draw_bitmap(charscreen, 0, 0, 0);
		if (al_key_down(&key_state, ALLEGRO_KEY_M))
		{
			sound.selectsound();
			sound.STOPtitle();
			sound.fieldmusic();
			player.male = true;
			select = true;
		}
		else if (al_key_down(&key_state, ALLEGRO_KEY_F))
		{
			sound.selectsound();
			sound.STOPtitle();
			sound.fieldmusic();
			player.male = false;
			select = true;
		}
		render.End();
	}

	Init();

	while (!quit)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER)
		{
			if (battlearena == true && reset == true)
			{
				sound.STOPfield();
				sound.battlemusic();
				Init();
				reset = false;
			}
			if (battlearena == false && reset2 == true)
			{
				sound.STOPbattle();
				sound.fieldmusic();
				Init();
				reset2 = false;
			}
			Update();
			Draw();

			while (gameover == true)
			{
				sound.STOPbattle();
				sound.gameovermusic();
				while (!enter)
				{
					bg = al_load_bitmap("Sprites/Gameover.png");
					ALLEGRO_KEYBOARD_STATE key_state;
					al_get_keyboard_state(&key_state);
					al_draw_bitmap(bg, 0, 0, 0);
					if (al_key_down(&key_state, ALLEGRO_KEY_ENTER))
					{
						quit = true;
						enter = true;
						gameover = false;
					}
					render.End();
				}
			}
			while (win == true)
			{
				sound.STOPfield();
				sound.winmusic();
				bg = al_load_bitmap("Sprites/win.png");
				while (!enter)
				{
					ALLEGRO_KEYBOARD_STATE key_state;
					al_get_keyboard_state(&key_state);
					al_draw_bitmap(bg, 0, 0, 0);
					if (al_key_down(&key_state, ALLEGRO_KEY_ENTER))
					{
						quit = true;
						enter = true;
						win = false;
					}
					render.End();
				}
			}
		}
	}
}

