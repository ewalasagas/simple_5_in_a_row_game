#include "GBoard.hpp"
#include <iostream>

int main()
{
    GBoard game;
    int turn_count = 1;
    int row;
    int column;
    char player;
    game.printBoard();
    while (game.getGameState() == GameState::UNFINISHED)
    {
        if (turn_count % 2)
        {
            player = 'x';
        } else {
            player = 'o';
        }
        std::cout << player << "'s Turn.\nrow: ";
        std::cin >> row;
        std::cout << "column: ";
        std::cin >> column;
        if (game.makeMove(row,column,player))
        {
            turn_count++;
            game.printBoard();
        }
    }
    return 0;
}
