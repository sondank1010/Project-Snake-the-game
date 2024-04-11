#ifndef _GRAPHICS__H
#define _GRAPHICS__H

#include <SDL.h>
#include <SDL_image.h>
#include "resolution.h"

struct Graphics {
	SDL_Renderer* renderer = NULL;
	SDL_Window* window = NULL;

	void logErrorAndExit(const char* msg, const char* error);

	bool init();
	
		
	void presentScene();
	
	
	SDL_Texture* loadTexture(const char* filename);
	
	void renderTexture(SDL_Texture* texture, int x, int y);
	
	void blitRect(SDL_Texture* texture, SDL_Rect* src, int x, int y);
	

	void quit();

	
};
#endif



