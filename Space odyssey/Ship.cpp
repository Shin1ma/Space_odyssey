#include "Ship.h"

Ship::Ship(int X, int Y, int xv, int yv, ALLEGRO_BITMAP* TEXTURE, int life, int Cooldown, Shot shot) {
	x1 = X;
	y1 = Y;
	vx = xv;
	vy = yv;
	texture = TEXTURE;
	lifePoints = life;
	cooldown = Cooldown;
	shot_array = shot;
}

Ship::Ship() {
	x1 = 0;
	y1 = 0;
	vx = 0;
	vy = 0;
	texture = 0;
	lifePoints = 0;
	cooldown = 0;
}