#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Entity.hpp"

class Player : public Entity {
public:
  Player(Vector2 position, Vector2 size, SDL_Texture* tex);
  void update();
  // More functions will probably come as the game progresses.
};