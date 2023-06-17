#include "gameEngine.h"

gameEngine::gameEngine() {}

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

    //Load images
    image_X = IMG_Load("../images/X.png");
    image_O = IMG_Load("../images/O.png");
    image_board = IMG_Load("../images/board.png");

    return 0;
}

void gameEngine::drawBoard() {
    //Clear board
    SDL_BlitSurface(image_board, NULL, mScreenSurface, NULL);

    for (int y = 0; y < BOARD_SIZE; ++y) {
        for (int x = 0; x < BOARD_SIZE; ++x) {
            //Generate position
            SDL_Rect destination;
            destination.x = x * 150 + 50;
            destination.y = y * 150 + 50;
            destination.h = destination.w = 100;

            switch (mBoard->getBoardPosition(x + y * BOARD_SIZE)) {
                case EMPTY: {
                    break;
                }
                case X: {
                    SDL_BlitSurface(image_X, NULL, mScreenSurface, &destination);
                    break;
                }
                case O: {
                    SDL_BlitSurface(image_O, NULL, mScreenSurface, &destination);
                    break;
                }
                default: {
                    break;
                }
            }

        }
    }

    //Update the surface
    SDL_UpdateWindowSurface(mWindow);
}

void gameEngine::tick() {
    SDL_Event e;

    while (SDL_PollEvent(&e) != 0) {
        //User requests quit
        if (e.type == SDL_QUIT) {
            mQuit = true;
        }
    }

    drawBoard();
}

gameEngine::~gameEngine() {
    delete mBoard;
    SDL_DestroyWindow(mWindow);
    mWindow = nullptr;
    SDL_Quit();
}