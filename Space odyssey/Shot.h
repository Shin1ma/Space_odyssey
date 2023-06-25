#pragma once

#include <iostream>
#include <vector>
#include <allegro5/allegro_audio.h>
#include "utils.cpp"
#include "animated_textured.h"


class Shot : public animated_textured
{
private:
	bool alien;
	float yoffset;
	float xoffset;
	int time;
	long frames;
	ALLEGRO_BITMAP* texture2[2];
	ALLEGRO_SAMPLE* audio;
	static std::vector<Shot> shots;

public:


	Shot(float vx, float vy, float X, float Y, bool Alien, ALLEGRO_BITMAP* Texture2[2], ALLEGRO_SAMPLE* Audio, float YOffset, float XOffset);
	Shot();
	void shot_add(float X, float Y);
	void shot_update();
	void drawshots();

};

