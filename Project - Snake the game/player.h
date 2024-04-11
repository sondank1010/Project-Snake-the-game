#ifndef _PLAYER__H
#define _PLAYER__H
#include "graphics.h"
#include <vector>


struct Player {
	Graphics* graphics;
	SDL_Rect head = { 100, 100, 20, 20 };
	std::vector <SDL_Rect>  tail;

	void move(const int dir);
	void draw();

};

#endif
