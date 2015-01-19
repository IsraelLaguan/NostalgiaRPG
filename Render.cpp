#include "Render.h"

extern ALLEGRO_FONT *font;

Render::Render()
{
	Init();
}


Render::~Render()
{
}


void Render::Init()
{
	xscroll = 0;
	yscroll = -480;
}

void Render::Begin(ALLEGRO_BITMAP* bg)
{
	al_draw_bitmap(bg, xscroll, yscroll, 0);
}
void Render::Draw(GameObject* a)
{
	if (a->visibility != 0)
	{
		int x = a->x + xscroll;
		int y = a->y + yscroll;
		al_draw_bitmap(a->shape, x, y, 0);
	}
}
void Render::End()
{
	al_flip_display();
}