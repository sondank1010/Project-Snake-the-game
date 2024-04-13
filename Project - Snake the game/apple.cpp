#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

#include "apple.h"

void Apple::spawn() {
	apple.x = rand() % (SCREEN_WIDTH - 20);
	apple.y = rand() % (SCREEN_HEIGHT - 20);
	
}

void Apple::draw() {
	SDL_SetRenderDrawColor(graphics->renderer, 0, 60, 255, 255);
	SDL_RenderFillRect(graphics->renderer, &apple);
	
}

bool Apple::eaten() {
	if ( player->head.x == apple.x && player->head.y == apple.y) {
		return true; 
	}
	return false; 
}
