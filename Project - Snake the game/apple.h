#pragma once
#ifndef _APPLE__H
#define _APPLE__H
#include "graphics.h"
#include "player.h"

struct Apple{
	Graphics* graphics;
	std::vector<SDL_Rect> apple;
	void spawn();
};

#endif // !_APPLE__H

