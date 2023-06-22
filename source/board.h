#ifndef BOARD_H
#define BOARD_H

enum PIECE {
    EMPTY = 0, X, O, DRAW
};
const int BOARD_SIZE = 3;
const int WINNING_LINES = 8;

class board {
public:
    board();
    void resetBoard();
    PIECE getBoardPosition(int position) { return mBoard[position]; }
    void setBoardPosition(int position, PIECE piece) { mBoard[position] = piece; }
    bool checkEmpty(int position) { return mBoard[position] == EMPTY; }
    bool checkWinner(PIECE player);
    PIECE currentTurn;
    int moveNumber;

private:
    PIECE mBoard[BOARD_SIZE * BOARD_SIZE];
    const int winningLines[WINNING_LINES][BOARD_SIZE] = {
            {0, 1, 2},
            {3, 4, 5},
            {6, 7, 8},
            {0, 3, 6},
            {1, 4, 7},
            {2, 5, 8},
            {0, 4, 8},
            {2, 4, 6}
    };
};

#endif