#include "animated_textured.h"


animated_textured::animated_textured(float X, float Y, bool Coll, ALLEGRO_BITMAP* Texture, float Vy, float Vx, game_object Map) {
	x1 = X;
	y1 = Y;
	texture = Texture;
	x2 = X + al_get_bitmap_width(texture);
	y2 = Y + al_get_bitmap_height(texture);
	collisions = Coll;
	type = RECTANGLE;
	filled = true;
	color = al_map_rgba(0, 0, 0, 0);
	vx = Vx;
	vy = Vy;
	map = Map;
}

animated_textured::animated_textured() {
	x1 = 0;
	y1 = 0;
	texture = 0;
	x2 = 0;
	y2 = 0;
	collisions = 0;
	type = RECTANGLE;
	filled = true;
	color = al_map_rgba(0, 0, 0, 0);
	vy = 0;
	vx = 0;
}

void animated_textured::updategraphic() {
	x2 = x1 + al_get_bitmap_width(texture);
	y2 = y1 + al_get_bitmap_height(texture);
}

void animated_textured::CreateTextured() {
	al_draw_bitmap(texture, x1, y1, 0);
	game_object::create();
}
