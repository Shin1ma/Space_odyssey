#include <allegro5/allegro.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_audio.h>
#include <iostream>

ALLEGRO_SAMPLE* sample_shot;
ALLEGRO_SAMPLE* sample_explode[2];

void audio_init()
{
    al_install_audio();
    al_init_acodec_addon();
    al_reserve_samples(128);

    sample_shot = al_load_sample("audio_shot.flac");
    if (!(sample_shot)) { 
        throw std::runtime_error("audio sample shot failed"); }

    sample_explode[0] = al_load_sample("audio_explode1.flac");
    if (!(sample_explode[0])) { throw std::runtime_error("audio sample explode 1 failed"); }
    sample_explode[1] = al_load_sample("audio_explode2.flac");
    if (!(sample_explode[1])) { throw std::runtime_error("audio sample explode 2 failed"); }
}

void audio_deinit()
{
    al_destroy_sample(sample_shot);
    al_destroy_sample(sample_explode[0]);
    al_destroy_sample(sample_explode[1]);
}