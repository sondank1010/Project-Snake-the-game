#ifndef _PLAYER__H
#define _PLAYER__H
#include "graphics.h"
#include "apple.h"
#include <vector>
using namespace std;


struct Player {
	Graphics* graphics;
	SDL_Rect head = { (SCREEN_WIDTH - 100) / 2, (SCREEN_HEIGHT - 100) / 2, 20, 20 };
	vector <SDL_Rect>  tail;
	int size = 2;
	


	void move(const int dir);
	void grow();
	bool WallCollision();
	bool selfCollision();
	void draw();
	
};

#endif
