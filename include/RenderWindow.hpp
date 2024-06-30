#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Entity.hpp"

class RenderWindow {
public:
	RenderWindow(const char* title, int width, int height);
	SDL_Texture* loadTexture(char* filePath);
	void fill(int r, int g, int b, int a);
	void cleanUp();
	void clear();
	void render(Entity& entity);
	void display();
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
};