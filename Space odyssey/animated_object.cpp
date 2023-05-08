#include "animated_object.h"


animated_object::animated_object(float X, float Y, float vX, float vY, float R, float R1, float Xs, float Ys, bool Coll, bool Filled, float Thickness, int Type, const char* Text, ALLEGRO_COLOR Color, ALLEGRO_FONT* Font, game_object Map) {
	x1 = X;
	y1 = Y;
	vx = vX;
	vy = vY;
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
	map = Map;
}
animated_object::animated_object() {
	x1 = 0;
	y1 = 0;
	vx = 0;
	vy = 0;
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

float animated_object::getxvelocity() { return vx; }
float animated_object::getyvelocity() { return vy; }

void animated_object::setxvelocity(float v) { vx = v; }
void animated_object::setyvelocity(float v) { vy = v; }

void animated_object::updategraphic() {
	x2 = x1 + width;
	y2 = y1 + height;
}

bool animated_object::checkmapcolliding() {
	if (x1 > map.get_x2() - (map.get_thickness() - 3)) {
		x1 = map.get_x2() - (map.get_thickness() - 4);
		x1 -= 2.f;
		return true;
	}
	if (x2 < map.get_x() + (map.get_thickness() - 3)) {
		x2 = map.get_x() + (map.get_thickness() - 4);
		x1 += 2.f;
		return true;
	}
	if (y1 > map.get_y2() - (map.get_thickness() - 3)) {
		y1 = map.get_y2() - (map.get_thickness() - 4);
		y1 -= 2.f;
		return true;
	}
	if (y2 < map.get_y() + (map.get_thickness() - 3)) {
		y2 = map.get_y() + (map.get_thickness() - 4);
		y1 += 2.f;
		return true;
	}
	return false;
}

void animated_object::UpdateMovement() {
	if (checkmapcolliding()) {
		vx *= -1;
		vy *= -1;
	}
	x1 += vx;
	y1 += vy;
}
