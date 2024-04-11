#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

#include "player.h"

void Player::move(const int dir) {
    enum Direction
    {
        DOWN,
        LEFT,
        RIGHT,
        UP
    };
    switch (dir)
    {
    case DOWN:
        head.y += 5;

        break;

    case UP:
        head.y -= 5;

        break;

    case LEFT:
        head.x -= 5;

        break;
    case RIGHT:
        head.x += 5;

        break;
    }
}

void Player::draw() {

    SDL_SetRenderDrawColor(graphics->renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(graphics->renderer, &head);
    SDL_Delay(25);
}