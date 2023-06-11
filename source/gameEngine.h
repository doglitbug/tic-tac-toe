#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "board.h"
#include <iostream>
#include <SDL2/SDL.h>

#define SCREEN_WIDTH 450
#define SCREEN_HEIGHT 450
#define CELL_WIDTH 150

class gameEngine {
public:
    gameEngine();
    ~gameEngine();
    int init();
    void drawBoard();
    bool quit() { return mQuit; }

    void doEvents();

private:
    board *mBoard;
    SDL_Window *mWindow;
    SDL_Surface *mScreenSurface;
    bool mQuit;
};

#endif
