#include "Entity.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

Entity::Entity(Vector2 position, Vector2 texture_size, SDL_Texture* tex) :pos(position), size(texture_size), texture(tex) {
  std::cout << "Entity Created" << '\n';
}

SDL_Texture* Entity::getTexture() { return texture; }
