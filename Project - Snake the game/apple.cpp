#include <iostream>

#include <SDL.h>

#include <SDL_image.h>

#include <cstdlib>

#include <ctime>

#include "apple.h"

int main() {
	srand(time(NULL));
	return 0;
}

void Apple::spawn() {

	apple.x = rand() % (SCREEN_WIDTH - apple.w);
	apple.y = rand() % (SCREEN_HEIGHT - apple.h);

}

void Apple::draw() {
	SDL_SetRenderDrawColor(graphics->renderer, 15, 0, 400, 255);
	SDL_RenderFillRect(graphics->renderer, &apple);

}