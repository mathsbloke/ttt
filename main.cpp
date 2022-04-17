#include "utils.h"

int main() {

    std::array<std::array<char, 3>, 3> gameBoard {
        {
            {'-', '-', '-'},
            {'-', '-', '-'},
            {'-', '-', '-'}
        }
    };

    std::cout << "Welcome to the game of tic-tac-toe" << std::endl;
    std::cout << "Enter '0' for row if you want to quit" << std::endl;
    std::cout << "X's turn" << std::endl;
    std::cout << "Current Game Board:" << std::endl;
    printGameBoard(gameBoard);

    int row {};
    int column {};
    bool invalidEntry;
    const int sentinel = 0;
    bool playerX {true};

    do {
        do {
            std::cout << "Enter Row: ";
            std::cin >> row;
            std::cout << "Enter Column: ";
            std::cin >> column;
            if (row > 3 || column > 3) {
                invalidEntry = true;
                std::cout << format("Please enter a value between 1 and 3") << std::endl;
            } else
                invalidEntry = false;
        } while (invalidEntry);


        if (row != sentinel) {
            updateGameBoard(gameBoard, row - 1, column - 1, playerX);
            checkGameBoard(gameBoard);
            printGameBoard(gameBoard);
        }
        if(playerX)
            playerX = false;
        else
            playerX = true;

    } while (row != sentinel);
    return 0;
}
