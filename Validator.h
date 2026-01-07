#pragma once

int countBridges(int board[16][16], int boardSize, int islandX, int islandY);
bool checkBridges(int board[16][16], int boardSize, bool visited[16][16], int &islandCount);
void floodFill(int board[16][16], int boardSize, bool visited[16][16], int x, int y);
bool checkWin(int board[16][16], int boardSize);