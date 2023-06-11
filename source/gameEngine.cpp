#include "gameEngine.h"

gameEngine::gameEngine() {

}

int gameEngine::init() {
    ///We dont want to init unused or missing subsystems such as CD-ROM
    SDL_Init(SDL_INIT_VIDEO);
    //Create window
    mWindow = SDL_CreateWindow("Tic Tac Toe", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                               SCREEN_HEIGHT,
                               SDL_WINDOW_SHOWN);
    //Create surface for window
    mScreenSurface = SDL_GetWindowSurface(mWindow);

    mBoard = new board();
    mQuit = false;

    return 0;
}

gameEngine::~gameEngine() {
    delete mBoard;
    SDL_DestroyWindow(mWindow);
    mWindow = nullptr;
    SDL_Quit();
}

void gameEngine::drawBoard() {
    for (int y = 0; y < BOARD_SIZE; ++y) {
        for (int x = 0; x < BOARD_SIZE; ++x) {
            switch (mBoard->getBoardPosition(x + y * BOARD_SIZE)) {
                case EMPTY: {
                    std::cout << " . ";
                    break;
                }
                case X: {
                    std::cout << " X ";
                    break;
                }
                case O: {
                    std::cout << " O ";
                    break;
                }
                default: {
                    break;
                }
            }

        }
        std::cout << std::endl;
    }

    //Apply the image
    //SDL_BlitSurface( gXOut, NULL, mScreenSurface, NULL );

    //Update the surface
    SDL_UpdateWindowSurface( mWindow );
}

void gameEngine::doEvents() {
    SDL_Event e;

    while( SDL_PollEvent( &e ) != 0 )
    {
        //User requests quit
        if( e.type == SDL_QUIT )
        {
            mQuit = true;
        }
    }
}