#pragma once
#include "animated_object.h"
class animated_textured : public animated_object
{
protected:
	ALLEGRO_BITMAP* texture;
public:
	animated_textured(float X, float Y, bool Coll, ALLEGRO_BITMAP* Texture, float Vy, float Vx, game_object Map);
	animated_textured();

	void updategraphic();


	void CreateTextured();
};

