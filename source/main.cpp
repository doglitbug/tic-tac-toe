#include "gameEngine.h"

int main(int argc, char *args[]) {
    gameEngine *mGameEngine = new gameEngine();
    int result = mGameEngine->init();
    if (result != 0) {
        return result;
    }

    while (!mGameEngine->quit()) {
        mGameEngine->tick();
    }

    delete mGameEngine;
    return 0;
}