#pragma once

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <iostream>
#include "enums.cpp"

class game_object
{
protected:
	float width;
	float height;
	float x1;
	float y1;
	float x2;
	float y2;
	float x3;
	float y3;
	float r;
	float r1;
	bool collisions;
	bool filled;
	float thickness;
	const char* text;
	int type;
	ALLEGRO_COLOR color;
	ALLEGRO_FONT* font;
public:
	game_object(float X, float Y, float R, float R1, float Xs, float Ys, bool Coll, bool Filled, float Thickness, int Type, const char* Text, ALLEGRO_COLOR Color, ALLEGRO_FONT* Font);
	game_object();

	float get_width();
	float get_height();
	float get_thickness();
	float get_x();
	float get_y();
	float get_x2();
	float get_y2();
	bool can_collide();
	int get_type();
	ALLEGRO_FONT* get_font();

	void set_width(float v);
	void set_height(float v);
	void set_thickness(float v);
	void set_x(float v);
	void set_y(float v);
	void set_collide(bool v);
	void set_type(int v);
	void set_color(ALLEGRO_COLOR v);
	void set_font(ALLEGRO_FONT* v);

	//draw object to screen
	void create();

	//is colliding
	bool collide(game_object obj2);
};

