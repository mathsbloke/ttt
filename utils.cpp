#include "utils.h"
//
// Created by Bob McDermott on 14/04/2022.
//
std::string checkDiagonal2(std::array<std::array<char, 3>, 3> gameBoard) {
    int diagonalValue2 {};
    std::string resultMsg {};

    for (int row = 0, col = 2; row < 3; ++row, --col) {
        diagonalValue2 += gameBoard[row][col];
    }
    if(diagonalValue2 == O_value)
        resultMsg = "'O' wins this one!";
    else if(diagonalValue2 == X_value)
        resultMsg = "'X' wins this one!";
    return resultMsg;
}

std::string checkDiagonal1(std::array<std::array<char, 3>, 3> gameBoard) {
    int diagonalValue1 {};
    std::string resultMsg {};

    for (int n = 0; n < 3; ++n) {
        diagonalValue1 += gameBoard[n][n];
    }
    if(diagonalValue1 == O_value)
        resultMsg = "'O' wins this one!";
    else if(diagonalValue1 == X_value)
        resultMsg = "'X' wins this one!";
    return resultMsg;
}

void printGameBoard(const std::array<std::array<char, 3>, 3> &gameBoard){
    for (int row = 0; row < 3; row++) {
        for (int column = 0; column < 3; column++) {
            std::cout << std::setw(2) << gameBoard[row][column];
        }
        std::cout << std::endl;
    }
}

void updateGameBoard(std::array<std::array<char, 3>, 3> &gameBoard, int row, int column, bool playerX) {
    if(gameBoard[row][column] == '-') {
        if (playerX)
            gameBoard[row][column] = 'X';
        else
            gameBoard[row][column] = 'O';
    }
}

std::string checkGameBoard(std::array<std::array<char, 3>, 3> gameBoard) {
    std::string resultMsg {};

//    checkRows();
    resultMsg = checkRows(gameBoard);

//    checkDiagonals();
    resultMsg = checkDiagonals(gameBoard);

    return resultMsg;
}

std::string checkRows(std::array<std::array<char, 3>, 3> gameBoard) {
    std::string resultMsg {};
    int rowValue {};

    for (int row = 0; row < 3; row++) {
        for (int column = 0; column < 3; column++) {
            rowValue += static_cast<int >(gameBoard[row][column]);
        }
        if(rowValue == O_value)
            resultMsg = "'O' wins this one!";
        else if(rowValue == X_value)
            resultMsg = "'X' wins this one!";
        else
            rowValue = 0;
    }
    return resultMsg;
}

std::string checkDiagonals(std::array<std::array<char, 3>, 3> gameBoard) {
    std::string resultMsg {};

    resultMsg = checkDiagonal1(gameBoard);
    resultMsg = checkDiagonal2(gameBoard);
    return resultMsg;
}

