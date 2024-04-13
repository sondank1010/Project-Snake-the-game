#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "apple.h"
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


bool Player::WallCollision() {
    
    int playerX = head.x;
    int playerY = head.y;
    

    if (playerX < 0 || playerX >= SCREEN_WIDTH - 20 || playerY  < 0 || playerY >= SCREEN_HEIGHT - 20) {
		return true;
	}

    

    return false; 
}

  




void Player::draw() {

    SDL_SetRenderDrawColor(graphics->renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(graphics->renderer, &head);
    SDL_Delay(25);
}