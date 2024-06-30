#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

#define FPS_INTERVAL 1.0

#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "Vector2.hpp"
#include "Player.hpp"

const char* gameTitle = "Brick Breaker";
const int windowWidth = 800;
const int windowHeight = 400;
bool gameRunning = true;

Uint32 fps_lasttime = SDL_GetTicks(); //the last recorded time.
Uint32 fps_current; //the current FPS.
Uint32 fps_frames = 0; //frames passed since the last recorded fps.

int WinMain() {

  std::vector<Entity> Bricks;

  if (SDL_Init(SDL_INIT_VIDEO) > 0) {
		std::cout << __FILE__ << ": SDL2 couldn't initialize, SDL2 ERROR: " << SDL_GetError() << '\n';
	} else {
		std::cout << __FILE__ << ": SDL2 has successfully initialized." << '\n';
	}

	if (!(IMG_Init(IMG_INIT_PNG))) {
		std::cout << __FILE__ << ": SDL2_IMAGE couldn't initialize, SDL2_IMAGE ERROR: " << SDL_GetError() << '\n';
	} else {
		std::cout << __FILE__ << ": SDL2_IMAGE has successfully initialized." << '\n';
	}

  RenderWindow window(gameTitle, windowWidth, windowHeight);

  SDL_Texture* plr_texture = window.loadTexture("C:\\Users\\Itamar\\Documents\\Programming\\C++\\SDL2\\Brick Breaker\\res\\gfx\\paddle.png");

  Player plr(Vector2(50, 350), Vector2(150, 20), plr_texture);

  SDL_Event event;

  while (gameRunning) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT)
        gameRunning = false;
      plr.update();
    }

    window.clear();
    window.fill(255, 255, 255, 255);
    window.render(plr);
    window.display();

  }
  window.cleanUp();
  SDL_Quit();

  return 0;
}