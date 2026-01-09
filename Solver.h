#pragma once

int solveBoard(int board[16][16], int boardSize);

class Solver {
private:

    int board[16][16];       
    int shadowBoard[16][16]; 
    int islandCoords[64][2]; 
    int boardSize;

    int totalIslands;
    int moves;
    int attempts;
    bool guessingMode;

    void scanIslands();

public:

    Solver(int inputBoard[16][16], int size);

    int solve();

    void getBoard(int outputBoard[16][16]);

};