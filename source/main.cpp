#include "gameEngine.h"

int main(int argc, char *args[]) {
    gameEngine *mGameEngine = new gameEngine();
    if (mGameEngine == nullptr) {
        return -1;
    }

    //while (mGameEngine->quit() == false) {
    //mGameEngine->drawBoard();
    mGameEngine->input();
    mGameEngine->drawBoard();
    //}

    delete mGameEngine;
    return 0;
}