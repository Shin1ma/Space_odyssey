#include "game_object.h"

game_object::game_object(float X, float Y, float R, float R1, float Xs, float Ys, bool Coll, bool Filled, float Thickness, int Type, const char* Text, ALLEGRO_COLOR Color, ALLEGRO_FONT* Font) {
	x1 = X;
	y1 = Y;
	thickness = Thickness;
	width = Xs; 
	height = Ys;
	x2 = x1 + width;
	y2 = y1 + height;
	x3 = x1 + (width / 2);
	y3 = y2;
	r = R;
	r1 = R1;
	collisions = Coll;
	filled = Filled;
	type = Type;
	text = Text;
	color = Color;
	font = Font;
}
game_object::game_object() {
	x1 = 0;
	y1 = 0;
	thickness = 0;
	height = 0;
	width = 0;
	x2 = 0;
	y2 = 0;
	x3 = 0;
	y3 = 0;
	r = 0;
	r1 = 0;
	collisions = false;
	filled = false;
	type = 0;
	text = 0;
	color = al_map_rgb(0, 0, 0);
	font = 0;
}

float game_object::get_width() { return width; }
float game_object::get_height() { return height; }
float game_object::get_thickness() { return thickness; }
float game_object::get_x() { return x1; }
float game_object::get_y() { return y1; }
float game_object::get_x2() { return x2; }
float game_object::get_y2() { return y2; }
bool game_object::can_collide() { return collisions; }
int game_object::get_type() { return type; }
ALLEGRO_FONT* game_object::get_font() { return font; }

void game_object::set_width(float v) { width = v; }
void game_object::set_height(float v) { height = v; }
void game_object::set_thickness(float v) { thickness = v; }
void game_object::set_x(float v) { x1 = v; }
void game_object::set_y(float v) { y1 = v; }
void game_object::set_collide(bool v) { collisions = v; }
void game_object::set_type(int v) { type = v; }
void game_object::set_color(ALLEGRO_COLOR v) { color = v; }
void game_object::set_font(ALLEGRO_FONT* v) { font = v; }


void game_object::create() {
	if (filled) {
		switch (type) {
		case RECTANGLE: {
			al_draw_filled_rectangle(x1, y1, x2, y2, color);
			break;
		}
		case LINE: {
			al_draw_line(x1, y1, x2, y2, color, thickness);
			break;
		}
		case TRIANGLE: {
			al_draw_filled_triangle(x1, y1, x2, y2, x3, y3, color);
			break;
		}
		case TEXT: {
			al_draw_text(font, color, x1, y1, 0, text);
			break;
		}
		case CIRCLE: {
			al_draw_filled_circle(x1, y1, r, color);
			break;
		}
		case ELLIPSE: {
			al_draw_filled_ellipse(x1, y1, r, r1, color);
			break;
		}
		}
	}
	else {
		switch (type) {
		case RECTANGLE: {
			al_draw_rectangle(x1, y1, x2, y2, color, thickness);
			break;
		}
		case LINE: {
			al_draw_line(x1, y1, x2, y2, color, thickness);
			break;
		}
		case TRIANGLE: {
			al_draw_triangle(x1, y1, x2, y2, x3, y3, color, thickness);
			break;
		}
		case TEXT: {
			al_draw_text(font, color, x1, y1, 0, text);
			break;
		}
		case CIRCLE: {
			al_draw_circle(x1, y1, r, color, thickness);
			break;
		}
		case ELLIPSE: {
			al_draw_ellipse(x1, y1, r, r1, color, thickness);
			break;
		}
		}
	}
}


bool game_object::collide(game_object obj2) {
	if (x1 > obj2.get_x2()) return false;
	if (x2 < obj2.get_x()) return false;
	if (y1 > obj2.get_y2()) return false;
	if (y2 < obj2.get_y()) return false;

	return true;
}
