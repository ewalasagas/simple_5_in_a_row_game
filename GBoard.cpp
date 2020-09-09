#include "GBoard.hpp"
#include <iostream>

GBoard::GBoard()
{
    gameState = GameState::UNFINISHED;
    for (int i = 0; i < BOARDSIZE; ++i)
    {
        for (int j = 0; j < BOARDSIZE; ++j)
        {
            board[i][j] = '.';
        }
    }
}

GameState GBoard::getGameState()
{
    return gameState;
}

void GBoard::printBoard()
{
    std::cout << "   0  1  2  3  4  5  6  7  8  9  10 11 12 13 14\n";
    for (int i = 0; i < BOARDSIZE; ++i)
    {
        std::cout << i << " ";
        if (i < 10)
        {
            std::cout << ' ';
        }

        for (int j = 0; j < BOARDSIZE; ++j)
        {
            std::cout << board[i][j] << "  ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

bool GBoard::makeMove(int row, int column, char player)
{
    if (gameState != GameState::UNFINISHED)
    {
        std::cout << "Move not allowed: game is done!" << std::endl;
        return false;
    }

    if (row < 0 || row > BOARDSIZE || column < 0 || column > BOARDSIZE)
    {
        std::cout << "Move not allowed: not on board." << std::endl;
        return false;
    }

    if (!(player == 'x' || player == 'o'))
    {
        std::cout << "Move not allowed: invalid player." << std::endl;
        return false;
    }

    if (board[row][column] != '.')
    {
        std::cout << "Move not allowed: non-empty position." << std::endl;
        return false;
    }

    // this is a legal move, apply to the board.
    board[row][column] = player;

    // check for column win

    int columnscore = -1;

    for (int c = column; c < BOARDSIZE; ++c)
    {
        if (board[row][c] == player)
        {
            columnscore++;
        }
        else
        {
            break;
        }
    }

    for (int c = column; c >= 0; --c)
    {
        if (board[row][c] == player)
        {
            columnscore++;
        }
        else
        {
            break;
        }
    }

    if (columnscore >= 5)
    {
        if (player == 'x')
        {
            gameState = GameState::X_WON;
            std::cout << "X Wins!" << std::endl;
            return true;
        }
        if (player == 'o')
        {
            gameState = GameState::O_WON;
            std::cout << "O Wins!" << std::endl;
            return true;
        }
    }

    // check for row win.

    int rowscore = -1;

    for (int r = row; r < BOARDSIZE; ++r)
    {
        if (board[r][column] == player)
        {
            rowscore++;
        }
        else
        {
            break;
        }
    }

    for (int r = row; r >= 0; --r)
    {
        if (board[r][column] == player)
        {
            rowscore++;
        }
        else
        {
            break;
        }
    }

    if (rowscore >= 5)
    {
        if (player == 'x')
        {
            gameState = GameState::X_WON;
            std::cout << "X Wins!" << std::endl;
            return true;
        }
        if (player == 'o')
        {
            gameState = GameState::O_WON;
            std::cout << "O Wins!" << std::endl;
            return true;
        }
    }

    // check for ascending diagonal win.

    int ascdiagscore = -1;

    for (int i = 0; i < 5; ++i)
    {
        int c = column + i;
        int r = row - i;
        if (r > 0 || r < BOARDSIZE || c > 0 || c < BOARDSIZE)
        {
            if (board[r][c] == player)
            {
                ascdiagscore++;
            }
            else
            {
                break;
            }
        }
    }

    for (int i = 0; i < 5; ++i)
    {
        int c = column - i;
        int r = row + i;
        if (r > 0 || r < BOARDSIZE || c > 0 || c < BOARDSIZE)
        {
            if (board[r][c] == player)
            {
                ascdiagscore++;
            }
            else
            {
                break;
            }
        }
    }

    if (ascdiagscore >= 5)
    {
        if (player == 'x')
        {
            gameState = GameState::X_WON;
            std::cout << "X Wins!" << std::endl;
            return true;
        }
        if (player == 'o')
        {
            gameState = GameState::O_WON;
            std::cout << "O Wins!" << std::endl;
            return true;
        }
    }

    // check for descending diagonal win.

    int descdiagscore = -1;

    for (int i = 0; i < 5; ++i)
    {
        int c = column + i;
        int r = row + i;
        if (r > 0 || r < BOARDSIZE || c > 0 || c < BOARDSIZE)
        {
            if (board[r][c] == player)
            {
                descdiagscore++;
            }
            else
            {
                break;
            }
        }
    }

    for (int i = 0; i < 5; ++i)
    {
        int c = column - i;
        int r = row - i;
        if (r > 0 || r < BOARDSIZE || c > 0 || c < BOARDSIZE)
        {
            if (board[r][c] == player)
            {
                descdiagscore++;
            }
            else
            {
                break;
            }
        }
    }

    if (descdiagscore >= 5)
    {
        if (player == 'x')
        {
            gameState = GameState::X_WON;
            std::cout << "X Wins!" << std::endl;
            return true;
        }
        if (player == 'o')
        {
            gameState = GameState::O_WON;
            std::cout << "O Wins!" << std::endl;
            return true;
        }
    }

    // is every space taken? cats game.
    for (int i = 0; i < BOARDSIZE; ++i)
    {
        for (int j = 0; j < BOARDSIZE; ++j)
        {
            if (board[i][j] == '.')
            {
                return true;
            }
        }
    }
    std::cout << "No more moves: Cat's Game!" << std::endl;
    gameState = GameState::DRAW;
    return true;

}
