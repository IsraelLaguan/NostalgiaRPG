#include "Sound.h"

//Sound class takes care of all audio related duties, loading and playing samples, creating caches, and destroying them afterwards.
Sound::Sound()
{
	al_reserve_samples(11);

	title = al_load_sample("Music/Intro.wav");
	if (!title){
		printf("Title not loaded!\n");
		exit(0);
	}
	field = al_load_sample("Music/Field.wav");
	if (!field){
		printf("Field not loaded!\n");
		exit(0);
	}
	battle = al_load_sample("Music/Battle.wav");
	if (!battle){
		printf("Battle not loaded!\n");
		exit(0);
	}
	gameover = al_load_sample("Music/Gameover.wav");
	if (!gameover){
		printf("Gameover not loaded!\n");
		exit(0);
	}
	win = al_load_sample("Music/Win.wav");
	if (!win){
		printf("Win not loaded!\n");
		exit(0);
	}
	select = al_load_sample("Music/Menu.wav");
	if (!select){
		printf("Select not loaded!\n");
		exit(0);
	} 
	equip = al_load_sample("Music/Equip.wav");
	if (!equip){
		printf("Equip not loaded!\n");
		exit(0);
	}
	chest = al_load_sample("Music/Chest.wav");
	if (!chest){
		printf("Chest not loaded!\n");
		exit(0);
	}
	attack = al_load_sample("Music/Sword.ogg");
	if (!attack){
		printf("Attack not loaded!\n");
		exit(0);
	}
	weak = al_load_sample("Music/Unarmed.ogg");
	if (!weak){
		printf("Weak Attack not loaded!\n");
		exit(0);
	}
	enemy = al_load_sample("Music/Enemy.ogg");
	if (!enemy){
		printf("Enemy not loaded!\n");
		exit(0);
	}
	run = al_load_sample("Music/Run.ogg");
	if (!run){
		printf("Run not loaded!\n");
		exit(0);
	}
}


Sound::~Sound()
{
	al_destroy_sample(select);
	al_destroy_sample(equip);
	al_destroy_sample(attack);
	al_destroy_sample(enemy);
	al_destroy_sample(chest);
	al_destroy_sample(weak);
	al_destroy_sample(run);
}

void Sound::titlemusic()
{
	al_play_sample(title, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
}

void Sound::fieldmusic()
{
	field = al_load_sample("Music/Field.wav");
	if (!field){
		printf("Music not loaded!\n");
		exit(0);
	}
	al_play_sample(field, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
}

void Sound::battlemusic()
{
	battle = al_load_sample("Music/Battle.wav");
	if (!battle){
		printf("Music not loaded!\n");
		exit(0);
	}
	al_play_sample(battle, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
}

void Sound::STOPfield()
{
	al_destroy_sample(field);
}

void Sound::STOPtitle()
{
	al_destroy_sample(title);
}

void Sound::STOPbattle()
{
	al_destroy_sample(battle);
}

void Sound::gameovermusic()
{
	al_play_sample(gameover, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
}

void Sound::winmusic()
{
	al_play_sample(win, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
}

void Sound::selectsound()
{
	al_play_sample(select, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
}

void Sound::chestsound()
{
	al_play_sample(chest, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
}

void Sound::weaponsound()
{
	al_play_sample(equip, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
}

void Sound::attacksound()
{
	al_play_sample(attack, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
}

void Sound::enemysound()
{
	al_play_sample(enemy, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
}

void Sound::weaksound()
{
	al_play_sample(weak, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
}

void Sound::runsound()
{
	al_play_sample(run, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
}


