#include "Utils.h"
#include "Validator.h"

int countBridges(int board[16][16], int boardSize, int islandX, int islandY) {

	int bridgeCount = 0;

	// Richtungen für den Scout:
	int xDir[4] = { 1, -1, 0, 0 };
	int yDir[4] = { 0, 0, 1, -1 };
	// Stellt sicher das Scout im Spielfeld bleibt
	for (int i = 0; i < 4; i++)
	{
		// Start an der gewählten Insel:
		int scoutX = islandX;
		int scoutY = islandY;

		scoutX += xDir[i];
		scoutY += yDir[i];

		if (scoutX >= 0 && scoutX < boardSize && scoutY >= 0 && scoutY < boardSize) {
			switch (i) {
			case 0:
			case 1:
				if (board[scoutX][scoutY] == -1) bridgeCount++;
				else if (board[scoutX][scoutY] == -2) bridgeCount += 2;
				break;
			case 2:
			case 3:
				if (board[scoutX][scoutY] == -3) bridgeCount++;
				else if (board[scoutX][scoutY] == -4) bridgeCount += 2;
				break;
			}
		}
	}
	return bridgeCount;
}

bool checkBridges(int board[16][16], int boardSize, bool visited[16][16], int &islandCount) {

	for (int x = 0; x < boardSize; x++) {
		for (int y = 0; y < boardSize; y++) {
			if (board[x][y] > 0) {
				islandCount++;
				if (islandCount == 1) {
					floodFill(board, boardSize, visited, x, y);
				}
				if (countBridges(board, boardSize, x, y) != board[x][y])
					return false;
			}
		}
	}
	return true;
}

void floodFill(int board[16][16], int boardSize, bool visited[16][16], int x, int y) {

	visited[x][y] = true;

	// Richtungen für den Scout:
	int xDir[4] = { 1, -1, 0, 0 };
	int yDir[4] = { 0, 0, 1, -1 };

	for (int i = 0; i < 4; i++)
	{
		int scoutX = x;
		int scoutY = y;

		scoutX += xDir[i];
		scoutY += yDir[i];

		bool bridge = false;

		if (scoutX >= 0 && scoutX < boardSize && scoutY >= 0 && scoutY < boardSize) {
			switch (i) {
			case 0:
			case 1: bridge = ((board[scoutX][scoutY] == -1) || (board[scoutX][scoutY] == -2));
				break;
			case 2:
			case 3: bridge = ((board[scoutX][scoutY] == -3) || (board[scoutX][scoutY] == -4));
				break;
			}
		}

		while (bridge) {

			scoutX += xDir[i];
			scoutY += yDir[i];

			if (board[scoutX][scoutY] > 0) {
				if (!visited[scoutX][scoutY]) floodFill(board, boardSize, visited, scoutX, scoutY);
				break;
			}
		}
	}


}

bool checkWin(int board[16][16], int boardSize) {
	
	bool visited[16][16] = { false };
	int visitedCount = 0;
	int islandCount = 0;

	if (checkBridges(board, boardSize, visited, islandCount)) {
		for (int x = 0; x < boardSize; x++) {
			for (int y = 0; y < boardSize; y++) {
				if (visited[x][y]) visitedCount++;
			}
		}
		return (visitedCount == islandCount);
	}
	return false;
}
