#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <vector>
#include "game.h"
#include "game_object.h"
#include "animated_object.h"
#include "textured_object.h"
#include "animated_textured.h"
#include "player_object.h"
#include "utils.cpp"
#include "sprites.cpp"

#define BUFFER_W 320
#define BUFFER_H 240

#define DISP_SCALE 2
#define DISP_W (BUFFER_W * DISP_SCALE)
#define DISP_H (BUFFER_H * DISP_SCALE)


bool is_shoting = false;
long unsigned int time_roll = 0;
unsigned int to_wait_in_ms = 0;
game Game(0, 0, 0, 0, 0, 0);
//std::vector<Shot> Shot::shots;

int main()
{
	try {
		Game.AllegroInit(DISP_W, DISP_H, BUFFER_W, BUFFER_H);
		sprites_init();
	}
	catch (const std::runtime_error& exc) {
		std::cout << exc.what();
		return 1;
	}

	bool redraw = true;
	bool closed = false;
	bool running = false;
	ALLEGRO_EVENT event;
	game_object map(0, 0, 0, 0, 320, 240, true, false, 30, RECTANGLE, 0, al_map_rgba(0, 0, 0, 0), 0);
	player_object player(160, 120, true, sprites.ship, 2.f, 2.f, map);
	//Shot shipshot(0.f, 3.f, 0, 0, false, sprites.ship_shot, sample_shot, SHIP_SHOT_H, SHIP_SHOT_W);

	al_start_timer(Game.get_timer());
	while (true) {

		/*		if (time_roll * 30 > to_wait_in_ms && is_shoting) {
					is_shoting = false;
					to_wait_in_ms = 0;
					time_roll = 0;
				}
				*/
		al_wait_for_event(Game.get_queue(), &event);
		switch (event.type)
		{
		case ALLEGRO_EVENT_TIMER: {
			Game.ResetKeys();
			player.TakeKeyboardInput();
			player.updategraphic();
			Game.UpdateGame();
			redraw = true;
			break;
		}
		case ALLEGRO_EVENT_KEY_DOWN: {
			Game.SetKey(false, event.keyboard.keycode);
			break;
		}
		case ALLEGRO_EVENT_KEY_UP: {
			Game.SetKey(true, event.keyboard.keycode);
			break;
		}
		case ALLEGRO_EVENT_DISPLAY_CLOSE: {
			closed = true;
			break;
		}
		}
		if (closed) {
			return 0;
		}

		player.TakeKeyboardInput();



		Game.disp_pre_draw();
		if (redraw && al_is_event_queue_empty(Game.get_queue()))
		{
			al_clear_to_color(al_map_rgb(0, 0, 0));
			map.create();
			player.CreateTextured();
			//shipshot.drawshots();

			al_flip_display();

			redraw = false;
		}
		Game.disp_post_draw(DISP_W, DISP_H, BUFFER_W, BUFFER_H);
	}


	sprites_deinit();
	Game.Allegro_destroy();
    return 0;
}
