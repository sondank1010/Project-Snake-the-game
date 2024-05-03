#include "graphics.h"
#include "player.h"
#include "resolution.h"
#include "apple.h"
#include <SDL.h>
#include <SDL_image.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <SDL_ttf.h>
#include <string>
#include "audio.h"
using namespace std;

bool inside(int x, int y, SDL_Rect r) {
    return x > r.x && x < r.x + r.w && y > r.y && y < r.y + r.h;
}

bool overlap(const SDL_Rect& r1, const SDL_Rect& r2) {
    return inside(r1.x, r1.y, r2) || inside(r1.x + r1.w, r1.y, r2) ||
        inside(r1.x, r1.y + r1.h, r2) || inside(r1.x + r1.w, r1.y + r1.h, r2);
}

enum gameStatus {
    menu,
    playing,
    over
};

enum Direction
{
    DOWN,
    LEFT,
    RIGHT,
    UP
};


int main(int argc, char* argv[])
{
    
       Graphics graphics;
       graphics.init();

       SDL_Texture* background = graphics.loadTexture("background.jpg");
       SDL_Texture* menuBackground = graphics.loadTexture("menu.jpg");

       Sound sound;

      sound.init();
      sound.load();



       Player player;
       player.graphics = &graphics;
       player.draw();
       player.grow();

       Apple apple;
       apple.graphics = &graphics;
       apple.spawn();
       apple.draw();

       TTF_Init();
       TTF_Font* font = TTF_OpenFont("COMICSANS.TTF", 24);
       SDL_Color color = { 0, 0, 0 };

       graphics.presentScene();
       int score(0);

       int dir = 0;
       bool quit = false;
       SDL_Event event;
       cout << "Playing" << endl;

       sound.music();
       
       while (!quit)
           {

           
               SDL_RenderClear(graphics.renderer);
               graphics.renderTexture(background, 0, 0);


               SDL_Surface* scoreSurface = TTF_RenderText_Blended(font, ("Score: " + to_string(score)).c_str(), color);
               SDL_Texture* scoreTexture = SDL_CreateTextureFromSurface(graphics.renderer, scoreSurface);
               SDL_Rect scoreRect = { SCREEN_WIDTH / 2 - scoreSurface->w, 10,scoreSurface->w , scoreSurface->h };
               SDL_RenderCopy(graphics.renderer, scoreTexture, NULL, &scoreRect);

               SDL_FreeSurface(scoreSurface);
               SDL_DestroyTexture(scoreTexture);


               
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
               apple.draw();

               // Eat apple
               if (overlap(apple.apple, player.head))
               {
                   sound.eat();
                   score++;
                   apple.spawn();
                   player.grow();
                   player.speed += 0.3;
                   cout << score << endl;
               }

               bool wallCollision = player.WallCollision();
               bool selfCollision = player.selfCollision();
               if (wallCollision || selfCollision)
               {
                   sound.die();
                   sound.stopMusic();
                   cout << "Game Overs" << endl;
                   quit = true;
               }

               graphics.presentScene();
           }

           SDL_Delay(1000);
           SDL_DestroyTexture(background);
           graphics.quit();

           sound.close();

           TTF_CloseFont(font);
           TTF_Quit();
            
           return 0;
          
       
}
