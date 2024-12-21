//#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
//#include <SDL2/SDL_image.h>
//include <SDL_timer.h>
#include <iostream>

const int WIDTH = 64;
const int HEIGHT = 32;
const int SCALE = 20;

class Window {
public:
	Window(int width, int height, int scale) {
		SDL_Window* window = SDL_CreateWindow("chip8",
									SDL_WINDOWPOS_CENTERED,
									SDL_WINDOWPOS_CENTERED,
									WIDTH*SCALE, HEIGHT*SCALE, 0);

		//SDL_Renderer* renderer = SDL_CreateRenderer()
	}

	~Window() {

	}

	void update(void const* buffer) {

	}

};

/**
 * The main function is only used to test the SDL library
 */
int main(int argc, char *argv[])
{
	// returns zero on success else non-zero
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		printf("error initializing SDL: %s\n", SDL_GetError());
	}
	SDL_Window* window = SDL_CreateWindow("chip8",
									SDL_WINDOWPOS_CENTERED,
									SDL_WINDOWPOS_CENTERED,
									WIDTH*SCALE, HEIGHT*SCALE, 0);

	SDL_Event windowEvent;

	while (true) {
		if (SDL_PollEvent(&windowEvent)) {
			if (windowEvent.type == SDL_QUIT) {
				break;
			}
		}
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
