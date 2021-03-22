// chess-task.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Figure.h"

int main() {
    Figure king(5, 4, KING, WHITE);
    //Figure rook(1, 2, ROOK, BLACK);
    Figure bishop(2, 1, BISHOP, BLACK);
    Figure whiteFigures[16] = { king };
    Figure blackFigures[16] = { bishop };

    bool attacks = bishop.attacksKing(king.getX(), king.getY());

    for (int line = 1; line <= 8; line++) {
        for (int column = 1; column <= 8; column++) {
            bool isOccupied = false;
            for (int i = 0; i < 16; i++) {
                if ((whiteFigures[i].getX() == line && whiteFigures[i].getY() == column) ||
                        blackFigures[i].getX() == line && blackFigures[i].getY() == column) {
                    isOccupied = true;
                    break;
                }
            }
            if (isOccupied) {
                std::cout << " x ";
            }
            else {
                std::cout << " - ";
            }
        }
        std::cout << "\n";
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
