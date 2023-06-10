#include "gameEngine.h"

gameEngine::gameEngine() {
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
            switch (mBoard->mBoard[x + y * BOARD_SIZE]) {
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
}

void gameEngine::input() {
    mBoard->setBoard(0, X);
    mBoard->setBoard(3, O);
    mBoard->setBoard(1, X);

}
