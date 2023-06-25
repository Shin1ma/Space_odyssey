#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <vector>
#include "enums.cpp"
#include "game.h"
#include "game_object.h"
#include "animated_object.h"
#include "textured_object.h"
#include "animated_textured.h"
#include "player_object.h"
#include "Shot.h"
#include "Alien_ship.h"
#include "sprites.cpp"
#include "audio.cpp"



#define BUFFER_W 320
#define BUFFER_H 240

#define DISP_SCALE 2
#define DISP_W (BUFFER_W * DISP_SCALE)
#define DISP_H (BUFFER_H * DISP_SCALE)


bool is_shoting = false;
long unsigned int time_roll = 0;
unsigned int to_wait_in_ms = 0;
game Game(0, 0, 0, 0, 0, 0);
std::vector<Shot> Shot::shots;

int main()
{
	try {
		Game.AllegroInit(DISP_W, DISP_H, BUFFER_W, BUFFER_H);
		sprites_init();
		audio_init();
	}
	catch (const std::runtime_error& exc) {
		std::cout << exc.what();
		return 1;
	}

	bool moved = false;
	bool movementest = false;
	bool redraw = true;
	bool started = false;
	long time_in_frms = 15;
	long time_in_frm_al = 10;
	bool closed = false;
	bool running = false;
	bool setmovement = false;
	int settedmovement = 0;
	int rand;


	ALLEGRO_EVENT event;
	game_object map(0, 0, 0, 0, 320, 240, true, false, 30, RECTANGLE, 0, al_map_rgba(0, 0, 0, 0), 0);
	Shot shipshot(0.f, 3.f, 0, 0, false, sprites.ship_shot, sample_shot, SHIP_SHOT_H, SHIP_SHOT_W);
	player_object player(160, 120, true, sprites.ship, 2.f, 2.f, map, &shipshot);
	Shot alienshots(0.f, 3.f, 0, 0, true, sprites.ship_shot, sample_shot, -1 * SHIP_SHOT_H, SHIP_SHOT_W);
	Alien_ship alien(190, 0, 0.f, 3.f, sprites.alien[0], 20, 250, alienshots, 0, 1, ALIEN_BUG_W / 2.5);

	al_start_timer(Game.get_timer());
	while (true) {

		
		al_wait_for_event(Game.get_queue(), &event);
		switch (event.type)
		{
		case ALLEGRO_EVENT_TIMER: {
			if (!started) {
				Game.set_event(NPCSTART);
				started = true;
			}
			// PLACEHOLDER FOR TESTING PURPOSES
			Game.set_npc(LONE);

			if (setmovement) {
				alien.setmovement(settedmovement);
				setmovement = false;
				settedmovement = 0;
			}
			
			if (movementest) {
				rand = alien.randomtestmovement();
				if (rand) {
					Game.set_event(NPCRIGHT);
				}
				else{
					Game.set_event(NPCLEFT);
				}
				movementest = false;
				rand = 0;

			}

			if (player.IsShooting()) {
				time_in_frms--;
			}
			if (time_in_frms <= 0) {
				player.SetShooting(false);
				time_in_frms = 15;
			}

			if (!(alien.getshoot())) {
				time_in_frm_al--;
			}
			if (time_in_frm_al <= 0) {
				alien.setshoot(true);
				time_in_frm_al = 10;
			}

			

			Game.ResetKeys();
			player.TakeKeyboardInput();
			alienshots.shot_update();
			shipshot.shot_update();
			player.updategraphic();
			alien.attackOne();
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

		switch (Game.get_event())
		{
		case NPCLEFT: {
			switch (Game.get_npc()) {
			case LONE:
					alien.moveleft();

				if (!(alien.getmovement())) {
					movementest = true;
					Game.ClearEvent();
					Game.Clearnpc();
				}
				break;

			case LTWO:
				Game.ClearEvent();
				Game.Clearnpc();
				break;

			case LTHREE:
				Game.ClearEvent();
				Game.Clearnpc();
				break;
			}
			break;
		}

		case NPCRIGHT: {
			switch (Game.get_npc()) {
			case LONE:
					alien.moveright();

				if (!(alien.getmovement())) {
					movementest = true;
					Game.ClearEvent();
					Game.Clearnpc();
				}
				break;

			case LTWO:
				Game.ClearEvent();
				Game.Clearnpc();
				break;

			case LTHREE:
				Game.ClearEvent();
				Game.Clearnpc();
				break;
			}
			break;
		}

		case NPCSHOOT: {
			switch (Game.get_npc()) {
			case LONE:
				Game.ClearEvent();
				Game.Clearnpc();
				break;

			case LTWO:
				Game.ClearEvent();
				Game.Clearnpc();
				break;

			case LTHREE:
				Game.ClearEvent();
				Game.Clearnpc();
				break;
			}
			break;
		}

		case NPCSTART: {
			switch (Game.get_npc()) {
			case LONE:
				alien.start(true);
				if (!(alien.getmovement())) {
					movementest = true;
					Game.ClearEvent();
					Game.Clearnpc();
				}
				break;

			case LTWO:
				break;

			case LTHREE:

				break;
			}
			break;
		}

		default:
			Game.ClearEvent();
			Game.Clearnpc();
			break;
		}


		player.TakeKeyboardInput();



		Game.disp_pre_draw();
		if (redraw && al_is_event_queue_empty(Game.get_queue()))
		{
			al_clear_to_color(al_map_rgb(0, 0, 0));
			map.create();
			shipshot.drawshots();
			alienshots.drawshots();
			player.CreateTextured();
			alien.CreateTextured();
			

			al_flip_display();

			redraw = false;
		}
		Game.disp_post_draw(DISP_W, DISP_H, BUFFER_W, BUFFER_H);
	}

	audio_deinit();
	sprites_deinit();
	Game.Allegro_destroy();
    return 0;
}
