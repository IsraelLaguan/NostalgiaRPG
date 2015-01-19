#include <stdio.h>
#include "allegro5/allegro.h"
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

#pragma once

class Sound
{
public:
	ALLEGRO_SAMPLE *title = NULL;
	ALLEGRO_SAMPLE *field = NULL;
	ALLEGRO_SAMPLE *battle = NULL;
	ALLEGRO_SAMPLE *gameover = NULL;
	ALLEGRO_SAMPLE *win = NULL;
	ALLEGRO_SAMPLE *select = NULL;
	ALLEGRO_SAMPLE *equip = NULL;
	ALLEGRO_SAMPLE *chest = NULL;
	ALLEGRO_SAMPLE *attack = NULL;
	ALLEGRO_SAMPLE *weak = NULL;
	ALLEGRO_SAMPLE *enemy = NULL;
	ALLEGRO_SAMPLE *run = NULL;

	Sound();
	~Sound();


	void titlemusic();
	void fieldmusic();
	void battlemusic();
	void STOPtitle();
	void STOPfield();
	void STOPbattle();
	void selectsound();
	void winmusic();
	void gameovermusic();
	void weaponsound();
	void attacksound();
	void enemysound();
	void chestsound();
	void weaksound();
	void runsound();
};

