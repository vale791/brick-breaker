#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Vector2.hpp"

class Entity {
public:
  Entity(Vector2 position, Vector2 size, SDL_Texture* tex);
  Vector2& getPos() { return pos; }
  Vector2& getSize() { return size; }
  SDL_Texture* getTexture();
  Vector2 pos;
private:
  Vector2 size;
  SDL_Texture* texture;
};
