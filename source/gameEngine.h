#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "board.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define SCREEN_WIDTH 450
#define SCREEN_HEIGHT 450
#define CELL_WIDTH 150

class gameEngine {
public:
    gameEngine();
    ~gameEngine();
    int init();
    void drawBoard();
    PIECE processClick(int x, int y);
    bool quit() { return mQuit; }

    void tick();

private:
    board *mBoard;
    SDL_Window *mWindow;
    SDL_Surface *mScreenSurface;
    bool mQuit;
    SDL_Surface* image_X;
    SDL_Surface* image_O;
    SDL_Surface* image_board;
};

#endif
