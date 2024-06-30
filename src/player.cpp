#include "Player.hpp"

const Uint8* keystates = SDL_GetKeyboardState(NULL);

Player::Player(Vector2 position, Vector2 texture_size, SDL_Texture* tex): Entity(position, texture_size, tex) {
  std::cout << "Player Object Created" << '\n';
}

void Player::update() {
  if (keystates[SDL_SCANCODE_A] || keystates[SDL_SCANCODE_LEFT]) {
    pos.x -= 3;
  }
  if (keystates[SDL_SCANCODE_D] || keystates[SDL_SCANCODE_RIGHT]) {
    pos.x += 3;
  }
}