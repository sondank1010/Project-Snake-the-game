#pragma once
#ifndef _APPLE__H
#define _APPLE__H
#include "graphics.h"
#include "player.h"

struct Apple{
	Graphics* graphics ;
	SDL_Rect apple = { 100, 100, 15, 15 };
	void spawn();
	void draw();
};

#endif // !_APPLE__H

