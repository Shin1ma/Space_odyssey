#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <iostream>
#define KEY_SEEN	1
#define KEY_RELEASED 2

class game
{
private:
	long score;
	static bool closed;
	ALLEGRO_TIMER* timer;
	ALLEGRO_EVENT_QUEUE* queue;
	ALLEGRO_DISPLAY* display;
	ALLEGRO_BITMAP* buffer;
	ALLEGRO_FONT* font;
	static unsigned char key[ALLEGRO_KEY_MAX];


public:
	game(long Score, ALLEGRO_TIMER* Timer, ALLEGRO_DISPLAY* Display, ALLEGRO_BITMAP* Buffer, ALLEGRO_FONT* Font, ALLEGRO_EVENT_QUEUE* Queue);
	game();

	long get_score();
	ALLEGRO_TIMER* get_timer();
	ALLEGRO_EVENT_QUEUE* get_queue();
	ALLEGRO_DISPLAY* get_display();
	ALLEGRO_BITMAP* get_buffer();
	ALLEGRO_FONT* get_font();
	bool is_closed();

	void set_score(long v);
	void set_timer(ALLEGRO_TIMER* v);
	void set_queue(ALLEGRO_EVENT_QUEUE* v);
	void set_display(ALLEGRO_DISPLAY* v);
	void set_buffer(ALLEGRO_BITMAP* v);
	void set_font(ALLEGRO_FONT* v);
	void set_closed(bool v);

	//initializes Allegro
	void AllegroInit(int dWidth, int dHeight, int bWidth, int bHeight);

	void DisplayInit(int dWidth, int dHeight, int bWidth, int bHeight);

	//resets keys array
	static void ResetKeys();

	//has key been pressed, kc KeyCode
	static bool GetKeyStatus(int kc);

	static void SetKey(bool Released, int kc);

	//main state chain
	void UpdateGame();

	//buffer drawing mechanics
	void disp_pre_draw();
	void disp_post_draw(int dWidth, int dHeight, int bWidth, int bHeight);


	//destructor
	void Allegro_destroy();
};

