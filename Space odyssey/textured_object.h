#pragma once
#include "game_object.h"
class textured_object : public game_object
{
private:
	ALLEGRO_BITMAP* texture;
public:
	textured_object(float X, float Y, bool Coll, ALLEGRO_BITMAP* Texture);
	textured_object();

	void CreateTextured();
};

