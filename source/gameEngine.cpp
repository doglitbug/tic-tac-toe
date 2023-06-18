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
            destination.x = x * 150 + 25;
            destination.y = y * 150 + 25;
            destination.h = destination.w = 100;

            switch (mBoard->getBoardPosition(x + y * BOARD_SIZE)) {
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
        switch (e.type) {
            case SDL_MOUSEBUTTONDOWN:
                processClick((int) e.button.x, (int) e.button.y);
                break;
            case SDL_QUIT:
                mQuit = true;
                break;
        }
    }

    drawBoard();
}

void gameEngine::processClick(int x, int y) {
    x /= CELL_WIDTH;
    y /= CELL_WIDTH;
    int cellNumber = y * 3 + x;

    if (mBoard->checkEmpty(cellNumber)) {
        mBoard->setBoardPosition(cellNumber, mBoard->currentTurn);
        //Check for winner
        if (mBoard->checkWinner(mBoard->currentTurn)) {
            std::cout << "Winner " << std::endl;
        }

        //Flip player turn
        if (mBoard->currentTurn == X) {
            mBoard->currentTurn = O;
        } else {
            mBoard->currentTurn = X;
        }
    }
}

gameEngine::~gameEngine() {
    delete mBoard;
    SDL_DestroyWindow(mWindow);
    mWindow = nullptr;
    SDL_Quit();
}