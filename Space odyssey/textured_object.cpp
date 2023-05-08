#include "textured_object.h"

textured_object::textured_object(float X, float Y, bool Coll, ALLEGRO_BITMAP* Texture){
	x1 = X;
	y1 = Y;
	texture = Texture;
	x2 = X + al_get_bitmap_width(texture);
	y2 = Y + al_get_bitmap_height(texture);
	collisions = Coll;
	type = RECTANGLE;
	filled = true;
	color = al_map_rgba(0, 0, 0, 0);
}

textured_object::textured_object() {
	x1 = 0;
	y1 = 0;
	texture = 0;
	x2 = 0;
	y2 = 0;
	collisions = 0;
	type = RECTANGLE;
	filled = true;
	color = al_map_rgba(0, 0, 0, 0);
}

void textured_object::CreateTextured() {
	al_draw_bitmap(texture, x1, y1, 0);
	game_object::create();
}
