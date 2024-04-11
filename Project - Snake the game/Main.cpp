#include "graphics.h"
#include "player.h"
#include "resolution.h"
#include <SDL.h>
#include <SDL_image.h>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

enum Direction
{
    DOWN,
    LEFT,
    RIGHT,
    UP
};

int
main(int argc, char* argv[])
{
    Graphics graphics;
    graphics.init();

    SDL_Texture* background = graphics.loadTexture("background.jpg");

    SDL_Texture* border = graphics.loadTexture("borderwall.png");

    Player player;
    player.graphics = &graphics;
    graphics.renderTexture(background, 0, 0);
    graphics.renderTexture(border, 0, 0);
    player.draw();
    graphics.presentScene();

    int dir = 0;
    bool quit = false;
    SDL_Event event;


    while (!quit)
    {
        SDL_RenderClear(graphics.renderer);
        graphics.renderTexture(background, 0, 0);
        graphics.renderTexture(border, 0, 0);

      while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                exit(0);
            }
            if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_ESCAPE)
                {
                    exit(0);
                }
            }
            if (event.key.keysym.sym == SDLK_DOWN)
            {
                dir = DOWN;
            }
            if (event.key.keysym.sym == SDLK_UP)
            {
                dir = UP;
            }
            if (event.key.keysym.sym == SDLK_RIGHT)
            {
                dir = RIGHT;
            }
            if (event.key.keysym.sym == SDLK_LEFT)
            {
                dir = LEFT;
            }
        }

        player.move(dir);
        player.draw();
        graphics.presentScene();
    }

    SDL_DestroyTexture(border);
    SDL_DestroyTexture(background);

    graphics.quit();

    return 0;
}
