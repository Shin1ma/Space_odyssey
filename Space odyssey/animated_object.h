#pragma once
#include "game_object.h"
class animated_object : public game_object
{
protected:
	float vx;
	float vy;
	game_object map;
public:
	animated_object(float X, float Y, float vX, float vY, float R, float R1, float Xs, float Ys, bool Coll, bool Filled, float Thickness, int Type, const char* Text, ALLEGRO_COLOR Color, ALLEGRO_FONT* Font, game_object Map);
	animated_object();

	void updategraphic();

	float getxvelocity();
	float getyvelocity();

	void setxvelocity(float v);
	void setyvelocity(float v);

	bool checkmapcolliding();

	void UpdateMovement();
};

