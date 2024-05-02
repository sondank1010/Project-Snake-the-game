#include <iostream>

#include <SDL.h>

#include <SDL_image.h>

#include <vector>

#include "player.h"

void Player::move(const int dir) {
    enum Direction {
        DOWN,
        LEFT,
        RIGHT,
        UP
    };

    int prevX = head.x;
    int prevY = head.y;

    switch (dir) {
    case DOWN:
        head.y += speed;

        break;

    case UP:
        head.y -= speed;

        break;

    case LEFT:
        head.x -= speed;

        break;
    case RIGHT:
        head.x += speed;

        break;
    }

    if (!tail.empty()) {
        for (int i = 0; i < tail.size() - 1; ++i) {
            tail[i] = tail[i + 1];
        }
        tail[tail.size() - 1] = {
          prevX,
          prevY,
          20,
          20
        };
    }

}

bool Player::WallCollision() {

    int playerX = head.x;
    int playerY = head.y;

    if (playerX < 0 || playerX >= SCREEN_WIDTH - 20 || playerY < 0 || playerY >= SCREEN_HEIGHT - 20) {
        return true;
    }

    return false;
}

bool Player::selfCollision() {

    for (int i = tail.size() - 1; i > 0; --i) {
        if (head.x == tail[i].x && head.y == tail[i].y) {
            return true;
        }
    }
    return false;
}
void Player::grow() {
    SDL_Rect newSegment = {
      head.x,
      head.y,
      20,
      20
    };
    tail.insert(tail.begin(), newSegment);

}

void Player::draw() {

    SDL_SetRenderDrawColor(graphics->renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(graphics->renderer, &head);

    SDL_SetRenderDrawColor(graphics->renderer, 0, 255, 0, 255);
    for (int i = 0; i < tail.size(); ++i) {
        SDL_RenderFillRect(graphics->renderer, &tail[i]);
    }
    SDL_Delay(25);
}