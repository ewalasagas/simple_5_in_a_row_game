#ifndef GBOARD_HPP
#define GBOARD_HPP

#define BOARDSIZE 15

enum GameState
{
    X_WON,
    O_WON,
    DRAW,
    UNFINISHED
};

class GBoard
{
private:
    char board[BOARDSIZE][BOARDSIZE];
    GameState gameState;

public:
    GBoard();

    GameState getGameState();
    bool makeMove(int,int,char);
    
    void printBoard();
};

#endif
