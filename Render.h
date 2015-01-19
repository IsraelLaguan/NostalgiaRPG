#include <stdio.h>
#include "allegro5/allegro.h"
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>

#include "GameObject.h"

#pragma once

class Render
{
public:
	Render(void);
	~Render(void);

	int xscroll;
	int yscroll;

	void Draw(GameObject* a);
	void Begin(ALLEGRO_BITMAP* bg);
	void End();
	void Init();
	void Map();
	void BattleScreen();
};

