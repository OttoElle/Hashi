#pragma once

void drawBridge(int board[16][16], int boardSize, int x1, int y1, int x2, int y2, bool create, bool doubleBridge, bool log);
void drawBridge(int board[16][16], int boardSize, int X, int Y);
void eraseAllBridges(int board[16][16], int boardSize);
void printBoard(int board[16][16], int boardSize, int cursorX, int cursorY);
