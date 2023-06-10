#ifndef BOARD_H
#define BOARD_H

enum PIECE {
    EMPTY = 0, X, O
};
const int BOARD_SIZE = 3;
const int WINNING_LINES = 8;

class board {
public:
    board();

    void resetBoard();

    bool checkWinner(PIECE player);

    PIECE checkBoard(int position);

    void setBoard(int position, PIECE player);

    friend class gameEngine;

private:
    PIECE mBoard[BOARD_SIZE * BOARD_SIZE];
    PIECE currentTurn;
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