//
// Created by Bob McDermott on 15/04/2022.
//

#ifndef TTT_UTILS_H
#define TTT_UTILS_H
#include <iostream>
#include <array>
#include <iomanip>
#include "format"

const int O_value {237}; // int('O') + int('O') + int('O')
const int X_value {264};

std::string checkDiagonals(std::array<std::array<char, 3>, 3> gameBoard);
std::string checkRows(std::array<std::array<char, 3>, 3> gameBoard);
std::string checkDiagonal2(std::array<std::array<char, 3>, 3> gameBoard);
std::string checkGameBoard(std::array<std::array<char, 3>, 3> gameBoard);
void updateGameBoard(std::array<std::array<char, 3>, 3> &gameBoard, int row, int column, bool playerX);
void printGameBoard(const std::array<std::array<char, 3>, 3> &gameBoard);

#endif //TTT_UTILS_H
