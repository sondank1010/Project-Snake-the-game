#include <iostream>
#include <SDL.h>
#include <SDL_mixer.h>
#include "audio.h"

using namespace std;

void Sound::init() {
	if (SDL_Init(SDL_INIT_AUDIO) != 0) {
		cout << "Sound could not be initialized" << endl;
		SDL_GetError();

	}

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
		cout << "Sound could not be initialized" << endl;
		SDL_GetError();
	}


}

bool Sound::load(){
	bool success = true;

    Smusic = Mix_LoadMUS("music.wav");
    if (Smusic == NULL)
    {
        printf("Failed to load music! SDL_mixer Error: %s\n", Mix_GetError());
        success = false;
    }

   
    Seat = Mix_LoadWAV("eat.wav");
    if (Seat == NULL)
    {
        printf("Failed to load eat sound effect! SDL_mixer Error: %s\n", Mix_GetError());
        success = false;
    }

    Sdie = Mix_LoadWAV("die.wav");
    if (Sdie == NULL)
    {
        printf("Failed to load die sound effect! SDL_mixer Error: %s\n", Mix_GetError());
        success = false;
    }

    return success;
}

void Sound::music() {
	Mix_PlayMusic(Smusic, -1);
}

void Sound::eat() {
	Mix_PlayChannel(-1, Seat, 0);
}

void Sound::die() {
	Mix_PlayChannel(-1, Sdie, 0);
   
}

void Sound::stopMusic() {
	Mix_HaltMusic();
}

void Sound::close() {
	Mix_FreeChunk(Seat);
	Mix_FreeChunk(Sdie);
	Mix_FreeMusic(Smusic);
	Mix_Quit();

}
