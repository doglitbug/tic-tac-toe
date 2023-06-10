#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "board.h"
#include <iostream>
#include <SDL2/SDL.h>

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768

class gameEngine {
public:
    gameEngine();
    ~gameEngine();
    void drawBoard();
    bool quit() { return mQuit; }

    void input();

private:
    board *mBoard;
    SDL_Window *mWindow;
    SDL_Surface *mScreenSurface;
    bool mQuit;
};

#endif
