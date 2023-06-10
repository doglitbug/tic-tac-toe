#include <cstring>
#include "board.h"

board::board() {
    resetBoard();
    currentTurn = X;
}

void board::resetBoard() {
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; ++i) {
        mBoard[i] = EMPTY;
    }
}

bool board::checkWinner(PIECE player) {
    for (int line = 0; line < WINNING_LINES; line++) {
        if (mBoard[winningLines[line][0]] == mBoard[winningLines[line][1]] &&
            mBoard[winningLines[line][1]] == mBoard[winningLines[line][2]] &&
            mBoard[winningLines[line][2]] == player) {
            return true;
        }
    }

    return false;
}

PIECE board::checkBoard(int position) {
    return mBoard[position];
}

void board::setBoard(int position, PIECE player) {
    mBoard[position] = player;
}
