#include "Utils.h"
#include "Player.h"

char inputChar;
int currentCursorX = 0, currentCursorY = 0;
int moves = 0;
int typeBefore = 0;

int scanForInput(int board[16][16], int boardSize) {
	inputChar = getchar();
	switch (inputChar) {
	case 'W':
	case 'w':
		moveW(boardSize);
		break;
	case 'A':
	case 'a':
		moveA(boardSize);
		break;
	case 'S':
	case 's':
		moveS(boardSize);
		break;
	case 'D':
	case 'd':
		moveD(boardSize);
		break;
	case 'B':
	case 'b':
		// next bridge
		typeBefore = (board[currentCursorX][currentCursorY]);
		drawBridge(board, boardSize, currentCursorX, currentCursorY);
		if ((typeBefore == 0 && board[currentCursorX][currentCursorY] < 0) || (typeBefore < 0 && board[currentCursorX][currentCursorY] == 0)) moves++;
		break;
	case 'X':
	case 'x':
		// delete bridge
		deleteBridge(board, boardSize, currentCursorX, currentCursorY);
		break;
	case '#':
		return 0;
		// give up, then go to main menu
		break;
	default:
		break;

	}
	return 1;
}

void moveW(int boardSize) {
	if (currentCursorY == 0) {
		currentCursorY = boardSize - 1;
	}
	else {
		currentCursorY--;
	}
	// Hier noch in Log schreiben und dann aufrufen dass das spielfeld neu gezeichnet werden muss
}

void moveA(int boardSize) {
	if (currentCursorX == 0) {
		currentCursorX = boardSize - 1;
	}
	else {
		currentCursorX--;
	}
	// Hier noch in Log schreiben und dann aufrufen dass das spielfeld neu gezeichnet werden muss
}

void moveS(int boardSize) {
	if (currentCursorY == boardSize - 1) {
		currentCursorY = 0;
	}
	else {
		currentCursorY++;
	}
	// Hier noch in Log schreiben und dann aufrufen dass das spielfeld neu gezeichnet werden muss
}

void moveD(int boardSize) {
	if (currentCursorX == boardSize - 1) {
		currentCursorX = 0;
	}
	else {
		currentCursorX++;
	}
	// Hier noch in Log schreiben und dann aufrufen dass das spielfeld neu gezeichnet werden muss
}

int getCursorX() {
	return currentCursorX; // Übergibt aktuelle Cursor X-Koordinate als return Wert
}

int getCursorY() {
	return currentCursorY; // Übergibt aktelle Cursor Y-Koordinate als return Wert
}



int getUpDistance(int board[16][16], int boardSize, int X, int Y, int mode) {
	int ystart = Y;
	int state3 = 0;
	do {
		if (ystart >= 1 || ystart <= Y + 1) { // Nach oben prüfen wie weit es geht
			if (board[X][ystart] > 0) {
				ystart++;
				if (ystart < 1) {
					state3 = 2;
					ystart = Y;
				}
				else {
					state3 = 1;
				}
			}
			else {
				if (board[X][ystart] < 0 && board[X][ystart] >= -2 && ystart != Y) {
					state3 = 2;
				}
				else {
					state3 = 0;
					ystart--;
				}
			}
		}
		else {
			state3 = 2;
		}
	} while (state3 == 0);
	if (state3 == 2) ystart = Y;
	if (ystart > Y) {
		state3 = 2;
		ystart = Y;
	}
	if (mode == 1) return state3;
	return ystart;
}

int getDownDistance(int board[16][16], int boardSize, int X, int Y, int mode) {
	int yend = Y;
	int state4 = 0;
	do {
		if (yend >= Y - 1 || yend <= boardSize - 2) { // Nach unten prüfen wie weit es geht
			if (board[X][yend] > 0 || yend >= boardSize) {
				yend--;
				if (yend >= boardSize) {
					state4 = 2;
					yend = Y;
				}
				else {
					if (yend == boardSize - 1) {
						state4 = 2;
						yend = Y;
					}
					else {
						state4 = 1;
					}
				}
			}
			else {
				if (board[X][yend] < 0 && board[X][yend] >= -2 && yend != Y) {
					state4 = 2;
				}
				else {
					state4 = 0;
					yend++;
				}
			}
		}
		else {
			state4 = 2;
		}
	} while (state4 == 0);
	if (state4 == 2) yend = Y;
	if (yend < Y) {
		state4 = 2;
		yend = Y;
	}
	if (mode == 1) return state4;
	return yend;
}

int getLeftDistance(int board[16][16], int boardSize, int X, int Y, int mode) {
	int xstart = X;
	int state = 0;
	do {
		if (xstart >= 1 || xstart <= X + 1) { // Nach links prüfen wie weit es geht
			if (board[xstart][Y] > 0) {
				xstart++;
				if (xstart >= 1) {
					state = 1;
				}
				else {
					state = 2;
					xstart = X;
				}
			}
			else {
				if (board[xstart][Y] < -2) {
					state = 2;
				}
				else {
					state = 0;
					xstart--;
				}
			}
		}
		else {
			state = 2;
		}
	} while (state == 0);
	if (state == 2) xstart = X;
	if (mode == 1) return state;
	return xstart;
}

int getRightDistance(int board[16][16], int boardSize, int X, int Y, int mode) {
	int xend = X;
	int state2 = 0;
	do {
		if (xend >= 0 && (xend >= X - 1 || xend <= boardSize - 2)) {	// Nach rechts prüfen wie weit es geht

			if (board[xend][Y] > 0) {
				if (xend <= boardSize - 1) {
					xend--;
					state2 = 1;
					break;
				}

				else {
					xend = X;
					state2 = 2;
					break;
				}
			}
			else {
				if (board[xend][Y] < -2) {
					state2 = 2;
					break;
				}
				else {
					if (xend < boardSize - 1) {
						state2 = 0;
						xend++;
					}
					else {
						xend = X;
						state2 = 2;
						break;
					}
				}
			}
		}
		else {
			state2 = 2;
		}
	} while (state2 == 0);
	if (state2 == 2) xend = X;
	if (mode == 1) return state2;
	return xend;
}

void deleteBridge(int board[16][16], int boardSize, int X, int Y) {
	if (board[X][Y] <= 0) {
		board[X][Y] = 0;
	}
}

void resetCursorPos() {
	currentCursorX = 0;
	currentCursorY = 0;
}

int getPlayerMoves() {
	int moves2 = moves;
	moves = 0;
	return moves2;
}