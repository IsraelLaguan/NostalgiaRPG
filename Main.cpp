#define FPS 15

#include <stdio.h>
#include "allegro5/allegro.h"
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h> 
#include <allegro5/allegro_ttf.h>

#include "GameObject.h"
#include "Game.h"

ALLEGRO_DISPLAY* display = NULL;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_TIMER *timer = NULL;
ALLEGRO_FONT *font;

void InitAllegro(int W, int H)
{
	printf("Nostalgia RPG\n\nControls:\nArrow keys to move\nSpacebar to interact with chests\nNumber keys (1-4) to switch weapon\nEscape to exit game\nEnter to progress through title/end screens\n\n");

	if (!al_init())
	{
		printf("Failed to initialize allegro!\n");
	}

	if (!al_init_image_addon())
	{
		printf("Failed to initialize image addon!\n");
	}

	display = al_create_display(W, H);
	if (!display)
	{
		printf("Failed to create display!\n");
		exit(0);
	}

	if (!al_install_keyboard())
	{
		printf("Failed to install keyboard!\n");
		exit(0);
	}

	timer = al_create_timer(1.0 / FPS);
	if (!timer) {
		printf("Failed to create timer!\n");
		al_destroy_display(display);
		exit(0);
	}

	event_queue = al_create_event_queue();
	if (!event_queue) {
		printf("Failed to create event_queue!\n");
		al_destroy_display(display);
		al_destroy_timer(timer);
		exit(0);
	}

	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_start_timer(timer);

	al_init_font_addon(); 
	al_init_ttf_addon();

	font = al_load_ttf_font("arial.ttf", 12, 0);
	if (!font)
	{
		printf("Failed to create font!\n");
		al_destroy_display(display);
		al_destroy_timer(timer);
		exit(0);
	}

	if (!al_install_mouse())
	{
		printf("Failed to install mouse!\n");
		exit(0);
	}

	//Installing sound components
	if (!al_install_audio())
	{
		fprintf(stderr, "Allegro failed to initialize audio! D;\n");
		exit(0);
	}

	//Initializing audio codecs
	if (!al_init_acodec_addon()){
		fprintf(stderr, "Allegro failed to initialize audio codecs! D;\n");
		exit(0);
	}

	//Sample reserves
	if (!al_reserve_samples(20)){
		fprintf(stderr, "Allegro failed to reserve samples! D;\n");
		exit(0);
	}

}

void EndAllegro()
{
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
}

void main()
{
	int sw = 640;
	int sh = 480;
	InitAllegro(sw, sh);

	Game game;
	game.event_queue = event_queue; 

	game.Run();

	EndAllegro();
}
