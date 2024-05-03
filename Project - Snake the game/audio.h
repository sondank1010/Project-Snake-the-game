#pragma once
#include <SDL_mixer.h>

struct Sound {
	Mix_Music* Smusic = NULL;
	Mix_Chunk* Seat = NULL;
	Mix_Chunk* Sdie = NULL;

	void init();
	bool load();
	void music();
	void eat();
	void die();
	void stopMusic();
	void close();


};