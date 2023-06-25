#pragma once
#include "animated_textured.h"
#include "Shot.h"
#include "game.h"

class Ship : public animated_textured
{
protected:
	int lifePoints;
	Shot shot_array;
	long cooldown;

public:
	Ship(int X, int Y, int xv, int yv, ALLEGRO_BITMAP* texture, int life, int Cooldown, Shot shot);
	Ship();

	void onHit();

	void onDeath();


};

