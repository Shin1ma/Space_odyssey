#include "game.h"


unsigned char game::key[ALLEGRO_KEY_MAX];
bool game::closed = false;

game::game(long Score, ALLEGRO_TIMER* Timer, ALLEGRO_DISPLAY* Display, ALLEGRO_BITMAP* Buffer, ALLEGRO_FONT* Font, ALLEGRO_EVENT_QUEUE* Queue) {
	score = Score;
	timer = Timer;
	display = Display;
	buffer = Buffer;
	font = Font;
	queue = Queue;
	memset(key, 0, ALLEGRO_KEY_MAX);
}
game::game() {
	score = 0;
	timer = 0;
	display = 0;
	buffer = 0;
	font = 0;
	queue = 0;
}

long game::get_score() { return score; }
ALLEGRO_TIMER* game::get_timer() { return timer; }
ALLEGRO_EVENT_QUEUE* game::get_queue() { return queue; }
ALLEGRO_DISPLAY* game::get_display() { return display; }
ALLEGRO_BITMAP* game::get_buffer() { return buffer; }
ALLEGRO_FONT* game::get_font() { return font; }
bool game::is_closed() { return closed; }

void game::set_score(long v) { score = v; }
void game::set_timer(ALLEGRO_TIMER* v) { timer = v; }
void game::set_queue(ALLEGRO_EVENT_QUEUE* v) { queue = v; }
void game::set_display(ALLEGRO_DISPLAY* v) { display = v; }
void game::set_buffer(ALLEGRO_BITMAP* v) { buffer = v; }
void game::set_font(ALLEGRO_FONT* v) { font = v; }
void game::set_closed(bool v) { closed = v; }


void game::AllegroInit(int dWidth, int dHeight, int bWidth, int bHeight) {
	if (!al_init()) throw std::runtime_error("allegro init failed");
	if (!al_install_keyboard()) throw std::runtime_error("keyboard install failed");
	if (!al_init_primitives_addon()) throw std::runtime_error("primitives install failed");
	timer = al_create_timer(1.0 / 30.0);
	queue = al_create_event_queue();
	font = al_create_builtin_font();
	DisplayInit(dWidth, dHeight, bWidth, bHeight);
	if (!timer) throw std::runtime_error("timer init failed");
	if (!queue) throw std::runtime_error("queue init failed");
	if (!display) throw std::runtime_error("display init failed");
	if (!buffer) throw std::runtime_error("buffer init failed");
	if (!font) throw std::runtime_error("font init failed");
	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_display_event_source(display));
	al_register_event_source(queue, al_get_timer_event_source(timer));
}

void game::DisplayInit(int dWidth, int dHeight, int bWidth, int bHeight) {
	al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_SUGGEST);
	al_set_new_display_option(ALLEGRO_SAMPLES, 8, ALLEGRO_SUGGEST);
	al_set_new_display_flags(ALLEGRO_RESIZABLE);

	display = al_create_display(dWidth, dHeight);

	buffer = al_create_bitmap(bWidth, bHeight);
}

//buffer drawing mechanics
void game::disp_pre_draw() {
	al_set_target_bitmap(buffer);
}
void game::disp_post_draw(int dWidth, int dHeight, int bWidth, int bHeight) {
	al_set_target_backbuffer(display);
	al_draw_scaled_bitmap(buffer, 0, 0, bWidth, bHeight, 0, 0, dWidth, dHeight, 0);

	al_flip_display();
}

void game::ResetKeys() {
	for (int i = 0; i < ALLEGRO_KEY_MAX; i++) {
		key[i] &= KEY_SEEN;
	}
}

bool game::GetKeyStatus(int kc) {
	if (key[kc]) {
		return true;
	}
	else { return false; }
}

void game::SetKey(bool Released, int kc) {
	if (!Released) {
		key[kc] = KEY_SEEN | KEY_RELEASED;
	}
	else {
		key[kc] &= KEY_RELEASED;
	}
}

//main state chain
void game::UpdateGame() {

	if (GetKeyStatus(ALLEGRO_KEY_ESCAPE)) {
		closed = true;
	}
}

//destructor
void game::Allegro_destroy() {
	al_destroy_bitmap(buffer);
	al_destroy_display(display);
	al_destroy_timer(timer);
	al_destroy_event_queue(queue);
	al_destroy_font(font);
}
