#include "Alien_ship.h"



int Alien_ship::attack;
int Alien_ship::rand;

Alien_ship::Alien_ship(int X, int Y, int xv, int yv, ALLEGRO_BITMAP* TEXTURE, int life, int Cooldown, Shot shot, int Difficulty, int Type, int xoffset) {
	x1 = X;
	y1 = Y;
	vx = xv;
	vy = yv;
	texture = TEXTURE;
	lifePoints = life;
	cooldown = Cooldown;
	shot_array = shot;
	shoot = true;
	difficulty = Difficulty;
	type = Type;
	xOffset = xoffset;
	movement = 0;
}

int Alien_ship::getmovement() {
	return movement;
}

void Alien_ship::start(bool center) {
	int mov;
	if (started) {
		mov = 10;
	}
	if (center) {
		if (started) {
			mov *= 2;
			movement = mov;
		}
		if(movement){
			y1 += vy;
			movement--;
			started = false;
		}
	}
	else {
		if (started) {
			movement = mov;
		}
		if(movement) {
			y1 =+ vy;
			movement--;
			started = false;
		}
	}
}

void Alien_ship::end(bool center) {
	int mov = 15;
	if (center) {
		mov *= 2;
		while (mov--) {
			y1 += vy;
		}
	}
	else {
		while (mov--) {
			y1 = +vy;
		}
	}
}

void Alien_ship::attackOne() {
	if (shoot) {
		shot_array.shot_add(x1 + xOffset, y1);
		shoot = false;
		}
	}

void Alien_ship::setshoot(bool v) {
	shoot = v;
}

void Alien_ship::setmovement(int v) {
	movement = v;
}

bool Alien_ship::getshoot() {
	return shoot;
}

void Alien_ship::moveleft(){
	if (movement) {
		x1++;
		movement--;
	}

}

void Alien_ship::moveright(){
	if (movement) {
		x1--;
		movement--;
	}
}

int Alien_ship::randomtestmovement() {

	int dir = Irand(0, 2);

	

	if (x1 >= 230) {
		movement = Irand(10, 80);
		colliding = true;
		return 1;
	}
	if (x1 <= 90) {
		movement = Irand(10, 80);
		colliding = true;
		return 0;
	}

	movement = Irand(10, 80);

	return dir;
}