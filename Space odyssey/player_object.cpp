#include "player_object.h"


player_object::player_object(float X, float Y, bool Coll, ALLEGRO_BITMAP* Texture, float Vy, float Vx, game_object Map, Shot* shot) {
	x1 = X;
	y1 = Y;
	texture = Texture;
	x2 = X + al_get_bitmap_width(texture);
	y2 = Y + al_get_bitmap_height(texture);
	collisions = Coll;
	type = RECTANGLE;
	filled = true;
	running = false;
	color = al_map_rgba(0, 0, 0, 0);
	vx = Vx;
	vy = Vy;
	map = Map;
	shipshot = shot;
	isShooting = false;
}

player_object::player_object() {
	x1 = 0;
	y1 = 0;
	texture = 0;
	x2 = 0;
	y2 = 0;
	collisions = 0;
	type = RECTANGLE;
	filled = true;
	running = false;
	color = al_map_rgba(0, 0, 0, 0);
	vy = 0;
	vx = 0;
	shipshot = NULL;
	isShooting = false;
}

bool player_object::IsShooting() {
	return isShooting;
}
void player_object::SetShooting(bool v) {
	isShooting = v;
}


void player_object::TakeKeyboardInput() {
	bool colliding = checkmapcolliding();
	if (game::GetKeyStatus(ALLEGRO_KEY_LSHIFT) && !(running)) {
		vy = 4.f;
		vx = 4.f;
		running = true;
	}
	else {
		vy = 2.f;
		vx = 2.f;
	}
	if (!(colliding)) {
		if (game::GetKeyStatus(ALLEGRO_KEY_UP)) {
			y1 -= vy;
		}
		if (game::GetKeyStatus(ALLEGRO_KEY_DOWN)) {
			y1 += vy;
		}
		if (game::GetKeyStatus(ALLEGRO_KEY_LEFT)) {
			x1 -= vx;
		}
		if (game::GetKeyStatus(ALLEGRO_KEY_RIGHT)) {
			x1 += vx;
		}
	}

	if (game::GetKeyStatus(ALLEGRO_KEY_SPACE)) {
		if (isShooting != true) {
			shipshot->shot_add(x1, y1);
			isShooting = true;
		}
	}

	if (running) {
		running = false;
	}
}