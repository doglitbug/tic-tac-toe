#include <iostream>
#include <SDL2/SDL.h>

SDL_Window *g_pWindow = 0;
SDL_Renderer *g_pRenderer = 0;

int main(int argc, char *args[]) {
    if (SDL_Init(SDL_INIT_EVERYTHING) > 0) {
        std::cout << "Could not init SDL" << std::endl;
        return 1;
    }

    // Create a window
    g_pWindow = SDL_CreateWindow("Tic Tac Toe",
                                 SDL_WINDOWPOS_CENTERED,
                                 SDL_WINDOWPOS_CENTERED,
                                 600,
                                 600,
                                 SDL_WINDOW_SHOWN);
    if (g_pWindow == 0) {
        std::cout << "Could not create window" << std::endl;
        return 1;
    }

    // Create a renderer
    g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);

    if (g_pRenderer == 0) {
        std::cout << "Could not create renderer" << std::endl;
        return 1;
    }

    SDL_SetRenderDrawColor(g_pRenderer, 128, 128, 128, 255);
    SDL_RenderClear(g_pRenderer);
    SDL_RenderPresent(g_pRenderer);

    SDL_Delay(5000);

    return 0;
}