#pragma once
#include "Ship.h"
#include <Windows.h>

class Alien_ship : public Ship
{
private:
	int difficulty;
	int type;
	static int attack;
	static int rand;
	bool shoot;
	bool started = true;
	
	int xOffset;
	int movement;
public:
	bool colliding = false;


	Alien_ship(int X, int Y, int xv, int yv, ALLEGRO_BITMAP* texture, int life, int Cooldown, Shot shot, int Difficulty, int Type, int xoffset);


	bool getshoot();
	int getmovement();

	void start(bool center);
	void end(bool center);
	void setshoot(bool v);
	void setmovement(int v);

	int randomtestmovement();

	void moveleft();
	void moveright();

	void attackOne();
	void attackTwo();
	void attackThree();


};

