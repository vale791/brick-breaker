#include <iostream>

#include "RenderWindow.hpp"

RenderWindow::RenderWindow(const char* title, int width, int height):window(NULL), renderer(NULL) {
  window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);

  if (window == NULL)
    std::cout << __FILE__ << ": Window failed to init. ERROR: " << SDL_GetError() << '\n';

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

}

void RenderWindow::cleanUp() {
  SDL_DestroyWindow(window);
}

SDL_Texture* RenderWindow::loadTexture(char* filePath) {
  SDL_Texture* texture = NULL;
  texture = IMG_LoadTexture(renderer, filePath);

  if (texture == NULL)
    std::cout << __FILE__ << ": Failed to load texture. ERROR: " << SDL_GetError() << '\n';

  return texture;
}

void RenderWindow::render(Entity& entity) {
	SDL_Rect src;
	src.x = 0;
	src.y = 0;
	src.w = entity.getSize().x;
	src.h = entity.getSize().y;

	SDL_Rect dst;
	dst.x = entity.getPos().x;
	dst.y = entity.getPos().y;
	dst.w = entity.getSize().x;
	dst.h = entity.getSize().y;

	SDL_RenderCopy(renderer, entity.getTexture(), &src, &dst);
}

void RenderWindow::clear() { SDL_RenderClear(renderer); }

void RenderWindow::display() { SDL_RenderPresent(renderer); }

//SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
//SDL_RenderClear(renderer);

void RenderWindow::fill(int r, int g, int b, int a) {
	SDL_SetRenderDrawColor(renderer, r, g, b, a);
	SDL_RenderClear(renderer);
}