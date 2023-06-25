#pragma once
#include "animated_textured.h"
#include "Shot.h"
#include "game.h"


class player_object : public animated_textured
{
private:
	bool running;
	Shot* shipshot;
	bool isShooting;
	//to do
public:


	player_object(float X, float Y, bool Coll, ALLEGRO_BITMAP* Texture, float Vy, float Vx, game_object Map, Shot* shot);
	player_object();

	bool IsShooting();
	void SetShooting(bool v);

	void TakeKeyboardInput();
};

