#include "Shot.h"


Shot::Shot(float xv, float yv, float X, float Y, bool Alien, ALLEGRO_BITMAP* Texture2[2], ALLEGRO_SAMPLE* Audio, float YOffset, float XOffset) {
	vx = xv;
	vy = yv;
	x1 = X;
	y1 = Y;
	alien = Alien;
	type = RECTANGLE;
	frames = 0;
	time = 0;
	texture2[0] = Texture2[0];
	texture2[1] = Texture2[1];
	audio = Audio;
	yoffset = YOffset;
	xoffset = XOffset;
}

Shot::Shot() {
	vx = 0;
	vy = 0;
	x1 = 0;
	y1 = 0;
	alien = false;
	type = 0;
	frames = 0;
	time = 0;
	texture2[0] = 0;
	texture2[1] = 0;
	audio = 0;
	yoffset = 0;
	xoffset = 0;
}

void Shot::shot_add(float X, float Y){
	al_play_sample(audio, 0.3, 0, alien ? Frand(1.5, 1.6) : 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
	shots.push_back(Shot(vx, vy, X += xoffset, Y -= yoffset, alien, texture2, audio, yoffset, xoffset));
}

void Shot::shot_update() {
	for (int i = 0; i < shots.size(); i++) {
		if (shots[i].time > 100) {
			shots.erase(shots.begin() + i);
			continue;
		}
		if (shots[i].alien) {
			shots[i].x1 += vx;
			shots[i].y1 += vy;
		}
		else {
			shots[i].x1 -= vx;
			shots[i].y1 -= vy;
		}
		shots[i].frames += 1;
		shots[i].time += 1;
	}
}

void Shot::drawshots() {
	for (int i = 0; i < shots.size(); i++) {
		int frame_display = (shots[i].frames / 2) % 2;
		if (shots[i].alien) {
			ALLEGRO_COLOR tint =
				Irand(0, 1) ? al_map_rgb_f(1, 1, 1) : al_map_rgb_f(0.5, 0.5, 0.5);
			al_draw_tinted_bitmap(texture2[1], tint, shots[i].x1, shots[i].y1, 0);
}
		else {
			al_draw_bitmap(texture2[frame_display], shots[i].x1, shots[i].y1, 0);
			create();
		}
	}
}
