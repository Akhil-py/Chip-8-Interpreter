#include <SDL2/SDL.h>
#include <iostream>

class Window {
public:
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Texture* texture;

	Window(const int width, const int height) {
		SDL_Init(SDL_INIT_VIDEO);
		
		window = SDL_CreateWindow("chip8", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);

		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

		texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, width, height);
	}

	~Window() {
		SDL_DestroyTexture(texture);
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
	}

	void update(void const* buffer) {

	}

};


/**
 * The main function is only used to test the SDL library
 */
int main(int argc, char *argv[])
{
	const int WIDTH = 64;
	const int HEIGHT = 32;
	const int SCALE = 20;
	
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
