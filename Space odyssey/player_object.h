#pragma once
#include "animated_textured.h"
#include "game.h"


class player_object : public animated_textured
{
private:
	bool running;
	//to do
public:
	player_object(float X, float Y, bool Coll, ALLEGRO_BITMAP* Texture, float Vy, float Vx, game_object Map);
	player_object();

	void TakeKeyboardInput();
};

