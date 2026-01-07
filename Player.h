#pragma once

int scanForInput(int board[16][16], int boardSize);

void moveW(int boardSize);
void moveA(int boardSize);
void moveS(int boardSize);
void moveD(int boardSize);
int getCursorX();
int getCursorY();

int getLeftDistance(int board[16][16], int boardSize, int X, int Y, int mode);
int getRightDistance(int board[16][16], int boardSize, int X, int Y, int mode);
int getUpDistance(int board[16][16], int boardSize, int X, int Y, int mode);
int getDownDistance(int board[16][16], int boardSize, int X, int Y, int mode);
void deleteBridge(int board[16][16], int boardSize, int X, int Y);
void resetCursorPos();
int getPlayerMoves();